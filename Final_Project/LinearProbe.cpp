#include <iostream>
#include "Hash.hpp"
#include <math.h>
using namespace std;

node* HashTable::createNode(int key, node* next) {
    node* nw = new node;
    nw -> key = key;
    nw -> next = next;
    return nw;
}

HashTable::HashTable () {
    this -> tableSize = TABLE_SIZE;  //new object is created with tablesize the size of TABLE_SIZE
    table = new node*[tableSize];   // node pointer array created called table. Each element set to nullptr
    int tableSize = TABLE_SIZE;
    for (int i = 0; i < tableSize; i++)
        table[i] = nullptr;
}

node* HashTable::Lookup(int key)
{
    //Compute the index by using the hash function
    int index = hashFunction(key);
    if (table[index] != nullptr) {  //if table at index has element, create node pointer at index
        node* n = table[index];
        while (n != nullptr)    //traverse chain until key is found. Return key.
        {
            if (n -> key == key)
            {
                return n;   // returns pointer to where the key is located.
            }
            else
            {
                n = n -> next;
            }
        }
    }
    else {
        cout << "Collision detected at " << index;
    }
}

void HashTable::insertController(int key) { // needs to determine insertion method
    int LLcounter = 0, BSTcounter = 0, LPcounter = 0, CuCounter = 0;
    while (LLcounter < 100) {
        insertItemLLChain(key);
    }
    cout << "100 LL insertions performed... switching to BST insertion method."
    while (BSTcounter < 100) {
        insertItemBSTChain(key);
    }
    //etc
}

bool HashTable::insertItemLLChain(int key) {   //chaining with linked list
    if (Lookup(key)) {  //if pointer is empty
        int index = hashFunction(key);
        node* n = table[index];
            n -> key = key;
            return true;
        }
    } else {
        // insert via chaining
        while (n) {             //repeat while n is not nullptr
            if (n -> key == key)
                return n;
            else
                n = n -> next;
    }
}

bool HashTable::insertItemBSTChain(int key) {   // possibly have to rebuild the hashtable

}

bool HashTable::insertItemLinearP(int key) {
    // step size = 1
}

bool HashTable::insertItemCuckoo(int key) {

}

unsigned int HashTable::hashFunction(int key) {
    //is the actual function to hash the key
    return (key % TABLE_SIZE);
}

unsigned int HashTable::hashFunction2(int key) {
    return int(floor(key / TABLE_SIZE)) % TABLE_SIZE;
}

void HashTable::printTable() {
    int tableSize = TABLE_SIZE;
    for (int i = 0; i < tableSize; i++) {
        if (table[i] != nullptr) cout << table[i] -> key << " at index " << i;
    }
    cout << endl;
}
