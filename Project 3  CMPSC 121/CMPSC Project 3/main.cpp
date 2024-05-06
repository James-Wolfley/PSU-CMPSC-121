//Author    :   James P Wolfley
//Class     :   CMPSC 121
//Purpose   :	Reads in and sorts list of parts as well as letting a user add more to the list while maintaining the order.
//Sources of logic assistance: None

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct Part
{
	string ID;
	int PartNum;
	char C;
	int Quantity;
	double Value;

	Part()
	{
		ID = "";
		PartNum = -1;
		C = ' ';
		Quantity = -1;
		Value = -1;
	}

	Part(string iD, char c, int quantity, double value)
	{
		ID = iD;
		PartNum = stoi(iD.substr(2, iD.length()));
		C = c;
		Quantity = quantity;
		Value = value;
	};



};
bool binarySearch(vector<Part>& V, int num, int& index);
void swapper(Part& a, Part& b);
void shellSort(vector<Part>& V);
bool readFile(vector<Part>& V, string fileName);
void writeFile(vector<Part>& V, string fileName);
void insertPart(vector<Part>& V, Part p);

int main()
{
	vector<Part> parts;
	string fileName = "parts.txt";
	readFile(parts, fileName);
	shellSort(parts);
	int index;
	string sortString, cont;
	int goodSearch = 0, badSearch = 0;
	do
	{
		system("cls");
		cout << "Enter a part number to search for.\n";
		cin >> sortString;
		if (binarySearch(parts, stoi(sortString.substr(2, sortString.length())), index))
		{
			cout << "There are " << parts[index].Quantity << " of Part Number " << parts[index].ID << " in inventory.\n";
			cout << "It is a class " << parts[index].C << " part.\n";
			cout << "The cost is $" << fixed << setprecision(2) << parts[index].Value << endl;
			cout << "The value of that inventory is $" << parts[index].Quantity * parts[index].Value << endl;
			goodSearch++;
		}
		else
		{
			char c;
			int quant;
			double val;
			cout << "That part doesnt exist please enter the info in the form, Class Quantity Value\n";
			cin >> c >> quant >> val;
			insertPart(parts, Part(sortString, c, quant, val));
			badSearch++;
		}
		cout << "Would you like to search for another part? Y or N.\n";
		cin >> cont;
	} while (cont == "Y");

	cout << "\nYou made " << goodSearch + badSearch << " searches.\n";
	cout << goodSearch << " were found in the database and " << badSearch << " were added to the database.\n";
	writeFile(parts, "sortedParts.txt");
}


//reads the file in
bool readFile(vector<Part>& V, string fileName)
{
	ifstream fin(fileName);
	string line, pnumber;
	char c;
	int q;
	double val;
	while (getline(fin, line))
	{
		stringstream ss(line);
		ss >> pnumber >> c >> q >> val;
		V.push_back(Part(pnumber, c, q, val));
	}
	fin.close();
	if (V.empty())return false;

	return true;
}

//writes the file out
void writeFile(vector<Part>& V, string fileName)
{
	ofstream fout(fileName);

	for (size_t i = 0; i < V.size(); i++)
	{
		fout << V[i].ID << " " << V[i].C << " " << V[i].Quantity << " " << V[i].Value << endl;
	}
	fout.close();
}

void shellSort(vector<Part>& V)
{
	bool flag = true;
	int i, numLength = V.size();

	int d = numLength;
	while (flag || (d > 1))    // bool flag 
	{
		flag = false;  //reset flag to 0 to check for
		// future swaps
		d = (d + 1) / 2;
		for (i = 0; i < (numLength - d); i++)
		{
			if (V[i + d].PartNum < V[i].PartNum)
			{
				swapper(V[i], V[i + d]);

				flag = true;     //tells swap has occurred
			}
		}
	}
}
void swapper(Part& a, Part& b)
{
	Part temp;
	temp = a;
	a = b;
	b = temp;
}

//binary sort based on the number value of the part number
bool binarySearch(vector<Part>& V, int num, int& index)
{
	int min = 0, max = V.size(), mid = V.size() / 2;
	bool cont = true;
	int element;
	while (min <= max)
	{
		element = V[mid].PartNum;

		if (element == num)
		{
			index = mid;
			return true;
		}
		else if (element < num)
		{
			min = mid + 1;
		}
		else
		{
			max = mid - 1;
		}
		mid = (min + max) / 2;

	}
	return false;
}

//appends a new part and resorts the vector
void insertPart(vector<Part>& V, Part p)
{
	//This is sorta lazy sorta not
	//Would require more analyzing to determine if this is faster or if
	//looking for the correct insertion point and moving the rest would be faster.
	V.push_back(p);
	shellSort(V);
}



/*These are in between the clear screen command
Enter a part number to search for.
P-10022
That part doesnt exist please enter the info in the form, Class Quantity Value
C 123 45
Would you like to search for another part? Y or N.

Enter a part number to search for.
P-31977
That part doesnt exist please enter the info in the form, Class Quantity Value
A 12 156
Would you like to search for another part? Y or N.
Y

Enter a part number to search for.
P-32344
That part doesnt exist please enter the info in the form, Class Quantity Value
D 88 12
Would you like to search for another part? Y or N.
Y

//I redid this one after adding to verify it had added it and that the search works correctly.

Enter a part number to search for.
P-32344
There are 88 of Part Number P-32344 in inventory.
It is a class D part.
The cost is $12.00
The value of that inventory is $1056.00
Would you like to search for another part? Y or N.
N

You made 4 searches.
1 were found in the database and 3 were added to the database.
*/