//Author    :   James P Wolfley
//Class     :   CMPSC 121
//Purpose   :	takes an input file sums the total and outputs a report to a file
//Sources of logic assistance: None

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

struct SalesRecord
{
	string invoiceNumber = "";
	char equipmentCode = ' ';
	double cost = 0;
};

void accumulate(const SalesRecord& s, double& cap, double& eqp, double& prt)
{
	switch (s.equipmentCode)
	{
	case 'A':
		cap += s.cost;
		break;
	case 'B':
		eqp += s.cost;
		break;
	case 'C':
		prt += s.cost;
		break;
	default:
		cout << "Encountered an unexpected character for equipment code\n Exiting....\n";
		exit(1);
	}
}

void writeRepot(ofstream& out, double& cap, double& eqp, double& prt)
{
	out << "\tS A L E S\tR E P O R T\n";
	out << fixed << left << setw(20) << "Capital Equipment" << "$" << right << setw(10) << setprecision(2) << cap << setw(8) << cap/(cap + eqp + prt)*100 << "%\n";
	out << fixed << left << setw(20) << "Expensed Equipment" << "$" << right << setw(10) << setprecision(2) << eqp << setw(8) << eqp/(cap + eqp + prt)*100 << "%\n";
	out << fixed << left << setw(20) << "Small Parts" << "$" << right << setw(10) << setprecision(2) << prt << setw(8) << prt/(cap + eqp + prt)*100 << "%\n";
	out << fixed << left << setw(20) << " " << "-----------\n";
	out << fixed << left << setw(20) << "Total Sales" << "$" << right << setw(10) << setprecision(2) << cap + eqp + prt << endl;

	cout << "\tS A L E S\tR E P O R T\n";
	cout << fixed << left << setw(20) << "Capital Equipment" << "$" << right << setw(10) << setprecision(2) << cap << setw(8) << cap / (cap + eqp + prt) * 100 << "%\n";
	cout << fixed << left << setw(20) << "Expensed Equipment" << "$" << right << setw(10) << setprecision(2) << eqp << setw(8) << eqp / (cap + eqp + prt) * 100 << "%\n";
	cout << fixed << left << setw(20) << "Small Parts" << "$" << right << setw(10) << setprecision(2) << prt << setw(8) << prt / (cap + eqp + prt) * 100 << "%\n";
	cout << fixed << left << setw(20) << " " << "-----------\n";
	cout << fixed << left << setw(20) << "Total Sales" << "$" << right << setw(10) << setprecision(2) << cap + eqp + prt << endl;
}

int main()
{
	ifstream fin("sales.txt");
	ofstream fout("salesReport.txt");
	double cap=0, exp=0, sma=0;
	string line;
	SalesRecord saleRecord;
	if (!fin) {
		cout << "sales.txt was not found\n";
		return 1;
	}

	while (getline(fin, line))
	{
		stringstream ss(line);
		ss >> saleRecord.invoiceNumber >> saleRecord.equipmentCode >> saleRecord.cost;
		accumulate(saleRecord, cap, exp, sma);
	}
	writeRepot(fout, cap, exp, sma);

	fin.close();
	fout.close();
}

/* console/file output
		S A L E S       R E P O R T
Capital Equipment   $  24093.18   26.31%
Expensed Equipment  $  22222.80   24.27%
Small Parts         $  45251.98   49.42%
					-----------
Total Sales         $  91567.96
*/