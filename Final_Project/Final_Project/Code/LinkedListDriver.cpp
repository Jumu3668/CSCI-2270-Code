#include "LinkedList.hpp"
#include <iostream>
#include <iomanip>
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

    }else if (argc > 3) {
        cout << "Too many arguments" << endl;
        system("pause");
    }else {
        ifstream fs;
        filename = argv[1];
        int loadF = stoi(argv[2]);
        fs.open(filename);
        HashTable ht;
        string data;
        double startTime, endTime;
        double startTime2, endTime2;
        double execTime, execTime2;
        cout << "Performance time for TableSize of " << ht.getTableSize() << endl;
        startTime = clock();

        // insert numbers till load factor becomes 0.1
        // then time deleting 100 numbers, inserting another 100 numbers, lookup of 100 numbers.

        while (getline(fs, data, ',') && ht.loadFactor() < loadF) {
            getline(fs, data, ',');
            cout << data << " ";
            ht.insertItemLLChain(stoi(data));

        }
        cout << endl;
        fs.clear();
        fs.seekg(0);
        // for (int i = 0; i < 100; i++) {
        //     getline(fs, data, ',');
        //     ht.insertItemLLChain(stoi(data));
        // }

        // for (int i =0; i < 100; i++) {
        //     getline(fs, data, ',');
        //     ht.Lookup(stoi(data));
        // }
        //
        for (int i = 0; i < 100; i++) {
            getline(fs, data, ',');
            cout << data << " ";
            ht.deleteItem(stoi(data));
        }
        cout << endl;
        endTime = clock();
        execTime = (double) (endTime - startTime) /CLOCKS_PER_SEC;
        cout << fixed << showpoint;
        cout << setprecision(3);
        cout << "\nexecution time: " << execTime << endl;
        cout << "load factor: " << ht.loadFactor() << endl;
        cout << "number of elements: " << ht.getNumElements() << endl;
    }
}
