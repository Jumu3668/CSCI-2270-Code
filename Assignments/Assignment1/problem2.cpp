//Justin Murillo
//problem is that the last thing being printed is the array by itself
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct Park
{
    string parkname;
    string state;
    int area;
};

void addPark (Park parks[], string parkname, string state, int area, int length)
{
  //adds the park struct type to the array
  parks[length].parkname = parkname;
  parks[length].state = state;
  parks[length].area = area;
}

void printList (const Park parks[], int length)
{
  for (int i = 0; i < length; i++)
  {
    cout << parks[i].parkname << " [" << parks[i].state << "] area: " << parks[i].area << endl;
  }
}
int main(int argc, char *argv[])
{
  //Initialize variables
    ifstream inFile(argv[1]);
    Park prk[100];
    string parkData;
    string parkName;
    string parkState;
    int arrayLength = 0;
    int parkArea;
    int minArea;




    if (inFile.is_open())
    while (!inFile.eof())
    {
      getline (inFile, parkData, ',');
      parkName = parkData;
      getline (inFile, parkData, ',');
      parkState = parkData;
      getline (inFile, parkData, '\n');
      stringstream convert(parkData);
      convert >> parkArea;

      addPark (prk, parkName, parkState, parkArea, arrayLength++);
    }
    printList (prk, arrayLength);
    inFile.close();
    ofstream outFile(argv[2]);

    stringstream convert2(argv[3]);
    convert2 >> minArea;
    for (int j = 0; j < arrayLength; j++)
    {
      if (prk[j].area >= minArea)
      {
        outFile << prk[j].parkname << "," << prk[j].state << "," << prk[j].area << endl;
      }
    }
    outFile.close();
}
