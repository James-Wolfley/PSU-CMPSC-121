//Author    :   James P Wolfley
//Class     :   CMPSC 121
//Purpose   :	Calculate a table of wind chill values with various temperatures and wind speeds.
//Sources of logic assistance: None

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int columnWidth = 7;
	double currentTemp = 0;
	int currentWindSpeedDisplay = 0;
	double windMath = 0;
	cout << setprecision(1) << fixed << right;
	cout << "   Temp" << " : ---------------------- Wind Speed --------------------------\n";
	for (int j = 1; j < 14; j++)
	{
		for (int i = 1; i < 11; i++)
		{
			currentWindSpeedDisplay = (i - 1) * 5;
			currentTemp = double(j - 1) * 5 - 10;
			windMath = pow(currentWindSpeedDisplay, 0.16);
			if (i == 1 && j == 1)
			{
				cout << setw(columnWidth) << "";
			}
			else if ( j == 1)
			{
				cout << setw(columnWidth) << currentWindSpeedDisplay;
			}
			else if (i == 1)
			{
				cout << setw(columnWidth) << currentTemp;
			}
			else
			{
				cout << setw(columnWidth) << (35.74+0.6215*currentTemp)-35.75*windMath + 0.4275 * currentTemp * windMath;
			}
		}
		cout << endl;
	}
}


/*
   Temp : ---------------------- Wind Speed --------------------------
			 5     10     15     20     25     30     35     40     45
   -5.0  -16.4  -22.1  -25.8  -28.6  -30.8  -32.7  -34.3  -35.7  -37.0
	0.0  -10.5  -15.9  -19.4  -22.0  -24.1  -25.9  -27.4  -28.8  -30.0
	5.0   -4.6   -9.7  -13.0  -15.4  -17.4  -19.1  -20.5  -21.8  -23.0
   10.0    1.2   -3.5   -6.6   -8.9  -10.7  -12.3  -13.6  -14.8  -15.9
   15.0    7.1    2.7   -0.2   -2.3   -4.0   -5.5   -6.8   -7.9   -8.9
   20.0   13.0    8.9    6.2    4.2    2.6    1.3    0.1   -0.9   -1.8
   25.0   18.9   15.1   12.6   10.8    9.3    8.1    7.0    6.1    5.2
   30.0   24.7   21.2   19.0   17.4   16.0   14.9   13.9   13.0   12.2
   35.0   30.6   27.4   25.4   23.9   22.7   21.7   20.8   20.0   19.3
   40.0   36.5   33.6   31.8   30.5   29.4   28.5   27.7   26.9   26.3
   45.0   42.3   39.8   38.2   37.0   36.1   35.3   34.5   33.9   33.3
   50.0   48.2   46.0   44.6   43.6   42.8   42.0   41.4   40.9   40.4
*/