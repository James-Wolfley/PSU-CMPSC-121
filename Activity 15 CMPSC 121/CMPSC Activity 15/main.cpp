//Author    :   James P Wolfley
//Class     :   CMPSC 121
//Purpose   :	
//Sources of logic assistance: None

#include <iostream>
#include <iomanip>

using namespace std;



double calculateTotal(int i, double iCost) {
	return i * iCost;
}


int main()
{
	char repeat;
	int items;
	double cost;
	double total;

	do
	{
		cout << "Enter number of items and cost: ";
		cin >> items >> cost;
		total = calculateTotal(items, cost);
		cout << fixed << setprecision(2) << "The total cost is $" << calculateTotal(items, cost) << endl;


		cout << "Do you have another item to enter? Y or N\n";
		cin >> repeat;
	} while (repeat != 'N');

}



/*
Enter number of items and cost: 5 2.5
The total cost is $12.50
Do you have another item to enter? Y or N
Y
Enter number of items and cost: 7 11.11
The total cost is $77.77
Do you have another item to enter? Y or N
N
*/