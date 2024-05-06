//Author    :   James P Wolfley
//Class     :   CMPSC 121
//Purpose   :	Do a bunch of operations on an array and return the results.
//Sources of logic assistance: None

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

//
void squareArray(int a[], int s)
{
	for (int i = 0; i < s; i++)
	{
		a[i] *= a[i];
	}
}

void randArray(int a[], int s)
{
	srand(time(NULL));
	for (int i = 0; i < s; i++)
	{
		a[i] +=rand() % 11;//this might not have uniform distrobustion but it will work for this project
	}
}

void addNextBack(int a[], int s)
{
	for (int i = 0; i < s; i++)
	{
		if (i + 1 == s)break;
		a[i] += a[i + 1];
	}
}


int sumArray(int a[], int s)
{
	int sum = 0;
	for (int i = 0; i < s; i++)
	{
		sum += a[i];
	}
	return sum;//not sure if you wanted this to do something with it
}

int findLargest(int a[], int s)
{
	int highest = INT16_MIN;
	for (int i = 0; i < s; i++)
	{
		if (a[i] > highest)highest = a[i];
	}
	return highest;
}


int main()
{
    const int SIZE = 10;
    int nums[SIZE] = { 5,4,2,7,6,8,5,2,8,14 };

	//I assumed you wanted each one of these done in order, I took the liberty of printing the results between steps for viewing purposes
	//The ouput as usual is included below
	squareArray(nums, SIZE);
	for (int i = 0; i < SIZE; i++)
	{
		cout << fixed << right << setw(5) << nums[i] << ",";
	}
	cout << endl << endl;
	randArray(nums, SIZE);
	for (int i = 0; i < SIZE; i++)
	{
		cout << fixed << right << setw(5) << nums[i] << ",";
	}
	cout << endl << endl;
	addNextBack(nums, SIZE);
	for (int i = 0; i < SIZE; i++)
	{
		cout << fixed << right << setw(5) << nums[i] << ",";
	}
	cout << endl << endl;

	cout << "The sum of all numbers in the array is " << sumArray(nums, SIZE) << "!\n\n";

	cout << "The largest number in the array is " << findLargest(nums, SIZE) << "!\n";
}

/*
   25,   16,    4,   49,   36,   64,   25,    4,   64,  196,

   25,   24,    9,   55,   36,   67,   26,   11,   67,  196,

   49,   33,   64,   91,  103,   93,   37,   78,  263,  196,

The sum of all numbers in the array is 1007!

The largest number in the array is 263!
*/