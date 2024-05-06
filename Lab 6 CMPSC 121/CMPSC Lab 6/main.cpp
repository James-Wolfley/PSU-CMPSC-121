//Author    :   James P Wolfley
//Class     :   CMPSC 121
//Purpose   :	Calculate statistics about transactions entered.
//Sources of logic assistance: None

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int quantity = 0;
	int totalUnits = 0;
	int transactionsProcessed = 0;
	double totalRevenue = 0;
	double transactionAmount = 0;
	double minTransaction = DBL_MAX;
	double maxTransaction = DBL_MIN;


	cout << "Enter transactions -99 9 to stop.\n";
	do
	{
		
		cout << "Transaction # " << transactionsProcessed + 1 << ": ";
		cin >> quantity >> transactionAmount;

		
		if (quantity != -99 || transactionAmount != 0)
		{
			totalRevenue += transactionAmount* quantity;
			totalUnits += quantity;
			if (transactionAmount * quantity < minTransaction)
				minTransaction = transactionAmount*quantity;
			if (transactionAmount * quantity > maxTransaction)
				maxTransaction = transactionAmount* quantity;
			transactionsProcessed += 1;
		}

	} while (quantity != -99 || transactionAmount != 0);


	cout << setprecision(2) << fixed;

	cout << "TRANSACTION PROCESSING REPORT\n";
	cout << left << setw(30) << "\tTransactions Processed:" << right << setw(10) << transactionsProcessed << endl;
	cout << left << setw(30) << "\tUnits Sold:" << right << setw(10) << totalUnits << endl;
	cout << left << setw(30) << "\tAverage Units Per Order:" << right << setw(10) << (totalUnits*1.0f) / transactionsProcessed << endl;
	cout << left << setw(30) << "\tLargest Transaction:" << right << setw(10) << maxTransaction << endl;
	cout << left << setw(30) << "\tSmallest Transaction:" << right << setw(10) << minTransaction << endl;
	cout << left << setw(30) << "\tTotal Revenue:" << "$" << right << setw(9) << totalRevenue << endl;
	cout << left << setw(30) << "\tAverage Revenue:" << "$" << right << setw(9) << totalRevenue / transactionsProcessed << endl;


}

/*
 Enter transactions -99 9 to stop.
Transaction # 1: 30 9.75
Transaction # 2: 22 8.5
Transaction # 3: 15 7.95
Transaction # 4: 12 9
Transaction # 5: 16 8.55
Transaction # 6: 36 7.99
Transaction # 7: 100 10.75
Transaction # 8: 43 9.99
Transaction # 9: 14 6.95
Transaction # 10: 13 8.98
Transaction # 11: -99 0
TRANSACTION PROCESSING REPORT
        Transactions Processed:              10
        Units Sold:                         301
        Average Units Per Order:          30.10
        Largest Transaction:            1075.00
        Smallest Transaction:             97.30
        Total Revenue:               $  2849.80
        Average Revenue:             $   284.98
*/