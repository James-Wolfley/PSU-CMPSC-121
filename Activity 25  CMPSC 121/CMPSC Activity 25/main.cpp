//Author    :   James P Wolfley
//Class     :   CMPSC 121
//Purpose   :	Generates a collection of integers, sorts them and returns statistics about them
//Sources of logic assistance: None

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void shellSort(vector<int>& V);
void swapper(int& a, int& b);
void runStats(vector<int>& V, int& numOdd, int& numEven, double& average, int& total);
bool binarySearch(vector<int>& V, int num, int& index);


int main()
{
	const int SIZE = 5000;
	vector<int> nums(SIZE);
	int odd, even, tot;
	double average;
	int foundIndex, numToFind;

	srand(time(NULL));
	for (size_t i = 0; i < nums.size(); i++)
	{
		nums[i] = rand();
	}

	shellSort(nums);
	runStats(nums, odd, even, average, tot);
	
	//If you sort first the largest and smallest is already apparent
	cout << "The smallest number is " << nums[0] << endl;
	cout << "The largest number is " << nums[nums.size() - 1] << endl;
	cout << "The number of odd values is " << odd << endl;
	cout << "The number of even values is " << even << endl;
	cout << "The total of all values is " << tot << endl;
	cout << fixed << setprecision(2) << "The average of all values is " << average << endl;
	cout << "Enter an integer: ";
	cin >> numToFind;
	if (binarySearch(nums, numToFind, foundIndex))
	{
		cout << numToFind << " was found at position " << foundIndex << endl;
	} 
	else
	{
		cout << numToFind << " was not found\n";
	}
	

}


//Im about to write a binary search alg from memory and may not be perfect
//This is more of a test to me than just looking up how to do it

bool binarySearch(vector<int>& V, int num, int& index)
{
	int min = 0, max = V.size(), mid = V.size()/2;
	bool cont = true;
	int element;
	while (min <= max)
	{
		element = V[mid];

		if (element == num)
		{
			index = mid;
			return true;
		}
		else if(element<num)
		{
			min = mid + 1;
		}
		else
		{
			max = mid - 1;
		}
		mid = (min + max) / 2;

	}
	return false;
}

//Passed by reference to have multiple "returns"
//I did this all at once to only loop through one time since its required for all the stats needed
void runStats(vector<int>& V, int& numOdd, int& numEven, double& average, int& total)
{
	numOdd = 0;
	numEven = 0;
	total = 0;
	average = 0;

	for (size_t i = 0; i < V.size(); i++)
	{
		if (V[i] % 2 == 0)
		{
			numEven++;
		}
		else
		{
			numOdd++;
		}
		total += V[i];
	}
	average = total / V.size();
}


void shellSort(vector<int>& V)
{
	bool flag = true;
	int i, numLength = V.size();

	int d = numLength;
	while (flag || (d > 1))    // bool flag 
	{
		flag = false;  //reset flag to 0 to check for
		// future swaps     
		d = (d + 1) / 2;
		for (i = 0; i < (numLength - d); i++)
		{
			if (V[i + d] < V[i])
			{
				swapper(V[i], V[i + d]);

				flag = true;     //tells swap has occurred
			}
		}
	}
}
void swapper(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}



/*
The smallest number is 2
The largest number is 32761
The number of odd values is 2457
The number of even values is 2543
The total of all values is 81391469
The average of all values is 16278.00
Enter an integer: 3654
3654 was not found


The smallest number is 9
The largest number is 32764
The number of odd values is 2546
The number of even values is 2454
The total of all values is 82839230
The average of all values is 16567.00
Enter an integer: 5646
5646 was not found

The smallest number is 5
The largest number is 32767
The number of odd values is 2456
The number of even values is 2544
The total of all values is 82461566
The average of all values is 16492.00
Enter an integer: 1850
1850 was found at position 274
*/