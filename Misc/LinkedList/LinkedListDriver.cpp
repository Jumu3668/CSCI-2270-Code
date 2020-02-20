#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "LinkedList.hpp"

using namespace std;



int main() {

    // cout << "happy midterm!  " << endl;
    //write program that creates linked list of integers
    //and a function that returns true if the number of nodes in
    //the list is even or false if odd

    LinkedList List;

    //create a linked list of integers
    int arrayLength = 71;
    int keys[arrayLength] = {3,-9,2,4,6};


    List.loadList(keys, arrayLength);
    cout << "Integer Array before sorting" << endl;
    List.printList();

    //is the length of the list even or odd?
    List.printThing();

    return 0;
}
