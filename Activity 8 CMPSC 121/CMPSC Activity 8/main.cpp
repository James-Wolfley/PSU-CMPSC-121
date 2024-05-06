//Author    :   James P Wolfley
//Class     :   CMPSC 121
//Purpose   :	Tell you if your at the origin point or at one of the axis
//Sources of logic assistance: None

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int x, y;
	cout << "Enter two the x and y coordinate separated by a space rounded to the nearest whole number.\n";
	cin >> x >> y;
	cout << "You entered ( " << x << ", " << y << "). ";
	//I chose to use else if here due to the twin arguments needed but had it only been one I would have used a switch stament
	if (x == 0 && y == 0) {
		cout << "You are at the origin.";
	}
	else if (x == 0) {
		cout << "You are on the X axis.";
	}
	else if (y == 0) {
		cout << "You are on the Y axis.";
	}
	else if(x > 0 && y > 0) {
		cout << "You are in quadrant 1";
	}
	else if (x < 0 && y > 0) {
		cout << "You are in quadrant 2";
	}
	else if (x < 0 && y < 0) {
		cout << "You are in quadrant 3";
	}
	else if (x > 0 && y < 0) {
		cout << "You are in quadrant 4";
	}
}



/*
Enter two the x and y coordinate separated by a space rounded to the nearest whole number.
0 0
You entered ( 0, 0). You are at the origin.
*/