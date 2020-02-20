//Justin Murillo
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct wordItem
{
    string word;
    int count;  //number of words in the text file
};

bool test_file(const char* filename)
{
  ifstream ifile(filename);
  ifile.close();
  return ifile.good();
}

int parse(string filename, wordItem* wordArray, int &capacity)
{
  //reads the textfile and dumps it all into an array
  ifstream ifile(filename);
  string read;
  int resizeCount;
  while(!ifile.eof())
  {
  //  if (wordCount > capacity)
    // {
      int newCapacity = capacity * 2;
      cout<<"Resizing from "<<capacity<<" to "<<newCapacity<<endl;

      int *newArray = new int[newCapacity];



      resizeCount++;
    // }
  }
  //return number of times array was doubled
  ifile.close();
}

void getStopWords(const char *ignoreWordFileName, string ignoreWords[])
{
  //do stuff
}

bool isStopWord(string word, string ignoreWords[])
{
  //do stuff
}

int getTotalNumberNonStopWords(wordItem uniqueWords[], int length)
{
  //do stuff
}

void arraySort(wordItem uniqueWords[], int length)
{
  //do stuff
}

void printNext10(wordItem wordItemList[], int startRank, int totalWords)
{
  //do stuff
}

int main(int argc, char* argv[])
{
/**
  Takes 3 arguements
  number n
  name of the text to be read
  name of text file w/ words that should be ignored
  reads text file and stores unique words in dynamic array


  Program prints the following:

  Number of time array doubling occured
  Number of unique "non-ignore" words in the file
  Total word count of  the file excluding ignore words
  Starting from index N print the 10 most frequent words
  and print the probability of occurence from array
  Array should be sorted in decreasing manner based on probability

**/
  wordItem structArray[100];

  char *s = argv[1];
  int n = atoi(s);
  int array = 0;
  if (argc < 2)
  {
    cout << "not enough arguments";
  }
  if (test_file(argv[2]) == true && test_file(argv[3]) == true)
  {
    ifstream textFile(argv[2]);
    ifstream ignoreFile(argv[3]);
  }
  else if (test_file(argv[2]) == true)
  {
    cout << "Text file not found";
  }
  else if (test_file(argv[3]) == true)
  {
    cout << "Ignore file not found";
  }
  else
  {
    cout << "Please enter both text file and ignore file";
  }

  return 0;
}
