#include <iostream>

struct Node{
      int key;
      Node *next;
};

class HashTable
{
private:
    int tableSize;  // No. of buckets (linked lists)
    const int TABLE_SIZE = 10009;
    // Pointer to an array containing buckets
    Node* *table;
    Node* createNode(int key, Node* next);
    int numElements;
public:
    HashTable();  // Constructor
    HashTable(int tableSize);
    // controls how each key will be  inserted into the hash table
    // measures things like load factor and how many times specific insertion method was used
    // inserts a key into hash table different methods.
    void insertItemLLChain(int key);
    // removes key from the table
    bool deleteItem(int key);

    // hash function to map values to key
    unsigned int hashFunction(int key);

    // secondary hash function for cuckoo hashing
    unsigned int hashFunction2(int key);

    void printHashTableLL();

    Node* Lookup(int key);

    // linear probing method to check hash collisions
    int linearProbe();

    // completely rebuilds the hash table
    void rehash();

    double loadFactor();
};
