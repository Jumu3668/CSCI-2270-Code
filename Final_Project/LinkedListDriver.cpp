#include "LinkedList.hpp"
// #include "BST.hpp"
// #include "Cuckoo.hpp"
// #include "LinearProbe.hpp"
#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
// Implement and compare performance characteristics of hash tables
// Create a hash table with 10009 slots called TABLE_SIZE


int main(int argc, char* argv[]) {

    string filename = "";
    if (argc < 2){
        cout << "Not enough arguments" << endl;
        system("pause");

    }else if (argc > 2) {
        cout << "Too many arguments" << endl;
        system("pause");
    }else {
        ifstream fs;
        filename = argv[1];
        fs.open(filename);
        HashTable ht;
        string data;
        int startTime, endTime;
        double execTime;
        cout << "Performance time for TableSize of 40" << endl;
        startTime = clock();


        // insert numbers till load factor becomes 0.1
        // then time deleting 100 numbers, inserting another 100 numbers, lookup of 100 numbers.

        while (getline(fs, data, ',')) {
            getline(fs, data, ',');
            ht.insertItemLLChain(stoi(data));

        }

        endTime = clock();
        execTime = (double) (endTime - startTime) /CLOCKS_PER_SEC;
        cout << "\nexecution time: " << execTime << endl;
        cout << "load factor: " << ht.loadFactor() << endl;
        // ht.lookup(random integer);
        // ht.deleteItem(random integer);
        // ht.printHashTableLL();
        return 0;
    }
}
