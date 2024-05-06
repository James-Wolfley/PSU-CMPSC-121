//Author    :   James P Wolfley
//Class     :   CMPSC 121
//Purpose   :	This program calculates the torque a motor puts out and the minimum shaft diameter required to have enough sheer strength to transmit the torque.
//Sources of logic assistance:


#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;



int main()
{
	double P, n, s, d, t;
	int colW = 15;
	cout << "Enter values for horsepower(P), rpm(n) and shear strength(s) separated by a space.\n";
	cin >> P >> n >> s;

	t = 63000 * (P / n);
	d = pow((16 * t) / s, 0.333);

	cout << fixed << setprecision(3) << left << setw(colW) << "P(HP)" << setw(colW) << "N(rpm)" << setw(colW) << "S(psi)" << setw(colW) << "T(torque)" << setw(colW) << "D(diameter)" << endl;
	cout << left << setw(colW) << P << setw(colW) << n << setw(colW) << s << setw(colW) << t  << d << " inches" << endl;
}


/*
* Given values
Enter values for horsepower(P), rpm(n) and shear strength(s) separated by a space.
20 1500 5000
P(HP)          N(rpm)         S(psi)         T(torque)      D(diameter)
20.000         1500.000       5000.000       840.000        1.390 inches

Enter values for horsepower(P), rpm(n) and shear strength(s) separated by a space.
20 50 5000
P(HP)          N(rpm)         S(psi)         T(torque)      D(diameter)
20.000         50.000         5000.000       25200.000      4.314 inches

Enter values for horsepower(P), rpm(n) and shear strength(s) separated by a space.
270 40 6500
P(HP)          N(rpm)         S(psi)         T(torque)      D(diameter)
270.000        40.000         6500.000       425250.000     10.130 inches

My own values
Enter values for horsepower(P), rpm(n) and shear strength(s) separated by a space.
20 40 5000
P(HP)          N(rpm)         S(psi)         T(torque)      D(diameter)
20.000         40.000         5000.000       31500.000      4.647 inches

Enter values for horsepower(P), rpm(n) and shear strength(s) separated by a space.
270 1500 6500
P(HP)          N(rpm)         S(psi)         T(torque)      D(diameter)
270.000        1500.000       6500.000       11340.000      3.030 inches
*/