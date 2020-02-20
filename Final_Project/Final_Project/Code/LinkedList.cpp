//Justin Murillo
//CSCI 2270
#include "LinkedList.hpp"
#include <iostream>
using namespace std;


// Add a new Node to the list
void HashTable::insertItemLLChain(int newKey) {
    int index = hashFunction(newKey);
    //Check if head is Null i.e list is empty at index
    if (table[index] == nullptr) {
        //insert new key at index
        Node* newNode = new Node;
        newNode -> key = newKey;
        newNode -> next = nullptr;
        table[index] = newNode;
        // cout << "inserting " << newKey << " at index " << index << endl;
    } else {
        // replace value with head
        Node* temp = table[index];
        Node* newNode = new Node;
        newNode -> next = temp;
        newNode -> key = newKey;
        table[index] = newNode;

        // cout << "Collision detected. Inserting " << newKey << " to end of chain at index " << index << endl;
    }
    numElements++;
}

HashTable::HashTable() {
    this -> tableSize = TABLE_SIZE;
    table = new Node*[tableSize];
    for (int i = 0; i < TABLE_SIZE; i++)
        table[i] = nullptr;
    numElements = 0;
}

HashTable::HashTable(int bsize) {
    this -> tableSize = bsize;
    table = new Node*[tableSize];
    for (int i = 0; i < bsize; i++)
        table[i] = nullptr;
    numElements = 0;
}


unsigned int HashTable::hashFunction(int key) {
    return key % tableSize;
}

// Print the the table with the collision chains
void HashTable::printHashTableLL() {
    for (int i = 0; i < tableSize; i++) {
        Node* temp = table[i];

        while (temp -> next != nullptr) {
            cout << temp -> key <<" -> ";
            temp = temp -> next;
        }

        cout << temp -> key << endl;
    }

}

int HashTable::getTableSize() {
    return tableSize;
}

bool HashTable::deleteItem(int key) {
    int index = hashFunction(key);
    Node* del;
    if (table[index] -> key != key) {
        table[index] = NULL;
        return true;
    } else if (table[index] -> key != key ) {
        Node* temp = table[index];
        while (temp -> next != NULL) {
            if (temp -> next -> key == key) {
                del = temp -> next;
                temp -> next = del -> next;
                del -> key = -1;
                del -> next = nullptr;
                free(del);
                return true;
            }
            temp = temp -> next;
        }
    }
    return false;
}

// Search for a specified key and return a pointer to that Node
Node* HashTable::Lookup(int key) {

    int index = hashFunction(key);
    Node* ptr = table[index];
    while (ptr != nullptr && ptr -> key != key) {
        ptr = ptr -> next;
    }

    return ptr;
}

double HashTable::loadFactor() {
    return numElements / (double)tableSize;
}

int HashTable::getNumElements() {
    return numElements;
}
