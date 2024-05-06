#include <iostream>
using namespace std;

int main()
{
	double length, width, height, volume, surface;
	cout << "Enter length, width and height in inches: ";
	cin >> length >> width >> height;
	volume = length * width * height;
	surface = 2 * length * width + 2 * length * height + 2 * height * width;
	cout << "For a box with length = " << length << ", width = " << width << ", height = " << height << endl;
	cout << "the volume is " << volume << " cubic inches and the surface is " << surface << " square inches" << endl;
	return 0;
}


/*  Execution Sample:
Enter length, width and height in inches: 12 8 7
For a box with length = 12, width = 8, height = 7
the volume is 672 cubic inches and the surface is 472 square inches
*/
