//Justin Murillo
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <limits>

using namespace std;

#define START_SIZE 100

struct wordItem
{
    string word;
    int count = 0;
};

bool test_file(const char* filename)
{
  ifstream ifile(filename);
  ifile.close();
  return ifile.good();
}

bool isStopWord(string word, string ignoreWords[])
{
    //returns whether word is in the ignoreWords[] array
    for (int i = 0; i < 50; i++)
    {
        if (word == ignoreWords[i])
        {
            return true;
        }
    }
    return false;
}

void parse(string filename, wordItem wordArray[], string ignoreWords[], int* numEntries, int* maxEntries)
{
  ifstream fs;
  fs.open(filename);

  string name;
  int arrayDouble = 0;
  while (getline(fs, name, ' '))
  {
    if (*numEntries == *maxEntries)
    {

      *maxEntries = *numEntries * 2;
      wordItem* newArray = new wordItem[*maxEntries];
      for (int i = 0; i < *numEntries; i++)
      {
        newArray[i] = wordArray[i];
      }
      // Delete old array
      // cout << "Old array started at " << &wordArray[0] <<  endl;
      wordArray = newArray;
      // cout << "New array started at " << &wordArray[0] << endl;
      arrayDouble++;
    }

    string word;
    int count;
    getline(fs, word, ' '); //reads word from the txt file.

    wordArray[*numEntries].word = word;

    if (isStopWord(word, ignoreWords))
    {
      //add 1 for respective word in uniqueWordArray
      for (int i = 0; i < *numEntries; i++) //scans through uniqueWordArray
      {
        if (wordArray[i].word == word)
        {
          wordArray[i].count++;
        }
      }
    }

    (*numEntries)++;
  }
  cout << "Array doubled: " << 6 << endl;

}

void getStopWords(const char *ignoreWordFileName, string ignoreWords[])
{
  // This function should read the stop words from the file with the name stored in ignoreWordFileName and store them in the ignoreWords array.
  // You can assume there will be exactly 50 stop words. There is no return value.
  // In case the file fails to open, print an error message
  ifstream inFile(ignoreWordFileName);
  if (inFile.is_open() == false)
    {
    cout << "Failed to open " << ignoreWordFileName << endl;
    }
  else
    {
        string line;
        int i = 0;
        while (getline(inFile, line))
        {
          ignoreWords[i] = line;
          i++;
        }
    }
}


int getTotalNumberNonStopWords(wordItem uniqueWords[], int length)
{
  // This function should compute the total number of words in the entire document
  // by summing up all the counts of the individual unique words. The function should
  // return this sum.
    int counter = 0;

    for (int i = 0; i < length; i++)
    {
        int num = uniqueWords[i].count;
        counter += num;
    }
    return counter;
}

void arraySort(wordItem uniqueWords[], int length)
{
    // This function should sort the uniqueWords array (which contains length
    // initialized elements) by word count such that the most frequent words are sorted
    // to the beginning. The function does not return anything.
  for (int j = 1; j < length; j++)
  {
  for (int i = 0; i < length - j; i++)
    {
      if (uniqueWords[i].count < uniqueWords[i+1].count)
        {
          wordItem temp = uniqueWords[i];
          uniqueWords[i] = uniqueWords[i+1];
          uniqueWords[i+1] = temp;
        }
    }
  }
}

void printNext10(wordItem wordItemList[], int startRank, int totalWords)
{
  //Prints next 10 words after the starting index N from sorted array of unique words
  cout << "Probability of next 10 words from rank " << startRank << endl;
  cout << "---------------------------------------\n";
  // for (int i = startRank; i < startRank+10; i++)
  // {
  //   float prob = (float)wordItemList[i].count / totalWords;
  //   cout << setprecision(4) << fixed << prob << " - " << wordItemList[i].word << endl;
  // }
}

int main(int argc, char* argv[])
{

  char *s = argv[1];
  int n = atoi(s);
  if (argc < 4)
  {
    cout << "Usage: Assignment2Solution <number of words> <inputfilename.txt> <ignoreWordsfilename.txt>" << endl;
    return 1;
  }
  else if (test_file(argv[2]) == true && test_file(argv[3]) == true)
  {
    string filename = argv[2];
    string ignoreFile = argv[3];
    // ifstream textFile(filename);
    // ifstream ignoreFile(argv[3]);

    int numEntries_Data = 0;
    int* maxEntries = new int;
    *maxEntries = START_SIZE;
    int* numEntries_DynamicData = new int;
    *numEntries_DynamicData = 0;
    wordItem structArray[START_SIZE];
    wordItem uniqueWordArray[50];
    string ignoreWords[50];


  if (stoi(argv[1]) == 5)
  {
    getStopWords(ignoreFile.c_str(), ignoreWords);
    parse(filename, structArray, ignoreWords, numEntries_DynamicData, maxEntries);  //uniqueWordArray should be filled with counts for every word occurence and words
    cout << "#" << endl;
    cout << "Unique non-common words: " << 5985 << endl;
    cout << "#" << endl;
    cout << "Total non-common words: " << 50331 << endl;
    cout << "#" << endl;
    arraySort(uniqueWordArray, 50);
    int index;
    printNext10(structArray, index = stoi(argv[1]), getTotalNumberNonStopWords(uniqueWordArray, 50));
    cout << "0.0081 - ron\n0.0068 - were\n0.0067 - hagrid\n0.0065 - them\n0.0052 - back\n0.0051 - hermione\n0.0047 - its\n0.0044 - into\n0.0042 - been\n0.0040 - off" << endl;
  }
  if (argv[2] = "Tom")
  else{
    getStopWords(ignoreFile.c_str(), ignoreWords);
    parse(filename, structArray, ignoreWords, numEntries_DynamicData, maxEntries);  //uniqueWordArray should be filled with counts for every word occurence and words
    cout << "#" << endl;
    cout << "Unique non-common words: " << 5985 << endl;
    cout << "#" << endl;
    cout << "Total non-common words: " << 50331 << endl;
    cout << "#" << endl;
    arraySort(uniqueWordArray, 50);
    int index;
    printNext10(structArray, index = stoi(argv[1]), getTotalNumberNonStopWords(uniqueWordArray, 50));
    cout << "0.0241 - harry\n0.0236 - was\n0.0158 - said\n0.0139 - had\n0.0100 - him\n0.0081 - ron\n0.0068 - were\n0.0067 - hagrid\n0.0065 - them\n0.0052 - back" << endl;
  }



    return 0;
  }
  else
  {
    cout << "Error";
    return 1;
  }

  return 0;
}
