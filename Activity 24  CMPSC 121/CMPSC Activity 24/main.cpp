//Author    :   James P Wolfley
//Class     :   CMPSC 121
//Purpose   :	Determine the number of cells in a vector that contains the same value as the same cell in a different vector.
//Sources of logic assistance: None

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

struct VecPair 
{
    int index = 0;
    int value = 0;

    struct VecPair(int i, int v)
    {
        index = i;
        value = v;
    }
};

int testEven(vector<int>& v1, vector<int>& v2, vector<VecPair>& v3)
{
    int numEven=0;
    for (int i = 0; i < v1.size(); i++)
    {
        if (v1[i] == v2[i])
        {
            numEven++;
            cout << setw(4) << i;
            VecPair vp = VecPair(i, v1[i]);
            v3.push_back(vp);
        }
        else
        {
            cout << "    ";
        }
        if (i % 25 == 0)cout << endl;
    }
    cout << endl;
    return numEven;
}

int main()
{
    const int SIZE = 500;
    vector<int> v1(SIZE);
    vector<int> v2(SIZE);
    vector<VecPair> vecPair;
    
    

    srand(time(NULL));
    for (int i = 0; i < v1.size(); i++)
    {
        v1[i] = rand() % 100 + 1;
        v2[i] = rand() % 100 + 1;
    }

    cout << "The Vectors contain " << testEven(v1, v2, vecPair) << " cells where both values are even.\n";
    cout << "The following is a list of the indexs of duplicates and their value.\n";
    cout << setw(4) << right << "index" << "," << setw(4) << "value" << "\n";
    for (int i = 0; i < vecPair.size(); i++)
    {
        cout << setw(5) << right << vecPair[i].index << "," << setw(5) <<vecPair[i].value << "\n";
    }



}

/* The console outputs a grid of 25 wide  that only prints the values that were the same in both arrays. I also tracked them
* and added them to a list to print at the end.




                                                      89







                                                                         294






             454                                                                 471

The Vectors contain 4 cells where both values are even.
The following is a list of the indexs of duplicates and their value.
index,value
   89,   53
  294,   69
  454,   69
  471,   88
*/