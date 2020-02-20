//billly
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int temp=0;
int i=0;


int insertIntoSortedArray(int myArray[],int numEntries,int newValue){
    myArray[numEntries] = newValue;
    if(myArray[i]>myArray[i+1]){
        temp=myArray[i];
        myArray[i]=myArray[i+1];
        myArray[i+1]=temp;
    }
    return numEntries;
}



int main()
{
    ifstream inFile("numbers.txt");
    int arr[100];
    int numEntries=0;
    int newValue;
    string temp;
    if (!inFile.is_open())
    {
        cout << "Failed to open the file\n";
    }
    else
    {
        cout << "File opened" << endl;
    }


    cout << "Now displaying \"filename\" ..." << endl;
    getline(inFile, temp);
    stringstream convert(temp);
    if ( !(convert >> newValue) )
    {
      newValue = 0;
    }

    cout << newValue << endl;








    inFile.close();
    //return 0;

}
