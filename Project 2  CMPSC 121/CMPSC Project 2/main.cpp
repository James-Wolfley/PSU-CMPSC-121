//Author    :   James P Wolfley
//Class     :   CMPSC 121
//Purpose   :	Takes raw intput data and formats and outputs with more info and more readable for a human
//Sources of logic assistance: None

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>

using namespace std;

ofstream fout("output.txt");

double calcCost(int quantity, double unitCost)
{
	return quantity * unitCost;
}

double accTotal(int totalCost, double itemCost)
{
	return totalCost + itemCost;
}

void printLine(string itemNo, string name, int quantity, double unitCost, double totalCost)
{
	fout << fixed << setprecision(2) << setw(10) << itemNo << setw(15) << name << right << setw(5) << quantity << setw(8) << unitCost << setw(10) << totalCost << endl;
	cout << fixed << setprecision(2) << setw(10) << itemNo << setw(15) << name << right << setw(5) << quantity << setw(8) << unitCost << setw(10) << totalCost << endl;
}

void printInvoiceHeader(string date)
{
	fout << "Invoice date: " << date << endl;
	cout << "Invoice date: " << date << endl;
}

void printReportHeader()
{
	fout << "Erie Industrial Supply Corporation" << endl;
	cout << "Erie Industrial Supply Corporation" << endl;
}

void printTotal(double invoiceTotal)
{
	fout << "Total ............................." << right << fixed << setprecision(2) << setw(13) << invoiceTotal << endl;
	cout << "Total ............................." << right << fixed << setprecision(2) << setw(13) << invoiceTotal << endl;
}

int main(int arg)
{
	ifstream fin("Input.txt");
	//I like early returning instead of creating a chain of indents.
	if (!fin)
	{
		cout << "The input file does not exist or is named wrong.\nCheck casing if using linux.\nFile name should be \"Input.txt\" and in the root directory of the program.";
		return 0;
	}

	string date;
	int items;
	while (fin >> items >> date)
	{
		double totalCost = 0;

		printInvoiceHeader(date);
		int quantity;
		double unitPrice, invoiceCost = 0;
		string name, item;
		for (int i = 0; i < items; i++)
		{
			fin >> item >> name >> quantity >> unitPrice;

			totalCost = calcCost(quantity, unitPrice);
			invoiceCost = accTotal(invoiceCost, totalCost);
			printLine(item, name, quantity, unitPrice, totalCost);
		}
		printTotal(invoiceCost);
	}
	fout.close();
	fin.close();
}


/*
Invoice date: 2/12/2017
	134276       Framis-R    8    7.35     58.80
	125790       Framis-L   12   15.76    189.12
	100086          Aglet  395    0.11     43.45
Total .............................       290.45
Invoice date: 1/23/2017
	135876         Wrench   12   22.50    270.00
	543287         Henway    4   19.25     77.00
Total .............................       347.00
Invoice date: 1/15/2017
	161432         Widget    5    6.50     32.50
	543289         Wodget   10    2.25     22.50
	876234         Gadget    2   10.75     21.50
Total .............................        75.50
Invoice date: 2/16/2017
	198765         Corkle    2   12.18     24.36
	107654          Swale    3    8.75     26.25
	987987         Sinter    5    6.43     32.15
	654821         Zangle    6   18.45    110.70
	432165         Lunule    7    9.60     67.20
	333221         Fangle   10   58.49    584.90
	654098      Fwetstock    3   12.65     37.95
	543210         Furnal    3    9.98     29.94
	543287         Bobble   12   19.25    231.00
Total .............................      1140.00
Invoice date: 2/26/2017
	654821         Muntin    2   18.45     36.90
	766443      Finwiddie    9    2.22     19.98
	120980         Ferkle  100    0.12     12.00
	123222     Sneedooper  700    1.19    833.00
	876543        Ferrule    2  345.77    691.54
	877721      Uberfrock   14   88.93   1245.02
Total .............................      2836.02
*/