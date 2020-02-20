#include <iostream>
#include <vector>
using namespace std;

class HashTable {
private:
    // vector<int> table;
    int* table;
    int h(int k);
    int M;
public:
    HashTable();
    int hash(int k);
    void printTable();
    int linearProbe(int k);
};

HashTable::HashTable() {
    //sets the table size to value M
    M = 11;
    table = new int[M];
    for (int i = 0; i < M; i++) {
        table[i] = -1;
    }
}

int HashTable::h(int k) {
    return k % M;   //where M is the size of the hash table
}

int HashTable::linearProbe(int k) {
    for (int i = k+1; i != k; i++){
        if ( i >= M) {      //wrap around
            i = -1;
            continue;
        }
        if (table[i] == -1) return i;
    }
    return -1;
}

int HashTable::hash(int k) {
    int index = h(k);
    if (table[index] >= 0) {
        index = linearProbe(index);
    }
    if (index >= 0) table[index] = k;
    else cout << "Couldnt fit it :(\n";

}

void HashTable::printTable() {
    for (int i = 0; i < M; i++) {
        cout << table[i] << ", ";
    }
    cout << endl;
}

int main() {
    HashTable myTable;
    myTable.hash(10);
    myTable.hash(21);
    myTable.hash(33);
    myTable.hash(43);
    myTable.hash(54);
    // myTable.hash(65);
    // myTable.hash(76);

    myTable.printTable();
    return 0;
}
