//Author    :   James P Wolfley
//Class     :   CMPSC 121
//Purpose   :	use functions to calculate the Ulam sequence from a number >= 2.
//Sources of logic assistance: None

#include <iostream>
#include <iomanip>

using namespace std;



void printUlam(int num)
{
	cout << "The Ulam Sequence starting from " << num << " is:";
	do
	{
		cout << " " << num;
		if (num % 2 == 0)
		{
			num = num / 2;
		}
		else
		{
			num = num * 3 + 1;
		}
	} while (num > 1);
	cout << " 1";
}


int main()
{
	int input;

	do
	{
		cout << "Enter a number >= 2: ";
		cin >> input;
		if (input < 2) cout << "Invalid input! Please try again ...\n";
	} while (input < 2);
	printUlam(input);
}

/*
Enter a number >= 2: 1
Invalid input! Please try again ...
Enter a number >= 2: -4
Invalid input! Please try again ...
Enter a number >= 2: 10
The Ulam Sequence starting from 10 is: 10 5 16 8 4 2 1
*/