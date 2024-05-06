//Author    :   James P Wolfley
//Class     :   CMPSC 121
//Purpose   :	Reads a file of candidates and generates randoms stats to print to the console.
//Sources of logic assistance: None

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>


using namespace std;

bool readFile(string c[], int& size, string fileName)
{
	ifstream fin(fileName);
	if (!fin) 
	{
		fin.close();
		return false;
	}
	for (int i = 0; i < size; i++)
	{
		getline(fin, c[i]);
		if (c[i] == "")
		{
			size = i;
			fin.close();
			return true;
		}
	}
	fin.close();
	return true;
}

void getVotes(int v[], int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		v[i] = rand() % 23501+1500;
	}
}

void calculatePercents(int v[], double p[], int size)
{
	int tVote = 0;
	for (int i = 0; i < size; i++)
	{
		tVote += v[i];
	}

	for (int i = 0; i < size; i++)
	{
		p[i] = (double)v[i] / (double)tVote * 100;
	}
}

void displayResults(string c[], int v[], double p[], int size)
{
	int mostVotes = INT_MIN;
	int mostVotesIndex = -1;
	cout << "Candidate    " << "Votes    " << "Percent\n";

	for (int i = 0; i < size; i++)
	{
		if (v[i] > mostVotes)
		{
			mostVotes = v[i];
			mostVotesIndex = i;
		}
		cout << fixed << setprecision(2) << left << setw(12) << c[i] << right << setw(6) << v[i] << setw(10) << p[i] << "%\n";
	}

	cout << "\nThe winner is " << c[mostVotesIndex] << " with " << v[mostVotesIndex] << " votes!\n";
}


int main()
{
	const int CAPACITY = 25;
	int size = CAPACITY;
	string candidates[25];
	int votes[25];
	double percent[25];

	if (readFile(candidates, size, "candidates.txt"))
	{
		getVotes(votes, size);
		calculatePercents(votes, percent, size);
		displayResults(candidates, votes, percent, size);
	}
	else
	{
		cout << "File not found\n";
	}

}


/*
Candidate    Votes    Percent
Rubio        12924      7.17%
Bush          3133      1.74%
Christie      7665      4.25%
Paul          7249      4.02%
O'Malley     17091      9.48%
Cruz          9835      5.46%
Clinton      21409     11.87%
Trump         9790      5.43%
Kasich       14157      7.85%
Sanders       4380      2.43%
Carson        9641      5.35%
Gilmore       2942      1.63%
Fiorina      13561      7.52%
Santorum      8930      4.95%
Huckabee      3181      1.76%
Graham        4956      2.75%
Jindal        2281      1.27%
Walker       21935     12.17%
Perry         5228      2.90%

The winner is Walker with 21935 votes!
*/