//Author    :   James P Wolfley
//Class     :   CMPSC 121
//Purpose   :	Data entrance terminal to output to a file.
//Sources of logic assistance: None

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct partData {
    string num = "";
    string name = "";
    char pClass = ' ';
    int quantity = 0;
    double unitPrice = 0;

    //Wouldnt be used in this project but constructors and what not down here.
};

void writeData(ofstream& out,const partData& d) 
{
    out << d.num << "," << d.name << "," << d.pClass << "," << d.quantity << "," << d.unitPrice << endl;
}


int main()
{
    ofstream fout;
    string cont = "";
    partData part;
    fout.open("output.txt");

    cout << "Enter info (Part-Number Part-Name Part-Class Quantity Unit-Price)\n";
    do
    {
        string line;
        getline(cin, line);
        stringstream lS(line);
        lS >> part.num >> part.name >> part.pClass >> part.quantity >> part.unitPrice;
        writeData(fout, part);

        cout << "More parts? Y or N\n";
        getline(cin, cont);
    } while (cont == "Y");
    

    fout.close();
}

//I chose to make the file comma delimited because its useful for other things, tons of things read csv files.

/*
Console out----
Enter info (Part-Number Part-Name Part-Class Quantity Unit-Price)
P-14376 Widget B 120 34.95
More parts? Y or N
Y
P-16543 Wodget C 80 15.75
More parts? Y or N
N


File Output----
P-14376,Widget,B,120,34.95
P-16543,Wodget,C,80,15.75
*/