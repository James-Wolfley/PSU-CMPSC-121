//Author    :   James P Wolfley
//Class     :   CMPSC 121
//Purpose   :	Bank account balance tracker
//Sources of logic assistance: None

#include <iostream>
#include <iomanip>

using namespace std;

static double balance = 0;


int main()
{
	bool cont = true;

	//loops while continue flag is set to true
	do
	{	
		//these are scoped to inside the loop to "reset" the state of the logic at the start.
		//it could be argued that initiating once before the loop and reseting is more efficient but this is a tradeoff between readability and speed.
		//for this is doesn't matter anyway
		double transaction = 0;
		char resp = '_';

		//intakes a transaction and repeats if invalid
		do
		{
			cout << fixed << setprecision(2) << "Enter amount of transaction, positive for deposit, negative for withdrawal.\n";
			cin >> transaction;

			if (balance + transaction < 0)
			{
				cout << "Invalid transaction, insufficient funds!\n";
			}
		} while (balance + transaction < 0);

		//update balance
		balance += transaction;
		cout << "Current balance = $" << balance << endl;

		//loop to check for more transactions and verify valid response.
		do
		{
			cout << "Do you have more transactions? Y or N\n";
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
Enter amount of transaction, positive for deposit, negative for withdrawal.
145.00
Current balance = $145.00
Do you have more transactions? Y or N
y
Enter amount of transaction, positive for deposit, negative for withdrawal.
25
Current balance = $170.00
Do you have more transactions? Y or N
y
Enter amount of transaction, positive for deposit, negative for withdrawal.
-30
Current balance = $140.00
Do you have more transactions? Y or N
y
Enter amount of transaction, positive for deposit, negative for withdrawal.
-150
Invalid transaction, insufficient funds!
Enter amount of transaction, positive for deposit, negative for withdrawal.
-15
Current balance = $125.00
Do you have more transactions? Y or N
Y
Enter amount of transaction, positive for deposit, negative for withdrawal.
30
Current balance = $155.00
Do you have more transactions? Y or N
N
*/