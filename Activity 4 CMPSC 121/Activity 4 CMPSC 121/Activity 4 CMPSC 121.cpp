#include <iostream>
#include <iomanip>

using namespace std;


int main()
{
	//conversion formula (F-32)*(5/9)=C
	float fInput1, fInput2, fInput3, fInput4, fInput5;
	float cOutput1, cOutput2, cOutput3, cOutput4, cOutput5;

	cout << "Please enter 5 temperatures in fahrenheit separated by a space. Decimals are allowed.\n";
	cin >> fInput1 >> fInput2 >> fInput3 >> fInput4 >> fInput5;

	cOutput1 = (fInput1 - 32.f) * (5.f / 9.f);
	cOutput2 = (fInput2 - 32.f) * (5.f / 9.f);
	cOutput3 = (fInput3 - 32.f) * (5.f / 9.f);
	cOutput4 = (fInput4 - 32.f) * (5.f / 9.f);
	cOutput5 = (fInput5 - 32.f) * (5.f / 9.f);

	cout << fixed << setprecision(2);

	cout << right << setw(15) << "Fahrenheit" << setw(12) << "Celcius" << endl;
	cout << right << setw(15) << fInput1 << setw(12) << cOutput1 << endl;
	cout << right << setw(15) << fInput2 << setw(12) << cOutput2 << endl;
	cout << right << setw(15) << fInput3 << setw(12) << cOutput3 << endl;
	cout << right << setw(15) << fInput4 << setw(12) << cOutput4 << endl;
	cout << right << setw(15) << fInput5 << setw(12) << cOutput5 << endl;
}



/*
Please enter 5 temperatures in fahrenheit separated by a space. Decimals are allowed.
-999.99 32 98.6 212 999.99
	 Fahrenheit     Celcius
		-999.99     -573.33
		  32.00        0.00
		  98.60       37.00
		 212.00      100.00
		 999.99      537.77
*/