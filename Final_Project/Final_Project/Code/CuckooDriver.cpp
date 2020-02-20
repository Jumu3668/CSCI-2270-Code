#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include "Cuckoo.hpp"
#include <math.h>
#include <iomanip>
using namespace std;



int main(int argc, char* argv[]) {
    string filename = "";
    if (argc < 2){
        cout << "Not enough arguments" << endl;
        system("pause");

    } else if (argc > 3) {
        cout << "Too many arguments" << endl;
        system("pause");
    } else {
    HashTableCuckoo ht;
    cout << "TABLE 1" << endl;
    ht.insertItemCuckoo(4);
    ht.insertItemCuckoo(104);
    ht.printCuckoo();
    cout << endl;

    cout << "TABLE  2" << endl;
    ht.deleteItemCuckoo(104);
    ht.printCuckoo();
    ht.lookupCuckoo(4);
    ht.lookupCuckoo(104);



    return 0;
    }
}
