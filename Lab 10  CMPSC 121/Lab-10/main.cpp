//Author    :   James P Wolfley
//Class     :   CMPSC 121
//Purpose   :	Calculates total price of an order of wood
//Sources of logic assistance: None

#include <iostream>
#include <iomanip>

using namespace std;


const double pine = 0.89;
const double fir = 1.09;
const double cedar = 2.26;
const double maple = 4.40;
const double oak = 3.10;



void getData(int& quant, double& thickness, double& width, double& length)
{
	cout << "Enter number of pieces and thickness(inch) width(inch) and length(feet)\n";
	cin >> quant >> thickness >> width >> length;
}

int main()
{

	const string types = "pfcmot";
	char resp;
	double thickness, width, length, total, curPrice;
	int quant;


	do
	{
		total = 0;
	enterItem:
		char type;
		do
		{
			cout << "Enter item: ";
			cin >> type;
			if (types.find(type) == std::string::npos)
			{
				cout << type << " is not a valid type! Reenter.\n";
			}
			//I am doing this cause I cant use arrays as a way of determining if its a valid input. granted strings are essentially just arrays
		} while (types.find(type) == std::string::npos);



		switch (type)
		{
		case 'p':
			getData(quant, thickness, width, length);
			curPrice = pine * thickness * width / 12 * length * quant;
			total += curPrice;
			cout << fixed << setprecision(2) << quant << "  " << thickness << " X " << width << " X " << length << "  Pine, cost: $" << curPrice << endl;
			goto enterItem;
			break;
		case 'f':
			getData(quant, thickness, width, length);
			curPrice = fir * thickness * width / 12 * length * quant;
			total += curPrice;
			cout << fixed << setprecision(2) << quant << "  " << thickness << " X " << width << " X " << length << "  Fir, cost: $" << curPrice << endl;
			goto enterItem;
			break;
		case 'c':
			getData(quant, thickness, width, length);
			curPrice = cedar * thickness * width / 12 * length * quant;
			total += curPrice;
			cout << fixed << setprecision(2) << quant << "  " << thickness << " X " << width << " X " << length << "  Cedar, cost: $" << curPrice << endl;
			goto enterItem;
			break;
		case 'm':
			getData(quant, thickness, width, length);
			curPrice = maple * thickness * width / 12 * length * quant;
			total += curPrice;
			cout << fixed << setprecision(2) << quant << "  " << thickness << " X " << width << " X " << length << "  Maple, cost: $" << curPrice << endl;
			goto enterItem;
			break;
		case 'o':
			getData(quant, thickness, width, length);
			curPrice = oak * thickness * width / 12 * length * quant;
			total += curPrice;
			cout << fixed << setprecision(2) << quant << "  " << thickness << " X " << width << " X " << length << "  Oak, cost: $" << curPrice << endl;
			goto enterItem;
			break;
		case 't':
			cout << fixed << setprecision(2) << "Total cost: $" << total << endl;
			break;
		}

		cout << "More purchases?\n";
		cin >> resp;
	} while (resp == 'y' || resp == 'Y');

}

/*
* Enter item: i
i is not a valid type! Reenter.
Enter item: o
Enter number of pieces and thickness(inch) width(inch) and length(feet)
100 2.5 3 20
100  2.50 X 3.00 X 20.00  Oak, cost: $3875.00
Enter item: p
Enter number of pieces and thickness(inch) width(inch) and length(feet)
150 3 3.5 22
150  3.00 X 3.50 X 22.00  Pine, cost: $2569.88
Enter item: t
Total cost: $6444.88
More purchases?
n
*/

