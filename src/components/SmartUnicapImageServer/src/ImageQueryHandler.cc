//--------------------------------------------------------------------------
// Code generated by the SmartSoft MDSD Toolchain Version 0.6.0
// The SmartSoft Toolchain has been developed by:
//
// ZAFH Servicerobotic Ulm
// Christian Schlegel (schlegel@hs-ulm.de)
// University of Applied Sciences
// Prittwitzstr. 10
// 89075 Ulm (Germany)
//
// Information about the SmartSoft MDSD Toolchain is available at:
// smart-robotics.sourceforge.net
//
// This file is generated once. Modify this file to your needs.
// If you want the workflow to re-generate this file, please
// delete it before running the workflow.
//--------------------------------------------------------------------------
//
//  Copyright (C) 2010 Jonas Brich
//
//        brich@mail.hs-ulm.de
//
//        Christian Schlegel (schlegel@hs-ulm.de)
//        University of Applied Sciences
//        Prittwitzstr. 10
//        89075 Ulm (Germany)
//
//  This file is part of the "Unicap Video Server component".
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//--------------------------------------------------------------------------

#include "ImageQueryHandler.hh"
#include "gen/SmartUnicapImageServer.hh"
#include "Unicap.hh"

#include <iostream>

void ImageQueryHandler::handleQuery(CHS::QueryServer<CommBasicObjects::CommVoid, CommVisionObjects::CommVideoImage> & server,
		const CHS::QueryId id, const CommBasicObjects::CommVoid & request) throw () {

	CHS::StatusCode status;
	CommVisionObjects::CommVideoImage image;
	image.set_data_invalid();
	CommVisionObjects::FormatType format;

	if (COMP->ini.component.debug_info) {
		std::cout<<"Query Request received.."<<std::endl;
	}

	// Component Active then get new image
	status = COMP->stateServer->tryAcquire("nonneutral");
	if(status == CHS::SMART_OK)
	{
			CommVisionObjects::CommVideoImage::string2format(COMP->ini.image.smart_format,format);
			image.set_parameters(COMP->ini.hardware_properties.width,COMP->ini.hardware_properties.height,format);

		// If Newest and Timed active get image from global Reference otherwise get it directly from Unicap
		if (COMP->stateServer->tryAcquire("pushimage")==CHS::SMART_OK)
		{
			if (COMP->ini.component.debug_info) {
							std::cout << "Push image mode"<<std::endl;
			}

			COMP->NewestImageMutex.acquire();
				CommVisionObjects::CommVideoImage* newestImage = COMP->newestImage;
				if (newestImage != NULL) {
					image.set_data(newestImage->get_data());
					image.set_sequence_counter((unsigned long int) newestImage->get_sequence_counter());
					image.set_sensor_pose(newestImage->get_sensor_pose());
					image.set_base_state(newestImage->get_base_state());
				}
			COMP->NewestImageMutex.release();

			COMP->stateServer->release("pushimage");
		}
		else
		{

			if (COMP->ini.component.debug_info) {
					std::cout << "Query only mode"<<std::endl;
			}

			CommBasicObjects::CommBasePosition default_base_position;
			default_base_position.set_x(COMP->ini.base.x);
			default_base_position.set_y(COMP->ini.base.y);
			default_base_position.set_z(COMP->ini.base.z);
			default_base_position.set_base_alpha(COMP->ini.base.base_a);
			default_base_position.set_steer_alpha(COMP->ini.base.steer_a);
			default_base_position.set_turret_alpha(COMP->ini.base.turret_a);

			CommBasicObjects::CommBaseVelocity zero_velocity;
			zero_velocity.set_v(0);
			zero_velocity.set_omega_base(0);
			zero_velocity.set_omega_steer(0);
			zero_velocity.set_omega_turret(0);


			try {
				UNICAPINZ->getImage(image);
			} catch (Unicap::UnicapException& e) {
				std::cerr << "Error: " << e.what() << " [QueryHandler].\n";
				image.set_data_invalid();
			} catch (...) {
				std::cerr << "Error: Undefined Error. [QueryHandler]\n";
				image.set_data_invalid();
			}

			arma::mat sensorMat;
			EulerTransformationMatrices::create_zyx_matrix(COMP->ini.sensor_pose.x, COMP->ini.sensor_pose.y,
					COMP->ini.sensor_pose.z, COMP->ini.sensor_pose.azimuth, COMP->ini.sensor_pose.elevation,
					COMP->ini.sensor_pose.roll, sensorMat);


			// set base state
			CommBasicObjects::CommBaseState base_state;
			if (COMP->ini.base.on_ptu) {
				CommBasicObjects::CommDevicePoseState devicePoseState;
				CHS::StatusCode status = COMP->ptuPushTimedClient->getUpdate(devicePoseState);

				base_state = devicePoseState.get_base_state();
				CommBasicObjects::CommPose3d ptuPose = devicePoseState.get_device_pose3d_robot();
				arma::mat ptuMat = ptuPose.getHomogeneousMatrix();

				sensorMat = ptuMat * sensorMat;

				if (status != CHS::SMART_OK) {
					std::cerr << "WARNING: failed to get current ptu device state (" << CHS::StatusCodeConversion(status)
					<< "), pushing invalid image" << std::endl;
					image.set_data_invalid();
				}

			}
			// read base state from base server
			else if (COMP->ini.base.on_base) {
				CHS::StatusCode status = COMP->basePushTimedClient->getUpdate(base_state);

				if (status != CHS::SMART_OK) {
					std::cerr << "WARNING: failed to get current base state (" << CHS::StatusCodeConversion(status)
					<< "), pushing invalid image" << std::endl;
					image.set_data_invalid();
				}
			}
			// default base state
			else {
				base_state.set_time_stamp(CommBasicObjects::CommTimeStamp::now());
				base_state.set_base_position(default_base_position);
				base_state.set_base_velocity(zero_velocity);
			}

			CommBasicObjects::CommPose3d sensorPose(sensorMat);
			image.set_sensor_pose(sensorPose);
			image.set_base_state(base_state);


		}

		COMP->stateServer->release("nonneutral");
	}
	else
	{
		image.set_data_invalid();
		if (COMP->ini.component.debug_info) {
			    std::cout << "Query: StatusCode: "<<CHS::StatusCodeConversion(status)<<std::endl;
				std::cout << "Query: Set Data invalid!"<< std::endl;

		}

	}

	server.answer(id, image);
	if (COMP->ini.component.debug_info) {
		std::cout << "Query: Answer sent: "<<image.is_data_valid()<<" with ID: " << id << std::endl;
	}

}
