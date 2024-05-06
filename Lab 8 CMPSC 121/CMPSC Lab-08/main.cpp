//Author    :   James P Wolfley
//Class     :   CMPSC 121
//Purpose   :	calculate batting average given weight averages.
//Sources of logic assistance: None

#include <iostream>
#include <iomanip>

using namespace std;


int batterResult() {
	//gets a number between 0 and 100 by normalizing the random output
	double r = 100 * (double)rand() / RAND_MAX;


	//spit a number out depending on the result of r you can chain ifs like this because of the returns
	if (r < 58)return 0;
	if (r < 67.7)return 1;
	if (r < 89.7)return 2;
	if (r < 95.8)return 3;
	if (r < 98.3)return 4;
	return 5;
}


int main()
{
	char userIn;

	//Capture the user with this do while loop
	do
	{
		int outs = 0, walk = 0, single = 0, dbl = 0, triple = 0, homeRun = 0;
		//For good measure seed rand with something
		srand(time(NULL));
		// run the weighted randomization function to determine an outcome and tally it
		for (int i = 0; i < 1000; i++)
		{
			switch (batterResult())
			{
			case 0:
				outs++;
				break;
			case 1:
				walk++;
				break;
			case 2:
				single++;
				break;
			case 3:
				dbl++;
				break;
			case 4:
				triple++;
				break;
			case 5:
				homeRun++;
				break;
			}
		}

		//display to user
		cout << "Outs            " << outs << endl;
		cout << "Walks           " << walk << endl;
		cout << "Singles         " << single << endl;
		cout << "Doubles         " << dbl << endl;
		cout << "Triples         " << triple << endl;
		cout << "Home Runs       " << homeRun << endl;
		cout << "Batting Average " << (single + dbl + triple + homeRun) / (1000 - walk) << endl;




		cout << "Would you like to do it again? Y or N\n";
		cin >> userIn;
	} while (userIn != 'N');
}

/*
Outs            589
Walks           99
Singles         224
Doubles         50
Triples         26
Home Runs       12
Batting Average 0
Would you like to do it again? Y or N
Y
Outs            613
Walks           92
Singles         207
Doubles         51
Triples         18
Home Runs       19
Batting Average 0
Would you like to do it again? Y or N
Y
Outs            577
Walks           87
Singles         247
Doubles         53
Triples         23
Home Runs       13
Batting Average 0
Would you like to do it again? Y or N
N
*/