//Author    :   James P Wolfley
//Class     :   CMPSC 121
//Purpose   :	Formats a name given
//Sources of logic assistance: None

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string contChar;

    do
    {
        string first, middle, last, full;
        cout << "Enter a name first mi last\n";
        getline(cin, full);
        stringstream fullStream(full);


        getline(fullStream, first, ' ');
        getline(fullStream, middle, ' ');
        getline(fullStream, last, ' ');

        first[0] = toupper(first[0]);
        middle[0] = toupper(middle[0]);
        last[0] = toupper(last[0]);

        cout << "You entered: " << full << "\nIt was converted to: " << last << ", " << first << " " << middle << endl << "Do you wish to enter another name?\n";
        getline(cin, contChar);
    } while (contChar.find("y") != std::string::npos|| contChar.find("Y") != std::string::npos);
    
}



/*
Enter a name first mi last
samuel p. clemens
You entered: samuel p. clemens
It was converted to: Clemens, Samuel P.
Do you wish to enter another name?
y
Enter a name first mi last
donald e. knuth
You entered: donald e. knuth
It was converted to: Knuth, Donald E.
Do you wish to enter another name?
n
*/