// Justin Murillo
// CSCI 2270 Assignment 1 redo
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

// Program reads up to 100 numbers from a file
// Insert them into an array in ascending order

void printSortedArray(int sortedArray[], int numEntries)
{
    for (int i = 0; i < numEntries; i++)
    {
        cout << sortedArray[i] << ", " ;
    }
    cout << endl;
    cout << sortedArray[0];
}

int insertIntoSortedArray(int myArray[], int numEntries, int newValue)
{
    // Inserts the number into the array at the end of the array
    myArray[numEntries] = newValue;

    // Bubble sort to reorganize the list of numbers
    for(int i = 0; i < numEntries; i++)
    {
        for(int j = 0; j < numEntries - i - 1; j++)
        {
            //swap (arr[j] and arr[j+1])
            if (myArray[j] > myArray[j+1])
            {
                int temp = myArray[j];
                myArray[j] = myArray[j+1];
                myArray[j+1] = temp;
            }
        }
    }
    return ++numEntries;
}



int main(int argc, char* argv[])
{
    if (argc > 2 || argc < 2)
    {
        cout << "Invalid Number of Arguments." << endl;
        return 0;
    }
    ifstream inFile(argv[1]);
    int arr[100];
    int numEntries = 0;
    int newValue = 0;
    string temp;
    if (!inFile.is_open())
    {
        cout << "Failed to open the file\n";
        return 0;
    }
    else
    {
        cout << "File opened" << endl;
    }

    cout << "Now displaying \"filename\" ..." << endl;
    while (!inFile.eof())
    {
        getline(inFile, temp);
        stringstream convert(temp);
        if ( !(convert >> newValue) )
        {
            break;
        }
        cout << newValue << endl;
        insertIntoSortedArray(arr, numEntries, newValue);
    }
    inFile.close();
    cout << "Now printing sorted Array: " << endl;
    cout << "Total number of entries is " << numEntries << endl;
    printSortedArray(arr, numEntries);

    return 0;
}
