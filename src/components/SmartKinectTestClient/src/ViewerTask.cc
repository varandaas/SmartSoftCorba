//--------------------------------------------------------------------------
// Code generated by the SmartSoft MDSD Toolchain Version 0.8.0
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
// If you want the toolchain to re-generate this file, please
// delete it before running the code generator.
//--------------------------------------------------------------------------

#include <mrpt/core.h>

#include "ViewerTask.hh"
#include "gen/SmartKinectTestClient.hh"

#include <CommKinectObjects/commKinectImage.hh>
#include <CommKinectObjects/commMutableKinectImage.hh>

#include <armadillo.hh>
#include <OpenCVHelpers.hh>

#include <iostream>

using namespace mrpt;
using namespace mrpt::gui;
using namespace mrpt::opengl;

ViewerTask::ViewerTask() {
}

int ViewerTask::svc() {
	// activate kinect
	COMP->stateClient->setWaitState("active");

	// create windows
	CDisplayWindow rgbImage("RGB Image");
	CDisplayWindow3D cartesianWindow("Cartesian Points", 640, 480);

	// place windows on screen
	rgbImage.setPos(0, 0);
	cartesianWindow.setPos(0, 260);

	cartesianWindow.setCameraProjective(true);
	cartesianWindow.setCameraElevationDeg(25.0f);
	cartesianWindow.setCameraAzimuthDeg(160.0f);
	cartesianWindow.setCameraPointingToPoint(4, 0, 0);
	cartesianWindow.setCameraZoom(12.0f);

	COpenGLScenePtr &theScene = cartesianWindow.get3DSceneAndLock();

	opengl::CPointCloudPtr cloud = opengl::CPointCloud::Create();
	cloud->setName("cloud");
	cloud->setColor(mrpt::utils::TColorf(1));
	cloud->setPointSize(2.0);
	theScene->insert(cloud);

	{
		// Add world coordinate system
		opengl::CSimpleLinePtr xAxis = opengl::CSimpleLine::Create();
		xAxis->setName("world_x");
		xAxis->setLineCoords(0, 0, 0, 0.3, 0, 0);
		xAxis->setLineWidth(3.0);
		xAxis->setColor(mrpt::utils::TColorf(1, 0, 0));
		theScene->insert(xAxis);

		opengl::CSimpleLinePtr yAxis = opengl::CSimpleLine::Create();
		yAxis->setName("world_y");
		yAxis->setLineCoords(0, 0, 0, 0, 0.3, 0);
		yAxis->setLineWidth(3.0);
		yAxis->setColor(mrpt::utils::TColorf(0, 1, 0));
		theScene->insert(yAxis);

		opengl::CSimpleLinePtr zAxis = opengl::CSimpleLine::Create();
		zAxis->setName("world_z");
		zAxis->setLineCoords(0, 0, 0, 0, 0, 0.3);
		zAxis->setLineWidth(3.0);
		zAxis->setColor(mrpt::utils::TColorf(0, 0, 1));
		theScene->insert(zAxis);
	}

	{
		// Add robot coordinate system
		opengl::CSimpleLinePtr xAxis = opengl::CSimpleLine::Create();
		xAxis->setName("robot_x");
		xAxis->setLineCoords(0, 0, 0, 0.2, 0, 0);
		xAxis->setLineWidth(3.0);
		xAxis->setColor(mrpt::utils::TColorf(1, 0, 0));
		theScene->insert(xAxis);

		opengl::CSimpleLinePtr yAxis = opengl::CSimpleLine::Create();
		yAxis->setName("robot_y");
		yAxis->setLineCoords(0, 0, 0, 0, 0.2, 0);
		yAxis->setLineWidth(3.0);
		yAxis->setColor(mrpt::utils::TColorf(0, 1, 0));
		theScene->insert(yAxis);

		opengl::CSimpleLinePtr zAxis = opengl::CSimpleLine::Create();
		zAxis->setName("robot_z");
		zAxis->setLineCoords(0, 0, 0, 0, 0, 0.2);
		zAxis->setLineWidth(3.0);
		zAxis->setColor(mrpt::utils::TColorf(0, 0, 1));
		theScene->insert(zAxis);
	}

	{
		// Add sensor coordinate system
		opengl::CSimpleLinePtr xAxis = opengl::CSimpleLine::Create();
		xAxis->setName("sensor_x");
		xAxis->setLineCoords(0, 0, 0, 0.1, 0, 0);
		xAxis->setLineWidth(3.0);
		xAxis->setColor(mrpt::utils::TColorf(1, 0, 0));
		theScene->insert(xAxis);

		opengl::CSimpleLinePtr yAxis = opengl::CSimpleLine::Create();
		yAxis->setName("sensor_y");
		yAxis->setLineCoords(0, 0, 0, 0, 0.1, 0);
		yAxis->setLineWidth(3.0);
		yAxis->setColor(mrpt::utils::TColorf(0, 1, 0));
		theScene->insert(yAxis);

		opengl::CSimpleLinePtr zAxis = opengl::CSimpleLine::Create();
		zAxis->setName("sensor_z");
		zAxis->setLineCoords(0, 0, 0, 0, 0, 0.1);
		zAxis->setLineWidth(3.0);
		zAxis->setColor(mrpt::utils::TColorf(0, 0, 1));
		theScene->insert(zAxis);
	}

	cartesianWindow.unlockAccess3DScene();

	// ------------------------------------------------------
	while (!mrpt::system::os::kbhit() && cartesianWindow.isOpen()) {

		CommKinectObjects::CommMutableKinectImage image;
		COMP->imagePushNewestClient->getUpdateWait(image);

		if (image.is_data_valid()) {

			std::cout << "counter: " << image.get_sequence_counter() << "\n";
			std::cout << "min_distance: " << image.get_min_distance() << "\n";
			std::cout << "max_distance: " << image.get_max_distance() << "\n";
			std::cout << "opening_angle_x_axis: " << image.get_opening_angle_x_axis() << "\n";
			std::cout << "opening_angle_y_axis: " << image.get_opening_angle_y_axis() << "\n";

			//////////////////////////////////////////
			// show rgb image
			{
				CImage dImage(image.get_width(), image.get_height());
				const uint8_t* imageData = image.get_rgb_image();
				for (uint32_t i = 0; i < image.get_height(); i++) {
					for (uint32_t j = 0; j < image.get_width(); j++) {

						const uint8_t* pixel = (imageData + i * 3* image .get_width() + j * 3);

						uint8_t r = pixel[0];
						uint8_t g = pixel[1];
						uint8_t b = pixel[2];

						TColor color(r, g, b);
						dImage.setPixel(j, i, color);
					}
				}
				rgbImage.showImage(dImage);
			}
			//////////////////////////////////////////

			COpenGLScenePtr & theScene = cartesianWindow.get3DSceneAndLock();
			//////////////////////////////////////////
			// show coordinates
			{
				cloud->clear();
				double x, y, z;

				for (uint32_t i = 0; i < image.get_width(); i++) {
					for (uint32_t j = 0; j < image.get_height(); j++) {
						image.get_cartesian_point_world(i, j, x, y, z, 1);
						cloud->insertPoint(x, y, z);
					}
				}
			}
			//////////////////////////////////////////


			//////////////////////////////////////////
			// show robot coordinate system
			{
				arma::mat pose_robot =
						image.get_base_state().get_base_position().get_base_pose3d().getHomogeneousMatrix(1);

				arma::vec origin(4);
				origin.zeros();
				origin[3] = 1;

				arma::vec x(4);
				x = origin;
				x[0] = 0.2;
				x = pose_robot * x;

				arma::vec y(4);
				y = origin;
				y[1] = 0.2;
				y = pose_robot * y;

				arma::vec z(4);
				z = origin;
				z[2] = 0.2;
				z = pose_robot * z;

				origin = pose_robot * origin;

				opengl::CSimpleLinePtr xAxis = (opengl::CSimpleLinePtr) theScene->getByName("robot_x");
				xAxis->setLineCoords(origin[0], origin[1], origin[2], x[0], x[1], x[2]);

				opengl::CSimpleLinePtr yAxis = (opengl::CSimpleLinePtr) theScene->getByName("robot_y");
				yAxis->setLineCoords(origin[0], origin[1], origin[2], y[0], y[1], y[2]);

				opengl::CSimpleLinePtr zAxis = (opengl::CSimpleLinePtr) theScene->getByName("robot_z");
				zAxis->setLineCoords(origin[0], origin[1], origin[2], z[0], z[1], z[2]);
			}
			//////////////////////////////////////////


			//////////////////////////////////////////
			// show sensor coordinate system
			{
				arma::mat pose = image.get_sensor_pose().getHomogeneousMatrix(1);
				arma::mat pose_robot =
						image.get_base_state().get_base_position().get_base_pose3d().getHomogeneousMatrix(1);

				arma::vec origin(4);
				origin.zeros();
				origin[3] = 1;

				arma::vec x(4);
				x = origin;
				x[0] = 0.1;
				x = pose_robot * pose * x;

				arma::vec y(4);
				y = origin;
				y[1] = 0.1;
				y = pose_robot * pose * y;

				arma::vec z(4);
				z = origin;
				z[2] = 0.1;
				z = pose_robot * pose * z;

				origin = pose_robot * pose * origin;

				opengl::CSimpleLinePtr xAxis = (opengl::CSimpleLinePtr) theScene->getByName("sensor_x");
				xAxis->setLineCoords(origin[0], origin[1], origin[2], x[0], x[1], x[2]);

				opengl::CSimpleLinePtr yAxis = (opengl::CSimpleLinePtr) theScene->getByName("sensor_y");
				yAxis->setLineCoords(origin[0], origin[1], origin[2], y[0], y[1], y[2]);

				opengl::CSimpleLinePtr zAxis = (opengl::CSimpleLinePtr) theScene->getByName("sensor_z");
				zAxis->setLineCoords(origin[0], origin[1], origin[2], z[0], z[1], z[2]);
			}
			//////////////////////////////////////////
			cartesianWindow.unlockAccess3DScene();
			cartesianWindow.forceRepaint();

		} else {
			std::cout << "data invalid\n";
		}

	}

	return 0;
}
