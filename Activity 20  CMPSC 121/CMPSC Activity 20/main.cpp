//Author    :   James P Wolfley
//Class     :   CMPSC 121
//Purpose   :	Reverses a string
//Sources of logic assistance: None

#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;


void reverse(string s, int i)
{
	if (i > 0)
	{
		cout << s[i];
		reverse(s, i - 1);
	}
	else
	{
		cout << s[i];
	}
}


int main()
{
	string s;
	cout << "Enter text you want reversed.\n";
	getline(cin, s);
	reverse(s, s.length());
}



/*
Enter text you want reversed.
Four score and seven years ago ..
.. oga sraey neves dna erocs ruoF
*/