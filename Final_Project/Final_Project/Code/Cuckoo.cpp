#include <stdio.h>
#include <string>
#include <iostream>
#include "Cuckoo.hpp"
#include <math.h>
#include <iomanip>

int TABLE_SIZE = 100;

HashTableCuckoo::HashTableCuckoo(){
    for(int i=0;i<TABLE_SIZE;i++){
        table[i] = -1;
    }
}

int HashTableCuckoo::hashFunction(int key){
    int hashVal = key % TABLE_SIZE;
    //cout << key << " " << hashVal;
    //cout << hashVal << endl;
    return hashVal;
}

int HashTableCuckoo::hashFunction2(int key){
    int hashVal2 = (int)(floor((key/TABLE_SIZE)%TABLE_SIZE));
    //cout << "HASHVAL2" << hashVal2 << endl;
    return hashVal2;
}


int HashTableCuckoo::lookupCuckoo(int key)
{
    //Compute the index by using the hash function
    int index = hashFunction(key);
    if(table[index] == key){
        cout << "key exists at index: " << index << endl;
        return index;
    }else if(table[index] != key){
        index = hashFunction2(key);
    }
    if(table[index] == key){
        cout << "key exists at index: " << index << endl;
        return index;
    }else{
        cout << "Item: " << key<<  " doesn't exist" << endl;
        return -1;
    }
}

bool HashTableCuckoo::insertItemCuckoo(int key){
        // TODO :
        // Use the hash function on the key to get the index/slot,
        // create a new node with the key and insert it in this slot's list
        int index = hashFunction(key);
        if(table[index] == -1){
            table[index] = key;
            return true;
        }else if(table[index] != -1){
            index = hashFunction2(key);
            if(table[index] == -1){
                table[index] = key;
                return true;
            }else{
                return false;
            }
        }
        return false;
}

bool HashTableCuckoo::deleteItemCuckoo(int key){
    int index = hashFunction(key);
    if(table[index] == key){
        table[index] = -1;
        cout << "Found key: " << key << " at index: " << index << "  and deleted it" << endl;
        return true;
    }else if(table[index] != key){
        index = hashFunction2(key);
    }
    if(table[index] == key){
        table[index] = -1;
        cout << "Found key: " << key << " at index: " << index << "  and deleted it" << endl;
        return true;
    }else{
        cout << "Key not found, nothing has been deleted" << endl;
        return false;
    }
}

void HashTableCuckoo::printCuckoo()
{
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << "[" << table[i] << "]";
    }
}
