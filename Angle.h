//----------------------------------
// File: Angle.h
//
// Class: Angle
//----------------------------------

#define _USE_MATH_DEFINES
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define RAD_CONVERSION (M_PI/180)
#define DEG_CONVERSION (180/M_PI)
#define PERIOD_LIMIT (2 * M_PI)

#ifndef ANGLE_H
#define ANGLE_H
#include <iostream>
//------------------------------------------------------------------------
//	Title:          Angle Class
//
//	Description:    class definition for Angle
//
//	Programmer:     Tabitha Roemish
//   
//	Date:           2/1/2017
// 
//	Version:		1.0
//		
//	Environment:	PC 
//					Software:   MS Windows 10
//					Compiles under Microsoft Visual C++.Net 2015
//
//	class Angle:
//
//	Properties:
//			m_radians
//			m_degrees
//	Methods:
//	
//		inline:	
//		Angle(double angleInRadians = 0.0) { setRadians(angleInRadians); };
//			double sine() { return sin(m_radians); };
//			double tangent() { return tan(m_radians); };
//			double cosMath() { return cos(m_radians); };
//			double getRadians() const { return m_radians; };
//			double getDegrees() const { return m_radians*DEG_CONVERSION; };
//
//		non-inline:
//			void setRadians(double x);
//			void printAngle(std::ostream & o) const;
//			void printTrigs(std::ostream& o, Angle a) const;
//			static double degreesToRadians(long x);
//			double setRadiansToFirstPeriod(double x);
//			static double factorial(double x);
//			static double cosinePrivate(double x);
//
//    History Log:
//		2/1/2017   TR  released version 1.0
//------------------------------------------------------------------------

using namespace std;

namespace TR_Angle
{
	class Angle
	{
	public:
		Angle(double angleInRadians = 0.0) { setRadians(angleInRadians); };
		void setRadians(double x);
		
		double getRadians() const { return m_radians; };
		double getDegrees() const { return m_radians*DEG_CONVERSION; };

		void printAngle(std::ostream & o) const;
		void printTrigs(std::ostream& o, Angle a) const;
		double sine() { return sin(m_radians); };
		double tangent() { return tan(m_radians); };
		double cosMath() { return cos(m_radians); };
		double cosine() { cosineReturn = 0; return cosinePrivate(m_radians); };
		static double degreesToRadians(long x);
		static double cosineReturn;

	private:
		double m_radians;
		double setRadiansToFirstPeriod(double x);
		static double factorial(double x);
		static double cosinePrivate(double x);

	};



// related ostream/istream operator overloads for Angle Class
ostream & operator<< (ostream & o, const Angle & a);
istream & operator>> (istream & o, Angle &a);


}

#endif



