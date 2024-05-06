//Author    :   James P Wolfley
//Class     :   CMPSC 121
//Purpose   :	Calculates bill of Zippy Cell Phone Company
//Sources of logic assistance: None

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	char plan = 'z';
	int dayMin, nightMin = 0;
	double totalCost = 0;
	//I am only doing this because the account number is not used anywhere else. Usually this would be used to look up the account and I wouldnt need the plan type either.
	string _;
	cout << "Enter your account number and your plan type(s or p) separated by a space.\n";

	while (plan != 's' && plan != 'p')
	{
		cin.sync();
		cin >> _ >> plan;
		if (plan == 's' || plan == 'p') { break; }
		cout << "The plan you entered wasnt valid try again.\n";
	}

	cout << fixed << setprecision(2);
	if (plan == 's')
	{
		cout << "Please enter the total amount of minutes used.\n";
		cin >> dayMin;

		if (dayMin <= 60)
		{
			totalCost = 12;
		}
		else
		{
			totalCost = 12 + (dayMin - 60.0) * .20;
		}

		//All code here would be in a function normally to display the result.
		cout << "---------Zippy Cell Phone Company ---------\n";
		cout << "Service Type:\t\tSTANDARD\n";
		cout << "Minutes Used:\t\t" << dayMin << endl;
		cout << "Amount Due:\t\t$" << totalCost << endl;
	}
	else if (plan == 'p')
	{
		cout << "Please enter the amount of daytime minutes and nighttime minutes used separated by a space.\n";
		cin >> dayMin >> nightMin;


		double dayCost = 0, nightCost = 0;
		if (dayMin >= 75)
		{
			dayCost = (dayMin - 75.0) * .10;
		}
		if (nightMin >= 100)
		{
			nightCost = (nightMin - 100.0) * .05;
		}
		totalCost = 25 + dayCost + nightCost;

		//All code here would be in a function normally to display the result.
		cout << "---------Zippy Cell Phone Company ---------\n";
		cout << "Service Type:\t\tSTANDARD\n";
		cout << "Day minutes Used:\t" << dayMin << endl;
		cout << "Night minutes Used:\t" << nightMin << endl;
		cout << "Amount Due:\t\t$" << totalCost << endl;
	}

	int i = 0;
	float j = 1;
	int k = i / j;
	int _ =  i + j;
}

/*
Enter your account number and your plan type(s or p) separated by a space.
d
s
Please enter the total amount of minutes used.
150
---------Zippy Cell Phone Company ---------
Service Type:           STANDARD
Minutes Used:           150
Amount Due:             $30.00


Enter your account number and your plan type(s or p) separated by a space.
p p
Please enter the amount of daytime minutes and nighttime minutes used separated by a space.
150 151
---------Zippy Cell Phone Company ---------
Service Type:           STANDARD
Day minutes Used:       150
Night minutes Used:     151
Amount Due:             $32.50
*/

