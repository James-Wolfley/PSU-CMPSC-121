#include <iostream>

using namespace std;

int main()
{
	int a, b, c, d, e = 0;
	double average = 0.f;
	cout << "Please enter 5 seperate integers seperated by a space.\n";
	cin >> a >> b >> c >> d >> e;
	average = (a + b + c + d + e) / 5.f;

	cout << "The average is " << average << endl;
}




/* Sample Output
Please enter 5 seperate integers seperated by a space.
5 1 1 1 4
The average is 2.4
*/