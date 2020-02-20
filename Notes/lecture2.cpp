#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
//vim cmd
using namespace std;

#define file "testfile.txt"
#define START_SIZE 4
//Declare struct

//#define filename "testFile.txt" //makes filename a variable
struct PhoneContact
{
  string name, nickName;    //abstract definitions of variables, therefore no data initialized
  int number;
  bool block;
} globaStruct1, globalStruct2;  // won't use these! declared as a global instance  of globaStruct1

void parse(string filename, PhoneContact* phoneBook, int* numEntries) //be used to parse the phoneBook struct. can also use PhoneContact phonebook[]
{
  // int* numEntries is pass by reference
  //
  ifstream fs;
  fs.open(filename);

  string name;
  while (getline(fs, name, ','))
  {
    if (*numEntries == *maxEntries)
    {
      //Double the array
      //Call Function
      int *maxEntries = *numEntries * 2;
      PhoneContact* newArray = new PhoneContact[&maxEntries];

      //copy old data to the new array
      for (int i = 0; i < *numEntries; i++)
      {
        newArray[i] = phoneBook[i];
      }

      //delete old arrayLength
      delete[] phoneBook;
      phoneBook = newArray;
    }
    //initialize line variables
    string name;
    string nickName;
    int number;
    bool block;

    //populate all the line variables
    getline(fs, line, ',');
    getline(fs, line, ',');
    getline(fs, line, ',');
    getline(fs, line, ',');
    //populate the struct at index "numEntries"
    phoneBook[*numEntries].name = name;
    phoneBook[*numEntries].nickName = nickName;
    phoneBook[*numEntries].number = stoi(number);
    phoneBook[*numEntries].block = stoi(block);
    cout << line << endl;

    (*numEntries)++;  //dereference the value before adding 1 to it
  }

}

int main(int argc, char* argv[])  //int argc tells how many arguments are valid in main
{
  char A[4] = {'H', 'i', '!', '\0'};
  int X[4] = {0,1,2,3};
  PhoneContact localStruct; //declare local instance of PhoneContact
                            //now instantiating struct data
  localStruct.name = "Christopher";
  localStruct.nickName = "Chris";
  localStruct.number = 42;
  localStruct.block = false;

  //cout << *localStruct << endl; //Doesn't work! Cannot dereference a struct. We don't know the first variable in struct
  cout << &localStruct << endl;
  cout << localStruct.name << endl;
  cout << localStruct.nickName << endl;
  cout << localStruct.number << endl;
  cout << localStruct.block << endl;



  // Take in command line arguments
  //string filename = argv[1];  //when running program, accepts argument as the filename
  string filename = "";
  if (argc < 2)                 //checking for number of arguments passed.when passed no arguments, argc = 1
  {
    cout << "Not enough arguments!" << endl;
  }
  else if (argc > 2)
  {
    cout << "Too many arguments!" << endl;
  }
  else
  {
    filename = argv[1];
  }
  string line;



  int numEntries_Data = 0;  //Static destination for numEntries_StaticData onto the STACK
  int* numEntries_StaticData = &numEntries_Data;  // Pointers need data to point to

  int* numEntries_DynamicData = new int;  //Allocates an integer onto the HEAP
  *numEntries_DynamicData = 0;



  PhoneContact phoneBook[5];
  parse(filename, phoneBook, numEntries_DynamicData);
  //Initialize input stream object




  //Test that we filled these in correcrly
  for (int i=0; i< *numEntries_DynamicData; i++)
  {
    cout << phoneBook[i].name << endl;
    cout << phoneBook[i].nickName << endl;
    cout << phoneBook[i].number << endl;
    cout << phoneBook[i].block << endl;
    cout << endl;
  }
  return 0;
}
