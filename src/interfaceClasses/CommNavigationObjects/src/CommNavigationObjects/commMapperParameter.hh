//--------------------------------------------------------------------------
// Code generated by the SmartSoft MDSD Toolchain Version 0.10.0
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

// --------------------------------------------------------------------------
//
//  Copyright (C) 2008 Christian Schlegel, Andreas Steck
//
//        schlegel@hs-ulm.de
//        steck@hs-ulm.de
//
//        ZAFH Servicerobotik Ulm
//        University of Applied Sciences
//        Prittwitzstr. 10
//        D-89075 Ulm
//        Germany
//
//  This file is part of the "SmartSoft Communication Classes".
//  It provides basic standardized data types for communication between
//  different components in the mobile robotics context. These classes
//  are designed to be used in conjunction with the SmartSoft Communication
//  Library.
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
//
// --------------------------------------------------------------------------


#ifndef _COMM_COMMNAVIGATIONOBJECTS_COMMMAPPERPARAMETER_HH
#define _COMM_COMMNAVIGATIONOBJECTS_COMMMAPPERPARAMETER_HH

#include <string>
#include <iostream>

// include files of classes

// include header-files of included communication objects

// include enums
#include <CommNavigationObjects/gen/enumMapperTagType.hh>

// include client-side file generated by IDL compiler
#include "CommNavigationObjects/gen/smartCommMapperParameterC.hh"

#ifndef LISP_SEPARATOR
#define LISP_SEPARATOR " ()\"\n"
#define LISP_STRING    1000
#endif


namespace CommNavigationObjects
{

class CommMapperParameter
{
protected:
	CommNavigationObjectsIDL::CommMapperParameter idl_CommMapperParameter;

public:
	CommMapperParameter()
	{
		//idl_CommMapperParameter.tag = 0;
		idl_CommMapperParameter.parameter1 = 0;
		idl_CommMapperParameter.parameter2 = 0;
		idl_CommMapperParameter.parameter3 = 0;
		idl_CommMapperParameter.parameter4 = 0;
		idl_CommMapperParameter.parameter5 = 0;
	}

	CommMapperParameter(
			const CommNavigationObjectsIDL::CommMapperParameter &obj) :
		idl_CommMapperParameter(obj)
	{
	}

	virtual ~CommMapperParameter()
	{
	}

	void get(CORBA::Any &a) const;
	void set(const CORBA::Any &a);

	inline const CommNavigationObjectsIDL::CommMapperParameter &get() const
	{
		return idl_CommMapperParameter;
	}

	inline void set(const CommNavigationObjectsIDL::CommMapperParameter &obj)
	{
		idl_CommMapperParameter = obj;
	}

	static inline std::string identifier(void)
	{
		return "CommNavigationObjects::CommMapperParameter";
	}

	//
	// user interfaces

	inline void get(MapperTagType &tag,int &value1,int &value2,int &value3,int &value4,int &value5,std::string &value6) const
	{
		tag = idl_CommMapperParameter.tag;
		value1 = idl_CommMapperParameter.parameter1;
		value2 = idl_CommMapperParameter.parameter2;
		value3 = idl_CommMapperParameter.parameter3;
		value4 = idl_CommMapperParameter.parameter4;
		value5 = idl_CommMapperParameter.parameter5;
		value6 = idl_CommMapperParameter.parameter6;
	}

