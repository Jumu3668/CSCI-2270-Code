#ifndef CUCKOO_HPP
#define CUCKOO_HPP
#define TABLE_SIZE 10009


using namespace std;

struct node
{
    int key;
    struct node* next;
    struct node* left;
    struct node* right;
};

class HashTable
{
private:
    int tableSize;  // No. of buckets (linked lists)

    // Pointer to an array containing buckets
    node* *table;

    node* createNode(int key, node* next);
public:
    HashTable();  // Constructor

    // controls how each key will be  inserted into the hash table
    // measures things like load factor and how many times specific insertion method was used
    bool insertController();

    // inserts a key into hash table different methods.
    bool insertItemLLChain(int key);
    bool insertItemBSTChain(int key);
    bool insertItemLinearP(int key);
    bool insertItemCuckoo(int key);
    // removes key from the table
    void deleteItem(int key);

    // hash function to map values to key
    unsigned int hashFunction(int key);

    // secondary hash function for cuckoo hashing
    unsigned int hashFunction2(int key);

    void printTable();

    node* Lookup(int key);

    // linear probing method to check hash collisions
    int linearProbe();

    // completely rebuilds the hash table
    void rehash();

};

#endif
