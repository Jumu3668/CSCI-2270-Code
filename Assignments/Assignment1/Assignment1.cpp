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

  if (numEntries == 0)
  {
    myArray[0] = newValue;
  }
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

bool test_file(const char* filename)
{
  ifstream inFile(filename);
  inFile.close();
  return inFile.good();
}



int main(int argc, char* argv[])
{
  int n = 0;
  int myArray[100];
  int newValue;
  string temp;
  if (test_file(argv[1]) == true)
  {
    ifstream inFile(argv[1]);
    while ( !inFile.eof() ) //puts the contents of 'filename' into myArray
    {
      getline(inFile, temp);
      stringstream convert(temp);
      convert >> newValue;
      numEntries = insertIntoSortedArray( myArray, numEntries, newValue ); //sends to funciton
      for ( int i = 0; i < numEntries; i++ ) //Prints out the current contents of myArray
      {
        if (i == numEntries - 1)
        {
          cout << myArray[i];
        }
        else
        {
          cout << myArray[i] << ",";
        }
      }
      if (numEntries != 0)
      {
          cout << endl;
      }

      numEntries++;

  }
  inFile.close();
}
  else
  {
    cout << "Failed to open the file.";
  }


  return 0;
}
