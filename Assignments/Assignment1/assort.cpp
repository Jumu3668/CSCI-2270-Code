#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;


int insertIntoSortedArray(int myArray[], int numEntries, int newValue)
{
    // store the last value in case it is not the new value anymore.
    int replaced;
    // convert size to useable integer
    int ent = abs(numEntries)+1;
    int lastVal = ent-1;
    //store new value in the last space of the array
    myArray[lastVal] = newValue;
  if(newValue < myArray[0])
  {
    myArray[lastVal] = myArray[0];
    myArray[0] = newValue;
    replaced = myArray[lastVal];
  }
    if(ent > 2)h
    {
      for(int comp = lastVal-1; comp >= 0; comp--)
      {
        replaced = myArray[lastVal];
        if(myArray[comp] <= myArray[lastVal]) break;
        else if((myArray[comp-1] < myArray[lastVal]) && (myArray[comp] > myArray[lastVal]))
        {
          for(int push = lastVal-1; push >= comp; push--)
          {
            myArray[push+1] = myArray[push];
          }
          myArray[comp] = replaced;
          break;
        }
      }
    }
    for(int g = 0; g < ent; g++)
    {
      cout << myArray[g];
      if(lastVal >= 1) cout << ',';
      lastVal--;
    }
    cout << endl;
    return ent;
}

int main(int argc, char *argv[])
{
  int array[100];
  int number, val;
  ifstream fin(argv[1]);
  if(fin.is_open())
  {
    string num;
    int stop;
    int i = 0;
    int j = 1;
    while(!fin.eof())
    {
    j--;
    getline(fin, num);
    stringstream to(num);
    to>>number;
    i++;
    val = insertIntoSortedArray(array, j, number);
    }
    cout << val << endl;

  }
  else
  {
    cout<< "Failed to open the file.\n" << endl;
  }
  fin.close();
return 0;
}
