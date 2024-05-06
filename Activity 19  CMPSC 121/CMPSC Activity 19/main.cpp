//Author    :   James P Wolfley
//Class     :   CMPSC 121
//Purpose   :	calculate area of triangles
//Sources of logic assistance: None

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double triangleArea(double base, double height)
{
    return 0.5 * base * height;
}

double triangleArea(double a, double b, double c)
{
    double s = (a + b + c) / 2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main()
{
    double a, b, c;
    char resp;
    do
    {

        if (rand()%2 == 0)
        {
            cout << "Enter base and height of a triangle.\n";
            cin >> a >> b;
            cout << fixed << setprecision(2) << "The area is " << triangleArea(a, b) << endl;
        }
        else
        {
            cout << "Enter the lengths of the sides of a triangle.\n";
            cin >> a >> b >> c;
            cout << fixed << setprecision(2) << "The area is " << triangleArea(a, b, c) << endl;
        }

        cout << "Run again? y or n\n";
        cin >> resp;
    } while (resp == 'y');
}



/*
Enter the lengths of the sides of a triangle.
18 30 24
The area is 216.00
Run again? y or n
y
Enter the lengths of the sides of a triangle.
20 28 34
The area is 279.91
Run again? y or n
y
Enter base and height of a triangle.
24 18
The area is 216.00
Run again? y or n
n
*/