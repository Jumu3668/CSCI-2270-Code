//Justin Murillo
//CSCI 2270 Assignment 1

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int numEntries = 0;
int insertIntoSortedArray(int myArray[],int numEntries, int newValue)  //numEntries is first passed as 0
{
  myArray[numEntries] = newValue;
  for (int i = 0; i < numEntries; i++)
  {
    for (int j = i + 1; j < numEntries; j++)
    {
      if (myArray[i] > myArray[j])
      {
        int temp = myArray[i];
        myArray[i] = myArray[j];
        myArray[j] = temp;
      }
    }
  }
  return numEntries;
}




int main(int argc, char* argv[])
{
  ifstream inFile(argv[1]); //opens file called 'filename'
  int n = 0;
  int myArray[100];
  int newValue;
  string temp;

  //cout << ifstream(filename).rdbuf();
  while ( !inFile.eof() ) //puts the contents of 'filename' into myArray
  {
    getline(inFile, temp);
    stringstream convert(temp);
    convert >> newValue;
    numEntries = insertIntoSortedArray( myArray, numEntries, newValue ); //sends to funciton
    for ( int i = 0; i < numEntries; i++ ) //Prints out the current contents of myArray
    {
      cout << myArray[i] << ", ";
    }
    cout << endl;
    numEntries++;

  }
	inFile.close();
  return 0;
}
