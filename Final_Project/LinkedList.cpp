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
        cout << "inserting " << newKey << " at index " << index << endl;
    } else if (table[index] != nullptr && table[index] -> next == nullptr){
        // if index has value (aka collision) but no chain created, add first value to chain
        Node* newNode = new Node;
        newNode -> key = newKey;
        newNode -> next = nullptr;
        table[index] -> next = newNode;
        cout << "Collision detected. Inserting " << newKey << " at index " << index << endl;
    } else {
        //add value to last linked list node at index in table
        Node* pres = table[index];
        Node* prev = nullptr;
        while (pres -> next != nullptr) {   // loop to end of LL chain
            prev = pres;
            pres = pres -> next;
        }
        Node* newNode = new Node;
        newNode -> key = newKey;
        newNode -> next = nullptr;
        pres -> next = newNode;
        cout << "Collision detected. Inserting " << newKey << " to end of chain at index " << index << endl;
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

// Delete Node given key
bool HashTable::deleteItem(int key) {
    bool isDeleted = false;
    if(!Lookup(key)) {    // if pointer to key exists

    }
    return isDeleted;
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

// Search for a specified key and return a pointer to that Node
Node* HashTable::Lookup(int key) {

    // Node* ptr = head;
    // while (ptr != NULL && ptr->key != key) {
    //     ptr = ptr->next;
    // }
    return nullptr;
}

double HashTable::loadFactor() {
    return numElements / tableSize;
}
