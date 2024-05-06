//Author    :   James P Wolfley
//Class     :   CMPSC 121
//Purpose   :	Produces a report on a file by reading in a structured text file and parsing the data
//Sources of logic assistance: None

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    //Setting up everything I will be using
    ifstream parts("FleetInput.txt");
    string line, str;
    int colW = 10;
    int count = 0;
    float curMiles = 0;
    float curGallons = 0;
    float curMPG = 0;
    float totalMiles = 0;
    float totalMPG = 0;
    string vSMax, vSMin, tempV;
    float vMin = std::numeric_limits<float>::max();
    float vMax = std::numeric_limits<float>::min();


    //Setting up cout
    cout << fixed << setprecision(2) << right;
    //printing the headers
    cout << "AMSCO Fleet Report\n";
    cout << setw(colW) << "Vehicle ID" << setw(colW) << "Miles" << setw(colW) << "Gallons" << setw(colW) << "MPG" << endl;
    cout << "----------------------------------------\n";

    //This loop gets a line and then moves that line into a string stream to parse using getline's delimeter option to 'pop' strings off the front of the stream.
    while (getline(parts, line)) {

        stringstream lineStream(line);

        //Their is likely a better way to do this but my prefered way involves
        //arrays so I'll do the old and trusty till I have optimization restraints.
        //Definetly some shenanigens going on with various whitespaces making the delimiting characters
        //not always the same. ctrl-r + ctrl-w is a friend when navigating these waters.
        //Dirty input data is the worst and I usually just make a script to 
        //clean it before inputing into something.
        getline(lineStream, str, ' ');
        cout << setw(colW) << str;
        tempV = str;
        getline(lineStream, str, ' ');

        do
        {
            getline(lineStream, str, ' ');
        } while (str == " ");
        curMiles = stof(str);
        cout << setw(colW) << str;

        do
        {
            getline(lineStream, str, ' ');
        } while (str == " " || str == "");
        curGallons = stof(str);

        //Handle all my statistics here
        curMPG = curMiles / curGallons;
        totalMiles += curMiles;
        totalMPG += curMPG;
        count++;
        if (curMPG < vMin)
        {
            vMin = curMPG;
            vSMin = tempV;
        }
        if (curMPG > vMax)
        {
            vMax = curMPG;
            vSMax = tempV;
        }

        cout << setw(colW) << str << setw(colW) << curMiles/curGallons << endl;
        
    }

    //Tabs can be pretty useful for quick orginizing but isnt always the most robust.
    //Outputing the footer info
    cout << "----------------------------------------\n";
    cout << "Count:\t\t\t\t" << count << endl;
    cout << "Total Miles:\t\t\t" << totalMiles << endl;
    cout << "Average MPG:\t\t\t" << totalMPG / count << endl;
    cout << "Vehicle ID with Best MPG:\t" << vSMax << "  " << vMax << endl;
    cout << "Vehicle ID with Worst MPG:\t" << vSMin << "  " << vMin << endl;

    
}

/*
AMSCO Fleet Report
Vehicle ID     Miles   Gallons       MPG
----------------------------------------
279BX6KY2Z     582.2      20.5     28.40
802MX8BZ4Q     723.6      25.1     28.83
671AY6DZ3N     756.9      27.5     27.52
845DH6AJ3B     660.2      25.4     25.99
566GJ6KV2U     510.2      30.8     16.56
109QW2RP2Y     301.2       8.3     36.29
135TR4YC6H     387.6      12.2     31.77
122AC6UG7P     228.9      14.7     15.57
136VW8TD2Z     331.2      19.1     17.34
448WQ2DX1M     543.9      33.6     16.19
721GZ1LJ5N     629.8      27.9     22.57
779FS3MB4Y     651.2      28.4     22.93
553SB5LK8O     444.4      26.8     16.58
----------------------------------------
Count:                          13
Total Miles:                    6751.30
Average MPG:                    23.58
Vehicle ID with Best MPG:       109QW2RP2Y  36.29
Vehicle ID with Worst MPG:      122AC6UG7P  15.57
*/