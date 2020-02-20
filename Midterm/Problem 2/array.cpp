#include<iostream>
#include<string>
using namespace std;

/*
// Split 'arr' into 'even_arr' & 'odd_arr'
//  - 'arr': pointer to original array
//  - 'even_arr': pointer to even array
//  - 'odd_arr': pointer to odd array
*/
void split(int* &arr, int* &even_arr, int* &odd_arr, int size, int &even_size, int &odd_size)
{
	//Implement this function
    //this funciton sorts original array into the two other arrays given
    int even_count = 0, odd_count = 0;
    for (int i = 0; i < size; i ++) //loop continues for entire length of orig array
    {
        if (arr[i] % 2==0)  //if even
        {
            //put into even array
            if (even_count > even_size)     //doubles even array size if the count of even numbers is greater than the even_array size
            {
                even_size = even_size * 2;
                int *temp = even_arr;        //store pointer to orignal array
                even_arr = new int[even_size];  //declare to new memory larger array and have arr point to it

                //copy over all info from original array to new array
                for (int i = 0; i < size; i ++)
                {
                    even_arr[i] = temp[i];
                }

                delete temp;
            }
            even_arr[even_count] = arr[i];
            even_count++;
        }
        else
        {
            //put into odd array
            if (odd_count > odd_size)   //doubles odd array size
            {
                odd_size = odd_size * 2;
                int *temp = odd_arr;        //store pointer to orignal array
                odd_arr = new int[odd_size];  //declare to new memory larger array and have arr point to it

                //copy over all info from original array to new array
                for (int i = 0; i < size; i ++)
                {
                    odd_arr[i] = temp[i];
                }

                delete temp;
            }
            odd_arr[odd_count] = arr[i];
            odd_count++;
        }
    }
}

void printArray(int* arr, int size) {
    for(int i = 0; i<size; i++)
    {
        cout<< arr[i];
        if(i < size-1)
          cout << ", ";
    }
    cout<<endl;
}

void doubleArray(int* arr, int size)
//apparently trying to put this funciton into the split
// funciton results in a scope error, so i just copied the guts over
{
    // cout << "array before doubling" << endl;
    // printArray(arr, size);

    int doubleSize = size * 2;
    int *temp = arr;        //store pointer to orignal array
    arr = new int[doubleSize];  //declare to new memory larger array and have arr point to it

    //copy over all info from original array to new array
    for (int i = 0; i < size; i ++)
    {
        arr[i] = temp[i];
    }

    delete temp;
    // cout << "array after doubling" << endl;
    // printArray(arr, doubleSize);
}

int main(int argc, char* argv[])
{
    if(argc<2)
    {
      cout<<"usage: a.out <#>";
      return -1;
    }

	// Create input array:
    int size = stoi(argv[1]);
    int *arr = new int[size];

    cout<< "original array: ";
    for(int i = 0; i<size; i++)
    {
        arr[i] = rand()%100;
        cout<< arr[i];
        if(i < size-1)
          cout << ", ";
    }
    cout<<endl;
    int even_size = 8, odd_size = 8;
    int *odd_arr = new int[odd_size];     //arbitrary length
    int *even_arr = new int[even_size];
    //test array doubling
    // doubleArray(arr, size);
	// Call your function with new arrays:
	split(arr, even_arr, odd_arr, size, even_size, odd_size);

	// Output
    cout << "\neven array: ";
    printArray(even_arr, even_size);
    cout << endl;
    cout << "odd array: ";
    printArray(odd_arr, odd_size);
	// Clean up (delete)
    //delete original array
    // printArray(array);  //should print nothing
    return 0;
}
