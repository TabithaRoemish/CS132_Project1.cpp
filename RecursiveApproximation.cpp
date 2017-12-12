//-------------------------------------
// File Name: RecursiveApproximation.cpp
//-------------------------------------
#include "Angle.h"
#include "safeio.h"


// ---------------------------------------------------------------------------
//
//	Function:	main()
//
//	Title:		Recursive Approximation Assignment 2
//
//	Description:	Recursive Approximation of Cosine using class Angle
//
//	Programmer:	Tabitha Roemish
//   
//	Date:		2/1/2017
// 
//	Version:	1.0
//  
//	Environment:	PC 
//				Software:   MS Windows 10
//				Compiles under Microsoft Visual C++.Net 2015
// 
//	Output:		Screen display of Angle objects
// 
//	Calls:		Angle class and related functions
// 
//	Called By:	n/a
// 
//	Parameters:	None
// 
//	Returns:	EXIT_SUCCESS  = successful 
//
//	History Log:
//			2/1/2017  TR  completed version 1.0
//----------------------------------------------------------------------------
int main()
{
	using TR_Angle::Angle;
	char again = 'Y';

	while (again != 'N')
	{
		system("cls");
		Angle a(0.0);
		double radians = 0.0;
		long degree = 0L;
		
		cout << "Please enter an angle in Radians: ";
		safeRead(cin, a);
		cout << "angle: " << a << endl;
		a.printTrigs(cout, a);
		cout << "cos (from cmath): " << a.cosMath() << endl;

		cout << "\nPlease enter an angle in Degrees: ";
		safeRead(cin, degree); // safely ready double
		radians = Angle::degreesToRadians(degree); // convert to radian
		a.setRadians(radians); // set radian on existing angle object
		cout << degree << " degrees: " << a << endl; // print out angle object
		a.printTrigs(cout, a); // print new trig calulations
		cout << "cos (" << degree << ") (from cmath): " << a.cosMath() << endl;

		char again = 'Y';
		again=safeChoice("\nDo you wish to enter another angle?",'Y','N');
	}
	
}





