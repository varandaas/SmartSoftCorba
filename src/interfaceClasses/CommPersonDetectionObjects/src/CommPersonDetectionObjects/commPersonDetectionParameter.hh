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
//------------------------------------------------------------------------
//
//  Copyright (C) 2011 Manuel Wopfner
//
//        wopfner@hs-ulm.de
//
//        Christian Schlegel (schlegel@hs-ulm.de)
//        University of Applied Sciences
//        Prittwitzstr. 10
//        89075 Ulm (Germany)
//
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

#ifndef _COMM_COMMPERSONDETECTIONOBJECTS_COMMPERSONDETECTIONPARAMETER_HH
#define _COMM_COMMPERSONDETECTIONOBJECTS_COMMPERSONDETECTIONPARAMETER_HH

#include <string>

// include files of classes

// include header-files of included communication objects

// include enums
#include <CommPersonDetectionObjects/gen/enumPersonManagerParam.hh>
#include <CommPersonDetectionObjects/gen/enumScanType.hh>
#include <CommPersonDetectionObjects/gen/enumScanMode.hh>
#include <CommPersonDetectionObjects/gen/enumScanParam.hh>

// include client-side file generated by IDL compiler
#include "CommPersonDetectionObjects/gen/smartCommPersonDetectionParameterC.hh"

#ifndef LISP_SEPARATOR
#define LISP_SEPARATOR " ()\"\n"
#define LISP_STRING    1000
#endif

namespace CommPersonDetectionObjects
{

class CommPersonDetectionParameter
{
protected:
	CommPersonDetectionObjectsIDL::CommPersonDetectionParameter idl_CommPersonDetectionParameter;

public:
	CommPersonDetectionParameter()
	{
		idl_CommPersonDetectionParameter.scan_mode = CommPersonDetectionObjectsIDL::LITERAL_NONE_SCAN_MODE;
		idl_CommPersonDetectionParameter.scan_type = CommPersonDetectionObjectsIDL::LITERAL_NONE_SCAN_TYPE;
		idl_CommPersonDetectionParameter.manager_param = CommPersonDetectionObjectsIDL::LITERAL_NONE_MANAGER_PARAM;
	}

	CommPersonDetectionParameter(const CommPersonDetectionObjectsIDL::CommPersonDetectionParameter &obj) :
		idl_CommPersonDetectionParameter(obj)
	{
	}

	operator CommPersonDetectionObjectsIDL::CommPersonDetectionParameter() const
	{
		return idl_CommPersonDetectionParameter;
	}

	virtual ~CommPersonDetectionParameter()
	{
	}

	void get(CORBA::Any &a) const;
	void set(const CORBA::Any &a);

	static inline std::string identifier(void)
	{
		return "CommPersonDetectionObjects::CommPersonDetectionParameter";
	}

