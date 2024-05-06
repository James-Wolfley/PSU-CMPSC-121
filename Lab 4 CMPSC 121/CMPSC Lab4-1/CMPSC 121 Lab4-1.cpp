//Author    :   James P Wolfley
//Class     :   CMPSC 121
//Purpose   :	
//Sources of logic assistance: None

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	char vehicleType;
	double totalPrice;
	int hoursParked;
	string vString;
	cout << "Enter what type of vehicle(C, T or B) you parked and how many hours you parked separated by a space.\nVehicle Options:\nC = Car\nT = Truck\nB = Bus\n";
	cin >> vehicleType >> hoursParked;
	//I like to early out like I did in activity 7 but in this case I am going to put it in the else in the next if stament
	//if (vehicleType != 'C' && vehicleType != 'c' && vehicleType != 'T' && vehicleType != 't' && vehicleType != 'B' && vehicleType != 'b') { exit(0); }

	if (vehicleType == 'C' || vehicleType == 'c') {
		vString = "Car";
		if (hoursParked <= 2) { totalPrice = 1.25 * hoursParked; }
		else { totalPrice = (1.25 * 2) + (1.5 * (hoursParked - 2)); }
	}
	else if (vehicleType == 'T' || vehicleType == 't') {
		vString = "Truck";
		if (hoursParked <= 2) { totalPrice = 2.75 * hoursParked; }
		else { totalPrice = (2.75 * 2) + (3.75 * (hoursParked - 2)); }
	}
	else if (vehicleType == 'B' || vehicleType == 'b') {
		vString = "Bus";
		if (hoursParked <= 1) { totalPrice = 9.5 * hoursParked; }
		else { totalPrice = 9.5 + (6.75 * (hoursParked - 1)); }
	}
	else { exit(0); }

	cout << fixed << setprecision(2);
	cout << "Crunchum Parking Lots, Inc.\n\"We usually find your vehicle!\"\n=============================\n";
	cout << "Vehicle Type:\t" << vString << endl;
	cout << "Time:\t\t" << hoursParked << " Hours\n";
	cout << "Amount Due\t$" << totalPrice << "\n=============================\n";

}


/*
Enter what type of vehicle(C, T or B) you parked and how many hours you parked separated by a space.
Vehicle Options:
C = Car
T = Truck
B = Bus
C 7
Crunchum Parking Lots, Inc.
"We usually find your vehicle!"
=============================
Vehicle Type:   Car
Time:           7 Hours
Amount Due      $10.00
=============================


Enter what type of vehicle(C, T or B) you parked and how many hours you parked separated by a space.
Vehicle Options:
C = Car
T = Truck
B = Bus
T 10
Crunchum Parking Lots, Inc.
"We usually find your vehicle!"
=============================
Vehicle Type:   Truck
Time:           10 Hours
Amount Due      $35.50
=============================


Enter what type of vehicle(C, T or B) you parked and how many hours you parked separated by a space.
Vehicle Options:
C = Car
T = Truck
B = Bus
B 8
Crunchum Parking Lots, Inc.
"We usually find your vehicle!"
=============================
Vehicle Type:   Bus
Time:           8 Hours
Amount Due      $56.75
=============================


Enter what type of vehicle(C, T or B) you parked and how many hours you parked separated by a space.
Vehicle Options:
C = Car
T = Truck
B = Bus
B 55
Crunchum Parking Lots, Inc.
"We usually find your vehicle!"
=============================
Vehicle Type:   Bus
Time:           55 Hours
Amount Due      $374.00
=============================

Enter what type of vehicle(C, T or B) you parked and how many hours you parked separated by a space.
Vehicle Options:
C = Car
T = Truck
B = Bus
T 17
Crunchum Parking Lots, Inc.
"We usually find your vehicle!"
=============================
Vehicle Type:   Truck
Time:           17 Hours
Amount Due      $61.75
=============================
*/
