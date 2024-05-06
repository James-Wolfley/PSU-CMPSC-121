//Author    :   James P Wolfley
//Class     :   CMPSC 121
//Purpose   :	A volume and surface area calaculator for a torus using the cross section radius and the radius of the torus.
//Sources of logic assistance: None


#include <iostream>
#include <iomanip>

using namespace std;
const double PI = 3.14159;
/*
Needed formulas
V=2pi^2*R*r^2
S=4pi^2*R*r
*/

int main()
{
	double cRadius, radius, volume, surfaceArea;
	cout << "Enter the radius of the ring and the radius of a cross section separated by a space.\n";
	cin >> radius >> cRadius;

	volume = 2 * (PI * PI) * radius * (cRadius * cRadius);
	surfaceArea = 4 * (PI * PI) * radius * cRadius;
	cout << fixed << setprecision(3);
	cout << "For a ring with a radius of " << radius << " and a cross section radius of " << cRadius << endl;
	cout << left << setw(25) << "The volume is:" << volume << endl;
	cout << left << setw(25) << "The surface area is:" << surfaceArea << endl;

}

/*
Enter the radius of the ring and the radius of a cross section separated by a space.
25.75 3
For a ring with a radius of 25.750 and a cross section radius of 3.000
The volume is:           4574.554
The surface area is:     3049.703
*/