// Hash class file
#ifndef CUCKOO_HPP
#define CUCKOO_HPP

#include <string>


using namespace std;



class HashTableCuckoo
{
    int TABLE_SIZE = 100;  // No. of buckets (linked lists)

    int table[100];

public:
    HashTableCuckoo();  // Constructor
    bool insertItemCuckoo(int key);
    bool deleteItemCuckoo(int key);
    int lookupCuckoo(int key);
    
    int hashFunction(int key);
    int hashFunction2(int key);
    void printCuckoo();

    


};

#endif
