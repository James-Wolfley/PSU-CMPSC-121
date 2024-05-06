//Author    :   James P Wolfley
//Class     :   CMPSC 121
//Purpose   :	Reads in a file and allows you to view various statistics based on use requests
//Sources of logic assistance: None

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;



struct part;
bool readFile(vector<part>& parts, string fileName);
double totalInv(vector<part>& parts);
void typeTotals(vector<part>& parts, map<char, int>& t);
double cCostTotal(vector<part>& parts, map<char, int>& t, char typ);
string highestCost(vector<part>& parts);
string lowestCost(vector<part>& parts);
void drawMenu();

int main()
{
	//vector<part> parts;
	//map<char, int> typs;
	//string line;
	//readFile(parts, "parts.txt");


	//do
	//{
	//	drawMenu();
	//	getline(cin, line);
	//	string c;
	//	double value;
	//	typeTotals(parts, typs);
	//	cout << "Your choice was " << line << endl;
	//	//handle each choice
	//	switch (line[0])
	//	{
	//	case '1':
	//		cout << "Total cost of inventory is $" << fixed << setprecision(2) << totalInv(parts);
	//		break;
	//	case '2':
	//		cout << "Count of parts by class\n";
	//		for (auto x : typs)
	//		{
	//			cout << x.first << "\t" << x.second << endl;
	//		}
	//		break;
	//	case '3':
	//		cout << "Which class?\n";
	//		getline(cin, c);
	//		value = cCostTotal(parts, typs, c[0]);
	//		if (value != -1)
	//		{
	//			cout << "Cost of inventory for class " << c[0] << " is $" << fixed << setprecision(2) << value << endl;
	//		}
	//		else
	//		{
	//			cout << "Could not find class " << c[0] << ". Return to the menu and try again.\n";
	//		}
	//		break;
	//	case '4':
	//		//I didnt know if you wanted highest per unit cost or total cost so I did the ladder
	//		cout << "The part with the highest cost of inventory is " << highestCost(parts) << endl;
	//		break;
	//	case '5':
	//		cout << "The part with the lowest cost of inventory is " << lowestCost(parts) << endl;
	//		break;
	//	case '6':
	//		cout << "Goodbye\n";
	//		return 1;
	//		break;
	//	default:
	//		cout << line << " is an invalid option please try again.\n";
	//		break;
	//	}
	//	cout << "\nPress enter to return to the menu.\n";
	//	getline(cin, line);
	//} while (true);


	vector<int> V(5);
	for (int i = 0; i < 5; i++)
	{
		V.push_back(i + 3);
	}
	cout << V[5];
}

//struct for each part
struct part
{
	string id;
	char type;
	int quantity;
	double value;

	struct part(string i, char t, int q, double v)
	{
		id = i;
		type = t;
		quantity = q;
		value = v;
	}
};

//Draws the menu
void drawMenu()
{
	system("cls");
	cout << "       R E P O R T S   M E N U         \n";
	cout << "1. Total cost of inventory.\n";
	cout << "2. A count of parts of each class.\n";
	cout << "3. Cost of inventory for a class.\n";
	cout << "4. Part with the highest cost of inventory.\n";
	cout << "5. Part with the lowest cost of inventory.\n";
	cout << "6. Exit.\n";
}

//Reads the file into a vector of part structs
bool readFile(vector<part>& parts, string fileName)
{
	string line;
	ifstream fin(fileName);
	string id;
	char type;
	int quantity;
	double value;
	while (getline(fin, line))
	{
		stringstream ss(line);
		ss >> id >> type >> quantity >> value;
		parts.push_back(part(id, type, quantity, value));
	}
	fin.close();
	return parts.size() > 0;
}
//totals the value of everything in inventory
double totalInv(vector<part>& parts)
{
	double total = 0;
	for (size_t i = 0; i < parts.size(); i++)
	{
		total += parts[i].quantity * parts[i].value;
	}
	return total;
}
//gets quantity of each class and initialize the type map
void typeTotals(vector<part>& parts, map<char, int>& t)
{
	for (size_t i = 0; i < parts.size(); i++)
	{
		if (t.find(parts[i].type) != t.end())
		{
			t[parts[i].type] += parts[i].quantity;
		}
		else
		{
			t.insert({ parts[i].type, parts[i].quantity });
		}
	}
}

//gets total cost of a given type if found if not returns -1
double cCostTotal(vector<part>& parts, map<char, int>& t, char typ)
{
	if (t.find(typ) == t.end()) return -1;

	double totCost = 0;
	for (size_t i = 0; i < parts.size(); i++)
	{
		if (parts[i].type == typ)totCost += parts[i].quantity * parts[i].value;
	}
	return totCost;
}

//gets part id with the highest cost
string highestCost(vector<part>& parts)
{
	double max = DBL_MIN;
	string c;

	for (size_t i = 0; i < parts.size(); i++)
	{
		if (parts[i].quantity * parts[i].value > max) c = parts[i].id;
	}

	return c;
}
//gets part id with the lowest cost
string lowestCost(vector<part>& parts)
{
	double min = DBL_MAX;
	string c;
	for (size_t i = 0; i < parts.size(); i++)
	{
		if (parts[i].quantity * parts[i].value < min) c = parts[i].id;
	}
	return c;
}


//all outputs were tested from fresh start to test them working 
//individually
/*
	   R E P O R T S   M E N U
1. Total cost of inventory.
2. A count of parts of each class.
3. Cost of inventory for a class.
4. Part with the highest cost of inventory.
5. Part with the lowest cost of inventory.
6. Exit.
1
Your choice was 1
Total cost of inventory is $342965.70
Press enter to return to the menu.


	   R E P O R T S   M E N U
1. Total cost of inventory.
2. A count of parts of each class.
3. Cost of inventory for a class.
4. Part with the highest cost of inventory.
5. Part with the lowest cost of inventory.
6. Exit.
2
Your choice was 2
Count of parts by class
A       2265
B       1744
C       2167
D       1448
E       137
F       137

Press enter to return to the menu.

//Testing what happens if it cant find the class
	   R E P O R T S   M E N U
1. Total cost of inventory.
2. A count of parts of each class.
3. Cost of inventory for a class.
4. Part with the highest cost of inventory.
5. Part with the lowest cost of inventory.
6. Exit.
3
Your choice was 3
Which class?
N
Could not find class N. Return to the menu and try again.

	   R E P O R T S   M E N U
1. Total cost of inventory.
2. A count of parts of each class.
3. Cost of inventory for a class.
4. Part with the highest cost of inventory.
5. Part with the lowest cost of inventory.
6. Exit.
3
Your choice was 3
Which class?
A
Cost of inventory for class A is $191180.07

Press enter to return to the menu.

	   R E P O R T S   M E N U
1. Total cost of inventory.
2. A count of parts of each class.
3. Cost of inventory for a class.
4. Part with the highest cost of inventory.
5. Part with the lowest cost of inventory.
6. Exit.
4
Your choice was 4
The part with the highest cost of inventory is P-43672

	   R E P O R T S   M E N U
1. Total cost of inventory.
2. A count of parts of each class.
3. Cost of inventory for a class.
4. Part with the highest cost of inventory.
5. Part with the lowest cost of inventory.
6. Exit.
5
Your choice was 5
The part with the lowest cost of inventory is P-43672

Press enter to return to the menu.
*/