// Hash class file
#ifndef LINEARPROBE_HPP
#define LINEARPROBE_HPP

#include <string>
using namespace std;



class HashTableLinear
{
    //int table[100];
    
const int TABLE_SIZE = 10009;
int table_size;


public:
    int* table;
    HashTableLinear();
    bool insertItemLinearProbe(int key);
    bool deleteItemLinearProbe(int key);
    int lookUpLinearProbe(int key);

    int hashFunction(int key);
    int hashFunction2(int key);
    void printTableLinearProbe();


};

#endif
