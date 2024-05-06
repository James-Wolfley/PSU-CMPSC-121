//Author    :   James P Wolfley
//Class     :   CMPSC 121
//Purpose   :	calculate the length of a pole that fits inside a rectangle
//Sources of logic assistance: None

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;


void handlePoleData(int &x, int &y, int &z) 
{
    cout << fixed << setprecision(2) << "The longest pole that can fit in this room is: " << double(sqrt(x*x+y*y+z*z)) << " meters\n";
}


void getBoxData()
{
    int x, y, z;
    cout << "Enter the width, length and height of a box separated by a space. EX 10 8 5\n";
    cin >> x >> y >> z;
    handlePoleData(x, y, z);
}

//quite possibly the shortest main I have ever written.
int main()
{
    getBoxData();
}

/*
Enter the width, length and height of a box separated by a space. EX 10 8 5
10 8 5
The longest pole that can fit in this room is: 13.75 meters
*/