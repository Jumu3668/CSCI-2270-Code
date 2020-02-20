#include "LinkedList.hpp"
#include "BST.hpp"
#include "Cuckoo.hpp"
#include "LinearProbe.hpp"
#include <iostream>
#include <ctime>

using namespace std;
// Implement and compare performance characteristics of hash tables
// Create a hash table with 10009 slots called TABLE_SIZE

// TODO add in code to read the .csv files and insert them into the HashTable

int main() {
    int startTime, endTime;
    double execTime;
    startTime = clock();
    //evaluation code goes here

    //calculate load factor of hash table
    // load factor = number of elements / table.length

    // Linked List Chaining Performance evaulation
    // Insert 100 elements into hash table, then calculate load factor and record performance, and average performance for all functions
    // Then insert another 100 elements

    LinkedList LL;
    endTime = clock();
    execTime = (double) (endTime - startTime) /CLOCKS_PER_SEC;
    cout << "execution time: " << execTime << endl;
    return 0;
}