	//
	// user interfaces
	inline int set(std::string& inString)
	{
		// ----------------------------------------------------
		//
		// input
		//   MODE ONESHOT/CONTINUOUS
		//   TYPE SINGLESCAN/FULLSCAN
		//   PMANAGER RESET/ACTIVATE/DEACTIVATE
		// 	 FULLSCAN (tilt, minMaxPan)
		// ----------------------------------------------------

		char *param = (char *) NULL;
		char *parse = (char *) NULL;
		char *input = (char *) NULL;
		int error;

		input = (char *) inString.c_str();
		error = 0;

		do
		{
			param = strsep(&input, LISP_SEPARATOR);
		} while ((param != NULL) && (strlen(param) == 0));

		if (strcasecmp(param, "MODE") == 0)
		{
			//
			// get the first parameter
			//
			if (error == 0)
			{
				do
				{
					param = strsep(&input, LISP_SEPARATOR);
				} while ((param != NULL) && (strlen(param) == 0));

				if (strcasecmp("ONESHOT", param) == 0)
				{
					idl_CommPersonDetectionParameter.scan_mode = CommPersonDetectionObjectsIDL::LITERAL_ONE_SHOT;
				} else if (strcasecmp("CONTINUOUS", param) == 0)
				{
					idl_CommPersonDetectionParameter.scan_mode = CommPersonDetectionObjectsIDL::LITERAL_CONTINUOUS;
				} else
				{
					error = -1;
				}
			}
		} else if (strcasecmp(param, "TYPE") == 0)
		{
			//
			// get the first parameter
			//
			if (error == 0)
			{
				do
				{
					param = strsep(&input, LISP_SEPARATOR);
				} while ((param != NULL) && (strlen(param) == 0));

				if (strcasecmp("SINGLESCAN", param) == 0)
				{
					idl_CommPersonDetectionParameter.scan_type = CommPersonDetectionObjectsIDL::LITERAL_SINGLE_SCAN;
				} else if (strcasecmp("FULLSCAN", param) == 0)
				{
					idl_CommPersonDetectionParameter.scan_type = CommPersonDetectionObjectsIDL::LITERAL_FULL_SCAN;
				} else
				{
					error = -1;
				}
			}
		} else if (strcasecmp(param, "PMANAGER") == 0)
		{
			//
			// get the first parameter
			//
			if (error == 0)
			{
				do
				{
					param = strsep(&input, LISP_SEPARATOR);
				} while ((param != NULL) && (strlen(param) == 0));

				if (strcasecmp("RESET", param) == 0)
				{
					idl_CommPersonDetectionParameter.manager_param = CommPersonDetectionObjectsIDL::LITERAL_RESET_MANAGER;
				} else if (strcasecmp("ACTIVATE", param) == 0)
				{
					idl_CommPersonDetectionParameter.manager_param = CommPersonDetectionObjectsIDL::LITERAL_ACTIVATE_MANAGER;
				} else if (strcasecmp("DEACTIVATE", param) == 0)
				{
					idl_CommPersonDetectionParameter.manager_param = CommPersonDetectionObjectsIDL::LITERAL_DEACTIVATE_MANAGER;
				} else
				{
					error = -1;
				}
			}

		} else if (strcasecmp(param, "FULLSCAN") == 0)
		{
			idl_CommPersonDetectionParameter.scan_param = CommPersonDetectionObjectsIDL::LITERAL_FULL_SCAN_PARAM;

			parse = (char *) calloc(LISP_STRING, sizeof(char));

			for (int i = 0; i < 2; i++)
			{
				do
				{
					param = strsep(&input, LISP_SEPARATOR);
				} while ((param != NULL) && (strlen(param) == 0));
				parse = strcat(parse, param);
				parse = strcat(parse, " ");
			}
			if (sscanf(parse, "%lf %lf", &idl_CommPersonDetectionParameter.p1, &idl_CommPersonDetectionParameter.p2) == 2)
			{
				error = 0;
			} else
			{
				error = -1;
			}
			free(parse);

		} else
		{
			// --------------------
			// got garbage
			// --------------------
			error = -1;
		}

		return error;
	}

	void setScanType(ScanType type)
	{
		idl_CommPersonDetectionParameter.scan_type = type.get_value_idl();
	}

	ScanType getScanType() const
	{
		return idl_CommPersonDetectionParameter.scan_type;
	}

	void setScanMode(ScanMode mode)
	{
		idl_CommPersonDetectionParameter.scan_mode = mode.get_value_idl();
	}

	ScanMode getScanMode() const
	{
		return idl_CommPersonDetectionParameter.scan_mode;
	}

	void setPersonManagerParam(PersonManagerParam param)
	{
		idl_CommPersonDetectionParameter.manager_param = param.get_value_idl();
	}

	PersonManagerParam getPersonManagerParam() const
	{
		return idl_CommPersonDetectionParameter.manager_param;
	}

	ScanParam getScanParam() const
	{
		return idl_CommPersonDetectionParameter.scan_param;
	}

	void getParams(double& p1, double& p2) const
	{
		p1 = idl_CommPersonDetectionParameter.p1;
		p2 = idl_CommPersonDetectionParameter.p2;
	}

};

}
#endif