//Author    :   James P Wolfley
//Class     :   CMPSC 121
//Purpose   :	Calculate the day of the week based on a date given.
//Sources of logic assistance: I don't know if this counts but I did look at the wikipedia article linked in the lab doc but nothing else.

#include <iostream>
#include <iomanip>

using namespace std;


/// <summary>
/// Determines if the year given is a leap year
/// </summary>
/// <param name="year">4 digit year representation</param>
/// <returns>true/false whether it is a leap year</returns>
bool isLeapYear(int year) {
	return (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0));
}

/// <summary>
/// Uses a calculation to assign a value to a given century
/// </summary>
/// <param name="year">4 digit year representation</param>
/// <returns>Value of a given century for in determining the day of the week.</returns>
int getCenturyValue(int year) {
	return ((3 - ((year / 100) % 4)) * 2);
}

/// <summary>
/// Uses a calculation to assign a value to a given year 
/// </summary>
/// <param name="year">4 digit year representation</param>
/// <returns>Value of a given year for in determining the day of the week.</returns>
int getYearValue(int year) {
	return year % 100 / 4 + year % 100;
}

/// <summary>
/// Uses the month and year value to return a value from a precomputed table of values.
/// </summary>
/// <param name="month">int representing month of the year, 1 for Jan, 2 for Feb etc...</param>
/// <param name="year">4 digit year representation</param>
/// <returns>Month Value</returns>
int getMonthValue(int month, int year) {
	switch (month)
	{
	case 1:
		if (isLeapYear(year))return 6;
		return 0;
	case 2:
		if (isLeapYear(year))return 2;
		return 3;
	case 3:
		return 3;
	case 4:
		return 6;
	case 5:
		return 1;
	case 6:
		return 4;
	case 7:
		return 6;
	case 8:
		return 2;
	case 9:
		return 5;
	case 10:
		return 0;
	case 11:
		return 3;
	case 12:
		return 5;
	}
	//this is to get rid of error C4715 but it can only hit this if someone gives a month outside the range of actual months.
	return -1;
}


int main()
{
	bool cont = true;

	//loops while continue flag is set to true
	do
	{
		char resp = '_';
		int month, day, year;
		string weekday = "";
		cout << "Enter a date with the format MM DD YYYY. eg 4 24 1939\n";
		cin >> month >> day >> year;

		switch ((day + getMonthValue(month, year) + getYearValue(year) + getCenturyValue(year)) % 7)
		{
		case 0:
			weekday = "Sunday";
			break;
		case 1:
			weekday = "Monday";
			break;
		case 2:
			weekday = "Tuesday";
			break;
		case 3:
			weekday = "Wednesday";
			break;
		case 4:
			weekday = "Thursday";
			break;
		case 5:
			weekday = "Friday";
			break;
		case 6:
			weekday = "Saturday";
			break;
		default:
			//This should only happen if I made a mistake or an invalid input is thrown in, consider it an easter egg.
			weekday = "| * _ * |";
			break;
		}

		cout << month << "/" << day << "/" << year << " is a " << weekday << endl;

		do
		{
			cout << "Do you have another date? Y or N\n";
			cin >> resp;
			if (resp == 'N' || resp == 'n')
			{
				cont = false;
			}
			else if (resp != 'Y' && resp != 'y')
			{
				cout << "Invalid option. Please enter either Y or N.\n";
			}
		} while (resp != 'Y' && resp != 'N' && resp != 'y' && resp != 'n');

	} while (cont);

}



/*
Enter a date with the format MM DD YYYY. eg 4 24 1939
4 24 1939
4/24/1939 is a Monday
Do you have another date? Y or N
Y
Enter a date with the format MM DD YYYY. eg 4 24 1939
10 26 2016
10/26/2016 is a Wednesday
Do you have another date? Y or N
Y
Enter a date with the format MM DD YYYY. eg 4 24 1939
12 25 2016
12/25/2016 is a Sunday
Do you have another date? Y or N
Y
Enter a date with the format MM DD YYYY. eg 4 24 1939
3 13 2024
3/13/2024 is a Wednesday
Do you have another date? Y or N
Y
Enter a date with the format MM DD YYYY. eg 4 24 1939
3 14 2024
3/14/2024 is a Thursday
Do you have another date? Y or N
N
*/