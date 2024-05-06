//Author    :   James P Wolfley
//Class     :   CMPSC 121
//Purpose   :	
//Sources of logic assistance: None

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>

using namespace std;

//adds the dashes
string fixName(string n)
{
	string f, l;
	stringstream ss(n);
	getline(ss, f, ' ');
	getline(ss, l, ' ');
	f[0] = toupper(f[0]);
	l[0] = toupper(l[0]);
	return l + "," + f;
}
//adds the dashes
string fixSSN(string ss)
{
	string ns = "555-55-5555";
	//THIS IS ABOUT TO BE DIRTY, prolly not the best way to do this. Might fix later
	ns[0] = ss[0]; ns[1] = ss[1]; ns[2] = ss[2];
	ns[4] = ss[3]; ns[5] = ss[4];
	ns[7] = ss[5]; ns[8] = ss[6]; ns[9] = ss[7]; ns[10] = ss[8];
	return ns;
}
//adds the dashes
string fixPhone(string ph)
{
	string ns = "555-555-5555";
	//THIS IS ABOUT TO BE DIRTY, prolly not the best way to do this. Might fix later
	ns[0] = ph[0]; ns[1] = ph[1]; ns[2] = ph[2];
	ns[4] = ph[3]; ns[5] = ph[4]; ns[6] = ph[5];
	ns[8] = ph[6]; ns[9] = ph[7]; ns[10] = ph[8]; ns[11] = ph[9];
	return ns;
}
//uppercases the first letter of each word
string fixAddress(string addr)
{
	stringstream stream(addr);
	string s, ns;
	while (getline(stream, s, ' '))
	{
		s[0] = toupper(s[0]);
		ns += s + ' ';
	}
	return ns.substr(0, ns.size() - 1);
}
//uppercase the state
string fixCity(string cty)
{
	cty[0] = toupper(cty[0]);
	return cty;
}
//uppercases the whole thing
string fixState(string st)
{
	st[0] = toupper(st[0]);
	st[1] = toupper(st[1]);
	return st;
}
//Essentially an extended version of getline
string extractField(string& s)
{
	stringstream ss(s);
	string ns;
	getline(ss, ns, '#');
	if (ns.length() < s.length())
	{
		s = s.substr(ns.length() + 1, s.length());
	}
	else s = "";
	return ns;
}

int main()
{
	ifstream oldFile;
	ofstream newFile("goodNames.txt");
	string line;
	oldFile.open("badnames.txt");

	while (getline(oldFile, line))
	{
		newFile << fixName(extractField(line)) << ',';
		newFile << fixSSN(extractField(line)) << ',';
		newFile << fixPhone(extractField(line)) << ',';
		newFile << fixAddress(extractField(line)) << ',';
		newFile << fixCity(extractField(line)) << ',';
		newFile << fixState(extractField(line)) << ',';
		newFile << extractField(line) << endl;
	}

	oldFile.close();
	newFile.close();
	cout << "Success";
}

/*
Success
*/