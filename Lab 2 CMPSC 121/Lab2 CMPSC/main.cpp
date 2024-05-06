#include <iostream>

using namespace std;

int main()
{
	int sum;
	int num1;
	int num2;
	int num3;
	int num4;

	cout << "Please enter a 4 digit integer." << endl;

	cin >> sum;

	num4 = sum % 10;
	num3 = sum / 10 % 10;
	num2 = sum / 100 % 10;
	num1 = sum / 1000 % 10;

	sum = num1 + num2 + num3 + num4;

	cout << "Sum of the digits: " << num1 << " + " << num2 << " + " << num3 << " + " << num4 << " = " << sum << endl;

	num4 = sum % 10;
	num3 = sum / 10 % 10;
	num2 = sum / 100 % 10;
	num1 = sum / 1000 % 10;

	sum = num1 + num2 + num3 + num4;

	cout << "Sum of the digits of the sum: " << num1 << " + " << num2 << " + " << num3 << " + " << num4 << " = " << sum << endl;

	num4 = sum % 10;
	num3 = sum / 10 % 10;
	num2 = sum / 100 % 10;
	num1 = sum / 1000 % 10;

	sum = num1 + num2 + num3 + num4;

	cout << "Sum of the digits of the sum of the digits of the sum: " << num1 << " + " << num2 << " + " << num3 << " + " << num4 << " = " << sum << endl;

}

/*
Please enter a 4 digit integer.
1423
Sum of the digits: 1 + 4 + 2 + 3 = 10
Sum of the digits of the sum: 0 + 0 + 1 + 0 = 1
Sum of the digits of the sum of the digits of the sum: 0 + 0 + 0 + 1 = 1
*/