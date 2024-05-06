//Author    :   James P Wolfley
//Class     :   CMPSC 121
//Purpose   :	
//Sources of logic assistance: None

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int num = 0, evenSum = 0, oddSum = 0;
	while (num < 10000) {
		cout << "Enter an integer greater than 10,000: ";
		cin >> num;
		if (num < 10000)
		{
			cout << num << " is not greater than 10,000. Try again.\n";
		}
	}

	int workingNum = num;
	int digit;
	while (workingNum != 0)
	{
		digit = workingNum % 10;
		if (digit % 2 == 0)
		{
			evenSum += digit;
		}
		else
		{
			oddSum += digit;
		}
		workingNum = workingNum / 10;
	}

	cout << "The sum of the even digits of " << num << " is: " << evenSum << endl;
	cout << "The sum of the odd digits of " << num << " is: " << oddSum << endl;
}



/*
Enter an integer greater than 10,000: 5
5 is not greater than 10,000. Try again.
Enter an integer greater than 10,000: 987654321
The sum of the even digits of 987654321 is: 20
The sum of the odd digits of 987654321 is: 25
*/