//Author    :   James P Wolfley
//Class     :   CMPSC 121
//Purpose   :	
//Sources of logic assistance: None

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int month, day, year;

    cout << "Please enter a numeric month, day and two digit year, separated by spaces.\nExample(8 2 16)\n";
    cin >> month >> day >> year;

    if ((month * day) == year) {
        cout << "It's a MAGIC date!\n";
    }
    else
    {
        cout << "The date you entered is not a magic date.\n";
    }
}


/*
Please enter a numeric month, day and two digit year, separated by spaces.
Example(8 2 16)
8 2 16
It's a MAGIC date!
*/
