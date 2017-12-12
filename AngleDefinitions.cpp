//----------------------------------------------------------------------------
//	File:		AngleDefinitions.cpp
//
//	functions:	
//			void Angle::setRadians(double x)
//			double Angle::setRadiansToFirstPeriod(double angleInRadians)
//			void Angle::printAngle(std::ostream & o) const
//			double Angle::factorial(double x)
//			double Angle::cosinePrivate(double x)
//			void Angle::printTrigs(std::ostream& o, Angle a) const
//			double Angle::degreesToRadians(long x)
//			ostream & operator<< (ostream & o, const TR_Angle::Angle & a)
//			istream & operator >> (istream & o, Angle & a)
//----------------------------------------------------------------------------
#include <cmath>
#include "Angle.h"
#include "safeio.h"



using namespace std;
namespace TR_Angle
{
	
	//---------------------------------------------------------------------------
	//	Class:			Angle
	//	method:			void Angle::setRadians(double x)
	//	description:	sets radians on already constructed Angle Type
	//	Called By:		
	//	Paramenters:	angleInRadians: double 
	//	History Log:
	//					2/1/2017  TR  completed version 1.0
	//---------------------------------------------------------------------------
	void Angle::setRadians(double x)
	{
		m_radians = setRadiansToFirstPeriod(x);
	}

	//---------------------------------------------------------------------------
	//	Class:			Angle
	//	method:			double Angle::setRadiansToFirstPeriod(double x)
	//	description:	mutates radian input to first period
	//	Called By:		Angle()
	//	Paramenters:	angleInRadians: double  - input in radians
	//	History Log:
	//					2/1/2017  TR  completed version 1.0
	//---------------------------------------------------------------------------

	double Angle::setRadiansToFirstPeriod(double angleInRadians)
	{
		double value = angleInRadians;
		if (value > PERIOD_LIMIT)
		{
			value = fmod(angleInRadians,PERIOD_LIMIT);
		}
		while (value < 0) // convert to positive if negative
			value += PERIOD_LIMIT;
		return value;
	}

	//---------------------------------------------------------------------------
	//	Class:			Angle
	//	method:			void printAngle(std::ostream & o)
	//	description:	prints radians and degrees
	//	Called By:	ostream& operator<<(ostream& o, const TR_Angle::Angle& a);
	//	Paramenters:	x: double  - number to be factorialized
	//	History Log:
	//					2/1/2017  TR  completed version 1.0
	//					2/10/2017 TR completed version 1.1
	//---------------------------------------------------------------------------
	void Angle::printAngle(std::ostream & o) const
	{
		double degrees = getDegrees();
		o << getRadians() << " (" << degrees << setprecision(0) << " degrees)";
	}

	//---------------------------------------------------------------------------
	//	Class:			Angle
	//	method:			double Angle::factorial(double x)
	//	description:	returns the factorial of a double
	//	Called By:		
	//	Paramenters:	x: double  - number to be factorialized
	//	History Log:
	//					2/1/2017  TR  completed version 1.0
	//---------------------------------------------------------------------------
	double Angle::factorial(double x)
	{
		double value = 1;
		if (x > 0)
			value = x * factorial(x - 1);
		return value;
	}

	//---------------------------------------------------------------------------
	//	Class:			Angle
	//	method:			double Angle::cosinePrivate(double x)
	//	description:	recursive function that finds cosine of angle in radians
	//	Called By:		
	//	Paramenters:	x: double  - radian angle on which cosine is calculated
	//	History Log:
	//					2/1/2017  TR  completed version 1.0
	//---------------------------------------------------------------------------

	double Angle::cosineReturn = 0;	// initialize static variable 
									// "cosineReturn" from Angle Class for 
									// cosinePrivate Function

	double Angle::cosinePrivate(double x)
	{
		double instance = 0;
		static int n = 0;
	
		instance = (pow(-1, n) * pow(x, 2*n)) / factorial(2 * n);
		if (fabs(instance) > 0.000001)
		{
			cosineReturn += instance;
			n++;
			cosinePrivate(x);
		}

		n = 0; // reset n counter
		
		return cosineReturn;
	}

	//---------------------------------------------------------------------------
	//	Class:			Angle
	//	method:			void Angle::printTrigs(std::ostream& o, Angle a)
	//	description:	prints calculated trig functions on Angle a
	//	Called By:		main()
	//	Paramenters:	o: ostream, a: Angle object to print
	//	History Log:
	//					2/1/2017  TR  completed version 1.0
	//---------------------------------------------------------------------------
	void Angle::printTrigs(std::ostream& o, Angle a) const
	{
		o << "sine: " << a.sine() << endl;
		o << "tangent: " << a.tangent() << endl;
		o << "cosine: " << a.cosine() << endl;
		
	}

	//---------------------------------------------------------------------------
	//	Class:			Angle
	//	method:			double Angle::degreesToRadians(long x)
	//	description:	converts degrees into Radians
	//	Called By:		
	//	Paramenters:	x: long degrees 
	//	History Log:
	//					2/1/2017  TR  completed version 1.0
	//					2/10/2017 TR complted version 1.1
	//---------------------------------------------------------------------------
	double Angle::degreesToRadians(long x)
	{
		double radians = (x == 360) ? 0 : x*RAD_CONVERSION;
		return radians;
	}

	//---------------------------------------------------------------------------
	//	Related Class:			Angle
	//	method:		ostream & operator<< (ostream & o, const TR_Angle::Angle & a)
	//	description:	ostream overloader that prints out Angle Type
	//	Called By:		
	//	Paramenters:	o: ostream, a: Angle reference
	//	History Log:
	//					2/1/2017  TR  completed version 1.0
	//---------------------------------------------------------------------------
	ostream & operator<< (ostream & o, const TR_Angle::Angle & a)
	{
		a.printAngle(o);
		return o;
	}

	//---------------------------------------------------------------------------
	//	Related Class:			Angle
	//	method:		istream & operator >> (istream & o, Angle & a)
	//	description:	istream overloader that reads into angle
	//	Called By:		
	//	Paramenters:	o: ostream, a: Angle reference
	//	History Log:
	//					2/1/2017  TR  completed version 1.0
	//---------------------------------------------------------------------------
	istream & operator >> (istream & o, Angle & a)
	{
		double value;
		o >> value;
		a.setRadians(value);
		return o;
	}
}