//Author    :   James P Wolfley
//Class     :   CMPSC 121
//Purpose   :	This program calculates the total cost of your phone bill.
//Sources of logic assistance: None

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
    char choice;
    double minutes;
    double totalPrice;

    cout << fixed << setprecision(2);
    cout << "Enter which plan you have (A, B or C) and number of minutes used this month separated by a space.\n";

    cin >> choice >> minutes;

    //I like a "No tab" approach whenever possible. Early exit instead of branching if statments is cleaner.
    //It can also save performance if this task is repeated often by not evaluating things below this.
    //I also know this section is about if statments so I am using them but I would probably use a case statment instead here.
    if (choice != 'A' && choice != 'B' && choice != 'C' && choice != 'a' && choice != 'b' && choice != 'c')
    {
        cout << "You entered an incorrect option for your plan. Please restart and only enter A, B or C.\n";
        exit(0);
    };

    if (choice == 'A' || choice == 'a')
    {
        if (minutes <= 450) { totalPrice = 39.99; }
        else { totalPrice = 39.99 + ((minutes - 450) * 0.45);}
    }
    else if (choice == 'B' || choice == 'b')
    {
        if (minutes <= 450) { totalPrice = 39.99; }
        else { totalPrice = 59.99 + ((minutes - 900) * 0.40); }
    }
    else if (choice == 'C' || choice == 'c')
    {
        totalPrice = 69.99;
    }

    cout << "For package " << choice << " with " << minutes << " minutes of usage, your bill is:\n$" << totalPrice;

}



/*
Enter which plan you have (A, B or C) and number of minutes used this month separated by a space.
A 650
For package A with 650.00 minutes of usage, your bill is:
$129.99
*/
