#include <iostream>



int* bubbleSort(int myArray[], int numEntries){
    int currentSize = numEntries;
    int holder = 0;

    for (int i = 1; i < currentSize; i++){
        for (int j = 0; j < currentSize - i; j++){

            if (myArray[j] > myArray[j+1]){
                holder = myArray[j+1];
                myArray[j+1] = myArray[j];
                myArray[j] = holder;
            }
        }
    }
    return currentSize;
}

int main(){
    int array[] = {1,5,42,73,3,75,3};

    std::cout << "Unsorted array: {";
    for (int i = 0; i < arrayLength; i++){
        if (i = arrayLength)
            std::cout << array[i];
        else
            std::cout << array[i] << ", ";
    }
    std::cout << "}" << endl;

    std::cout << "Sorted Array: {";
    for (int i = 0; i < arrayLength; i++){
        std::cout << sortedArray[i] << ",";
    }
    std::cout << "}" << endl;
}
