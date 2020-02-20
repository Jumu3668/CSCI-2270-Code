#include <iostream>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <fstream>
#include <sstream>
#include "BST.hpp"
using namespace std;

int main(int argc, char* argv[]) {

    string filename = "";
    if (argc < 2){
        cout << "Not enough arguments" << endl;
        system("pause");

    } else if (argc > 2) {
        cout << "Too many arguments" << endl;
        system("pause");
    } else {
        ifstream fs;
        filename = argv[1];
        fs.open(filename);
        HashTableBST ht;
        string data;
        double startTime, endTime;
        double execTime;
        cout << "Performance time for TableSize of " << ht.getTableSize() << endl;
        startTime = clock();

        // insert numbers till load factor becomes 0.1
        // then time deleting 100 numbers, inserting another 100 numbers, lookup of 100 numbers.

        while (getline(fs, data, ',') && ht.loadFactor() < 0.1) {
            getline(fs, data, ',');
            ht.insertBST(stoi(data));

        }

        for (int i = 0; i < 100; i++) {
            getline(fs, data, ',');
            ht.insertBST(stoi(data));
        }


        endTime = clock();
        execTime = (double) (endTime - startTime) /CLOCKS_PER_SEC;
        cout << fixed << showpoint;
        cout << setprecision(3);
        cout << "\nexecution time: " << execTime << endl;
        cout << "load factor: " << ht.loadFactor() << endl;
        cout << "number of elements: " << ht.getNumElements() << endl;
        // ht.lookup(random integer);
        // ht.deleteItem(random integer);
        // ht.printHashTableLL();
        // fs.clear();
        // fs.seekg(0, ios::beg);
        // for (int i =0; i < 100; i++) {
        //     getline(fs, data, ',');
        //     ht.lookup(stoi(data));
        // }
        //
        // for (int i = 0; i < 100; i++) {
        //     getline(fs, data, ',');
        //     ht.deleteNode(stoi(data));
        // }
    return 0;
    }
}
