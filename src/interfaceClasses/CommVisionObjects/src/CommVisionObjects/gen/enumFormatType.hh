//--------------------------------------------------------------------------
// Code generated by the SmartSoft MDSD Toolchain Version 0.10.3
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
// Please do not modify this file. It will be re-generated
// running the code generator.
//--------------------------------------------------------------------------

#ifndef _COMMVISIONOBJECTS_ENUM_HH_FORMATTYPE
#define _COMMVISIONOBJECTS_ENUM_HH_FORMATTYPE

#include <CommVisionObjects/gen/enumFormatTypeC.hh>
#include <string>
#include <ostream>

namespace CommVisionObjects
{

class FormatType
{
public:
	enum literal
	{

		GREY = CommVisionObjectsIDL::LITERAL_GREY,

		RGB24 = CommVisionObjectsIDL::LITERAL_RGB24,

		RGB32 = CommVisionObjectsIDL::LITERAL_RGB32,

		RGB555 = CommVisionObjectsIDL::LITERAL_RGB555,

		RGB565 = CommVisionObjectsIDL::LITERAL_RGB565,

		UYVY = CommVisionObjectsIDL::LITERAL_UYVY,

		YUV411P = CommVisionObjectsIDL::LITERAL_YUV411P,

		YUV420P = CommVisionObjectsIDL::LITERAL_YUV420P,

		YUV422 = CommVisionObjectsIDL::LITERAL_YUV422,

		YUV422P = CommVisionObjectsIDL::LITERAL_YUV422P,

		YUYV = CommVisionObjectsIDL::LITERAL_YUYV
	};

	FormatType()
	{
	}

	FormatType(literal t)
	{
		value = t;
	}

	operator literal()
	{
		return value;
	}

	FormatType(CommVisionObjectsIDL::ENUM_FormatType t)
	{
		value = (literal) t;
	}

	bool operator ==(FormatType& t)
	{
		return this->value == t.value;
	}

	CommVisionObjectsIDL::ENUM_FormatType get_value_idl()
	{
		return (CommVisionObjectsIDL::ENUM_FormatType) value;
	}

	literal get_value() const
	{
		return value;
	}

	std::string get_string() const
	{
		switch (value)
		{

		case GREY:
			return "FormatType::GREY";
			break;

		case RGB24:
			return "FormatType::RGB24";
			break;

		case RGB32:
			return "FormatType::RGB32";
			break;

		case RGB555:
			return "FormatType::RGB555";
			break;

		case RGB565:
			return "FormatType::RGB565";
			break;

		case UYVY:
			return "FormatType::UYVY";
			break;

		case YUV411P:
			return "FormatType::YUV411P";
			break;

		case YUV420P:
			return "FormatType::YUV420P";
			break;

		case YUV422:
			return "FormatType::YUV422";
			break;

		case YUV422P:
			return "FormatType::YUV422P";
			break;

		case YUYV:
			return "FormatType::YUYV";
			break;

		default:
			return "UNKNOWN!";
			break;
		}
	}

private:
	literal value;
};

inline std::ostream &operator<<(std::ostream &os, const FormatType &e)
{
	os << e.get_string();
	return os;
}

}
#endif