	inline int set(std::string& inString){

		// ----------------------------------------------------
		  //
		  // handle tag to mapper
		  //
		  // input
		  //   CURPARAMETER ?xsize ?ysize ?xpos ?ypos ?id
		  //   CURLTM DISABLE/ENABLE ?threshold
		  //   CUREMPTY ACCUMULATE/EMPTY
		  //   CURSAVE ?number
		  //   CURLOAD ?number
		  //   CURLOADLTM
		  //   CURSAVEXPM ?number
		  //   LTMPARAMETER ?xsize ?ysize ?xpos ?ypos ?id
		  //   LTMINITIALIZE ?init
		  //   LTMSAVE ?number
		  //   LTMLOAD ?number
		  //   LTMSAVEXPM ?number
		  //   LTMSAVEYAMLPGM ?number
		  //   LTMSAVEYAMLPPM ?number
		  //   LTMLOADYAML ?number
		  // output
		  //   0  everything ok
		  //  -1  format error occured
		  // ----------------------------------------------------

		  char *param = (char *)NULL;
		  char *parse = (char *)NULL;
		  char *input = (char *)NULL;

		  int  error;
		  int  i;

		  input = (char *)inString.c_str();
		  error = 0;

		  do
		  {
		    param = strsep(&input,LISP_SEPARATOR);
		  } while ((param != NULL) && (strlen(param)==0));


		  if (strcasecmp(param,"CURPARAMETER")==0)
		  {
		    // --------------------
		    // set parameter of current map
		    // --------------------
		    parse = (char *)calloc(LISP_STRING,sizeof(char));

		    idl_CommMapperParameter.tag = CommNavigationObjectsIDL::LITERAL_MAPPER_CUR_PARAMETER;
		    for (i=0; i<5; i++)
		    {
		      do
		      {
		        param = strsep(&input,LISP_SEPARATOR);
		      } while ((param != NULL) && (strlen(param)==0));
		      parse = strcat(parse,param);
		      parse = strcat(parse," ");
		    }
		    if (sscanf(parse,"%d %d %d %d %d",&idl_CommMapperParameter.parameter1,
		                                      &idl_CommMapperParameter.parameter2,
		                                      &idl_CommMapperParameter.parameter3,
		                                      &idl_CommMapperParameter.parameter4,
		                                      &idl_CommMapperParameter.parameter5)==5)
		    {
		      error = 0;
		    }
		    else
		    {
		      error = -1;
		    }
		    free(parse);
		  }
		  else if (strcasecmp(param,"CURLTM")==0)
		  {
		    // --------------------
		    // set preoccupation of current map
		    // --------------------
			  idl_CommMapperParameter.tag = CommNavigationObjectsIDL::LITERAL_MAPPER_CUR_LTM;

		    //
		    // get the first parameter
		    //

		    if (error == 0)
		    {
		      do
		      {
		        param = strsep(&input,LISP_SEPARATOR);
		      } while ((param != NULL) && (strlen(param)==0));

		      if (strcasecmp("DISABLE",param)==0)
		      {
		    	  idl_CommMapperParameter.parameter1 = 0;
		      }
		      else if(strcasecmp("ENABLE",param)==0)
		      {
		    	  idl_CommMapperParameter.parameter1 = 1;
		      }
		      else
		      {
		        error = -1;
		      }
		    }

		    //
		    // get the second parameter if available
		    //

		    if ((error == 0) && (idl_CommMapperParameter.parameter1 == 1))
		    {
		      do
		      {
		        param = strsep(&input,LISP_SEPARATOR);
		      } while ((param != NULL) && (strlen(param)==0));

		      if ((param != NULL) && (sscanf(param,"%d",&idl_CommMapperParameter.parameter2)==1))
		      {
		        // everything ok
		      }
		      else
		      {
		        error = -1;
		      }
		    }

		  }
		  else if (strcasecmp(param,"CUREMPTY")==0)
		  {
		    // --------------------
		    // set current map mode
		    // --------------------
			idl_CommMapperParameter.tag = CommNavigationObjectsIDL::LITERAL_MAPPER_CUR_EMPTY;

		    if (error == 0)
		    {
		      do
		      {
		        param = strsep(&input,LISP_SEPARATOR);
		      } while ((param != NULL) && (strlen(param)==0));

		      if (strcasecmp("ACCUMULATE",param)==0)
		      {
		    	  idl_CommMapperParameter.parameter1 = 0;
		      }
		      else if(strcasecmp("EMPTY",param)==0)
		      {
		    	  idl_CommMapperParameter.parameter1 = 1;
		      }
		      else
		      {
		        error = -1;
		      }
		    }

		  }
		  else if (strcasecmp(param,"CURSAVE")==0)
		  {
		    // --------------------
		    // save current map as xml
		    // --------------------
			idl_CommMapperParameter.tag = CommNavigationObjectsIDL::LITERAL_MAPPER_CUR_SAVE;

		    if (error == 0)
		    {
		      do
		      {
		        param = strsep(&input,LISP_SEPARATOR);
		      } while ((param != NULL) && (strlen(param)==0));

		      char* tmp = (char*)NULL;
		      tmp = (char *)calloc(LISP_STRING,sizeof(char));

		      if ((param != NULL) && (sscanf(param,"%s",tmp)==1))
		      {
		        // everything ok
		        error = 0;
		        std::string str(tmp);

		        idl_CommMapperParameter.parameter6 = str.c_str();
		      }
		      else
		      {
		        error = -1;
		      }
		    }

		  }
		  else if (strcasecmp(param,"CURLOAD")==0)
		  {
		    // --------------------
		    // load current map from xml
		    // --------------------
			idl_CommMapperParameter.tag = CommNavigationObjectsIDL::LITERAL_MAPPER_CUR_LOAD;

		    if (error == 0)
		    {
		      do
		      {
		        param = strsep(&input,LISP_SEPARATOR);
		      } while ((param != NULL) && (strlen(param)==0));

		      char* tmp = (char*)NULL;
		      tmp = (char *)calloc(LISP_STRING,sizeof(char));

		      if ((param != NULL) && (sscanf(param,"%s",tmp)==1))
		      {
		        // everything ok
		        error = 0;
		        std::string str(tmp);

		        idl_CommMapperParameter.parameter6 = str.c_str();
		      }
		      else
		      {
		        error = -1;
		      }
		    }

		  }
		  else if (strcasecmp(param,"CURLOADLTM")==0)
		  {
		    // --------------------
		    // load current map from longterm map
		    // --------------------
			idl_CommMapperParameter.tag = CommNavigationObjectsIDL::LITERAL_MAPPER_CUR_LOAD_LTM;

		  }
		  else if (strcasecmp(param,"CURSAVEXPM")==0)
		  {
		    // --------------------
		    // save current map as xpm
		    // --------------------
			  idl_CommMapperParameter.tag = CommNavigationObjectsIDL::LITERAL_MAPPER_CUR_SAVE_XPM;

		    if (error == 0)
		    {
		      do
		      {
		        param = strsep(&input,LISP_SEPARATOR);
		      } while ((param != NULL) && (strlen(param)==0));

		      char* tmp = (char*)NULL;
		      tmp = (char *)calloc(LISP_STRING,sizeof(char));

		      if ((param != NULL) && (sscanf(param,"%s",tmp)==1))
		      {
		        // everything ok
		        error = 0;
		        std::string str(tmp);

		        idl_CommMapperParameter.parameter6 = str.c_str();
		      }
		      else
		      {
		        error = -1;
		      }
		    }

		  }
		  else if (strcasecmp(param,"LTMPARAMETER")==0)
		  {
		    // --------------------
		    // set parameter of longterm map
		    // --------------------
		    parse = (char *)calloc(LISP_STRING,sizeof(char));
		    idl_CommMapperParameter.tag = CommNavigationObjectsIDL::LITERAL_MAPPER_LTM_PARAMETER;

		    if (error == 0)
		    {
		      for (i=0; i<5; i++)
		      {
		        do
		        {
		          param = strsep(&input,LISP_SEPARATOR);
		        } while ((param != NULL) && (strlen(param)==0));
		        parse = strcat(parse,param);
		        parse = strcat(parse," ");
		      }
		      if (sscanf(parse,"%d %d %d %d %d",&idl_CommMapperParameter.parameter1,
		                                        &idl_CommMapperParameter.parameter2,
		                                        &idl_CommMapperParameter.parameter3,
		                                        &idl_CommMapperParameter.parameter4,
		                                        &idl_CommMapperParameter.parameter5)==5)
		      {
		      }
		      else
		      {
		        error = -1;
		      }
		    }
		    free(parse);

		  }
		  else if (strcasecmp(param,"LTMINITIALIZE")==0)
		  {
		    // --------------------
		    // clears the map and initializes to value
		    // --------------------
			idl_CommMapperParameter.tag = CommNavigationObjectsIDL::LITERAL_MAPPER_LTM_INITIALIZE;

		    if (error == 0)
		    {
		      do
		      {
		        param = strsep(&input,LISP_SEPARATOR);
		      } while ((param != NULL) && (strlen(param)==0));

		      if ((param != NULL) && (sscanf(param,"%d",&idl_CommMapperParameter.parameter1)==1))
		      {
		        // everything ok
		      }
		      else
		      {
		        error = -1;
		      }
		    }

		  }
		  else if (strcasecmp(param,"LTMSAVE")==0)
		  {
		    // --------------------
		    // save longterm map as xml
		    // --------------------
			idl_CommMapperParameter.tag = CommNavigationObjectsIDL::LITERAL_MAPPER_LTM_SAVE;

		    if (error == 0)
		    {
		      do
		      {
		        param = strsep(&input,LISP_SEPARATOR);
		      } while ((param != NULL) && (strlen(param)==0));

		      char* tmp = (char*)NULL;
		      tmp = (char *)calloc(LISP_STRING,sizeof(char));

		      if ((param != NULL) && (sscanf(param,"%s",tmp)==1))
		      {
		        // everything ok
		        error = 0;
		        std::string str(tmp);

		        idl_CommMapperParameter.parameter6 = str.c_str();
		      }
		      else
		      {
		        error = -1;
		      }
		    }

		  }
		  else if (strcasecmp(param,"LTMLOAD")==0)
		  {
		    // --------------------
		    // load longterm map from xml
		    // --------------------
			idl_CommMapperParameter.tag = CommNavigationObjectsIDL::LITERAL_MAPPER_LTM_LOAD;

		    if (error == 0)
		    {
		      do
		      {
		        param = strsep(&input,LISP_SEPARATOR);
		      } while ((param != NULL) && (strlen(param)==0));

		      char* tmp = (char*)NULL;
		      tmp = (char *)calloc(LISP_STRING,sizeof(char));

		      if ((param != NULL) && (sscanf(param,"%s",tmp)==1))
		      {
		        // everything ok
		        error = 0;
		        std::string str(tmp);

		        idl_CommMapperParameter.parameter6 = str.c_str();
		      }
		      else
		      {
		        error = -1;
		      }
		    }

		  }
		  else if (strcasecmp(param,"LTMSAVEXPM")==0)
		  {
		    // --------------------
		    // save longterm map as xpm
		    // --------------------
			idl_CommMapperParameter.tag = CommNavigationObjectsIDL::LITERAL_MAPPER_LTM_SAVE_XPM;

		    if (error == 0)
		    {
		      do
		      {
		        param = strsep(&input,LISP_SEPARATOR);
		      } while ((param != NULL) && (strlen(param)==0));

		      char* tmp = (char*)NULL;
		      tmp = (char *)calloc(LISP_STRING,sizeof(char));

		      if ((param != NULL) && (sscanf(param,"%s",tmp)==1))
		      {
		        // everything ok
		        error = 0;
		        std::string str(tmp);

		        idl_CommMapperParameter.parameter6 = str.c_str();
		      }
		      else
		      {
		        error = -1;
		      }
		    }

		  }
		  else if (strcasecmp(param,"LTMSAVEYAMLPGM")==0)
		  {
		    // --------------------
		    // save longterm map as PGM
		    // --------------------
			idl_CommMapperParameter.tag = CommNavigationObjectsIDL::LITERAL_MAPPER_LTM_SAVE_YAML_PGM;

		    if (error == 0)
		    {
		      do
		      {
		        param = strsep(&input,LISP_SEPARATOR);
		      } while ((param != NULL) && (strlen(param)==0));

		      char* tmp = (char*)NULL;
		      tmp = (char *)calloc(LISP_STRING,sizeof(char));

		      if ((param != NULL) && (sscanf(param,"%s",tmp)==1))
		      {
		        // everything ok
		        error = 0;
		        std::string str(tmp);

		        idl_CommMapperParameter.parameter6 = str.c_str();
		      }
		      else
		      {
		        error = -1;
		      }
		    }

		  }
		  else if (strcasecmp(param,"LTMSAVEYAMLPPM")==0)
		  {
		    // --------------------
		    // save longterm map as PPM
		    // --------------------
			idl_CommMapperParameter.tag = CommNavigationObjectsIDL::LITERAL_MAPPER_LTM_SAVE_YAML_PPM;

		    if (error == 0)
		    {
		      do
		      {
		        param = strsep(&input,LISP_SEPARATOR);
		      } while ((param != NULL) && (strlen(param)==0));

		      char* tmp = (char*)NULL;
		      tmp = (char *)calloc(LISP_STRING,sizeof(char));

		      if ((param != NULL) && (sscanf(param,"%s",tmp)==1))
		      {
		        // everything ok
		        error = 0;
		        std::string str(tmp);

		        idl_CommMapperParameter.parameter6 = str.c_str();
		      }
		      else
		      {
		        error = -1;
		      }
		    }

		  }
		  else if (strcasecmp(param,"LTMLOADYAML")==0)
		  {
		    // --------------------
		    // load longterm map from YAML
		    // --------------------
			idl_CommMapperParameter.tag = CommNavigationObjectsIDL::LITERAL_MAPPER_LTM_LOAD_YAML;

		    if (error == 0)
		    {
		      do
		      {
		        param = strsep(&input,LISP_SEPARATOR);
		      } while ((param != NULL) && (strlen(param)==0));

		      char* tmp = (char*)NULL;
		      tmp = (char *)calloc(LISP_STRING,sizeof(char));

		      if ((param != NULL) && (sscanf(param,"%s",tmp)==1))
		      {
		        // everything ok
		        error = 0;
		        std::string str(tmp);

		        idl_CommMapperParameter.parameter6 = str.c_str();
		      }
		      else
		      {
		        error = -1;
		      }
		    }

		  }
		  else
		  {
		    // --------------------
		    // got garbage
		    // --------------------
		    error = -1;
		  }

		  return error;


	}

};

}
#endif
