//Author    :   James P Wolfley
//Class     :   CMPSC 121
//Purpose   :	
//Sources of logic assistance: None

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main()
{

	//since this is changing systems I have the file in the same folder as the cpp file, pathing might be different in your test enviroment.
	ifstream parts("parts.txt");
	string line, str;


	int countA = 0, countB = 0, countC = 0, countD = 0, countE = 0, countF = 0, countUnknown = 0;
	float totalA = 0, totalB = 0, totalC = 0, totalD = 0, totalE = 0, totalF = 0, totalUnknown = 0;


	while (getline(parts, line)) {

		stringstream lineStream(line);

		//I'd normal just split these into an array but I am doing a hacky workaround to not use arrays.
		getline(lineStream, str, ' ');
		getline(lineStream, str, ' ');

		if (str == "A")
		{
			getline(lineStream, str, ' ');
			countA += stoi(str);
			getline(lineStream, str, ' ');
			totalA += stof(str);

		}
		else if (str == "B")
		{
			getline(lineStream, str, ' ');
			countB += stoi(str);
			getline(lineStream, str, ' ');
			totalB += stof(str);
		}
		else if (str == "C")
		{
			getline(lineStream, str, ' ');
			countC += stoi(str);
			getline(lineStream, str, ' ');
			totalC += stof(str);
		}
		else if (str == "D")
		{
			getline(lineStream, str, ' ');
			countD += stoi(str);
			getline(lineStream, str, ' ');
			totalD += stof(str);

		}
		else if (str == "E")
		{
			getline(lineStream, str, ' ');
			countE += stoi(str);
			getline(lineStream, str, ' ');
			totalE += stof(str);

		}
		else if (str == "F")
		{
			getline(lineStream, str, ' ');
			countF += stoi(str);
			getline(lineStream, str, ' ');
			totalF += stof(str);

		}
		else
		{
			getline(lineStream, str, ' ');
			countUnknown += stoi(str);
			getline(lineStream, str, ' ');
			totalUnknown += stof(str);

		}


	}

	cout << "The first displayed is following the instructions exactly and counting anything that is not A,B,C or D as unknown.\n"
		<< "The second one displayed is counting them and displaying an unknown if there is one.\n"
		<< "I noticed in excel it was the only eroneous data thrown in as unknowns.\n\n\n";

	cout << setprecision(2) << fixed << right;
	cout << "...................... INVENTORY REPORT .......................\n";
	cout << setw(22) << "A parts   Count:" << setw(6) << countA << "  Value of inventory:  " << setw(12) << totalA << endl;
	cout << setw(22) << "B parts   Count:" << setw(6) << countB << "  Value of inventory:  " << setw(12) << totalB << endl;
	cout << setw(22) << "C parts   Count:" << setw(6) << countC << "  Value of inventory:  " << setw(12) << totalC << endl;
	cout << setw(22) << "D parts   Count:" << setw(6) << countD << "  Value of inventory:  " << setw(12) << totalD << endl;
	cout << setw(22) << "Unknown parts   Count:" << setw(6) << countUnknown+countE+countF << "  Value of inventory:  " << setw(12) << totalUnknown+totalE+totalF << endl;

	cout << "\n\n";

	cout << "....................... INVENTORY REPORT ......................\n";
	cout << setw(22) << "A parts   Count:" << setw(6) << countA << "  Value of inventory:  " << setw(12) << totalA << endl;
	cout << setw(22) << "B parts   Count:" << setw(6) << countB << "  Value of inventory:  " << setw(12) << totalB << endl;
	cout << setw(22) << "C parts   Count:" << setw(6) << countC << "  Value of inventory:  " << setw(12) << totalC << endl;
	cout << setw(22) << "D parts   Count:" << setw(6) << countD << "  Value of inventory:  " << setw(12) << totalD << endl;
	cout << setw(22) << "E parts   Count:" << setw(6) << countE << "  Value of inventory:  " << setw(12) << totalE << endl;
	cout << setw(22) << "F parts   Count:" << setw(6) << countF << "  Value of inventory:  " << setw(12) << totalF << endl;
	//The intention is to only show the unknown if their is any
	if (countUnknown > 0 && totalUnknown > 0)cout << setw(15) << "Unknown parts   Count:" << setw(6) << countUnknown << "  Value of inventory:  " << setw(12) << totalUnknown << endl;
}




/*
The first displayed is following the instructions exactly and counting anything that is not A,B,C or D as unknown.
The second one displayed is counting them and displaying an unknown if there is one.
I noticed in excel it was the only eroneous data thrown in as unknowns.


...................... INVENTORY REPORT .......................
	  A parts   Count:  2265  Value of inventory:       7328.87
	  B parts   Count:  1744  Value of inventory:       3160.83
	  C parts   Count:  2167  Value of inventory:       1600.51
	  D parts   Count:  1448  Value of inventory:        928.87
Unknown parts   Count:   274  Value of inventory:        168.50


....................... INVENTORY REPORT ......................
	  A parts   Count:  2265  Value of inventory:       7328.87
	  B parts   Count:  1744  Value of inventory:       3160.83
	  C parts   Count:  2167  Value of inventory:       1600.51
	  D parts   Count:  1448  Value of inventory:        928.87
	  E parts   Count:   137  Value of inventory:        116.85
	  F parts   Count:   137  Value of inventory:         51.65
*/