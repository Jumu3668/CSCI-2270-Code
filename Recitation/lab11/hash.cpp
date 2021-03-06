// CPP program to implement hashing with chaining
#include<iostream>
#include <list>
#include "hash.hpp"


using namespace std;

node* HashTable::createNode(int key, node* next)
{
    node* nw = new node;
    nw->key = key;
    nw->next = next;
    return nw;
}

HashTable::HashTable(int bsize)
{
    this -> tableSize = bsize;
    table = new node*[tableSize];
    for (int i = 0; i < bsize; i++)
        table[i] = nullptr;
}

//function to calculate hash function
unsigned int HashTable::hashFunction(int key)
{
    return (key % tableSize);
}

// TODO Complete this function
//function to search
node* HashTable::searchItem(int key)
{
    //Compute the index by using the hash function
    int index = hashFunction(key);

    //TODO: Search the list at that specific index and return the node if found
    node* n = table[index];
    while (n != nullptr)
    {
        if (n -> key == key)
        {
            return n;
        }
        else
        {
            n = n -> next;
        }
    }
}

//TODO Complete this function
//function to insert
bool HashTable::insertItem(int key)
{
    if(!searchItem(key))
    {
        // TODO :
        // Use the hash function on the key to get the index/slot,
        // create a new node with the key and insert it in this slot's list

        int index = hashFunction(key);
        node* n = new node;
        n -> key = key;
        n -> next = table[index];
        table[index] = n;

    }
    else{
        cout << "duplicate entry: " << key << endl;
        return false;
    }
}

//TODO Complete this function
// function to display hash table
void HashTable::printTable()
{
    for (int i = 0; i < tableSize; i++) {
        cout << i <<"|| ";

        //TODO
        // print the contents of the hash table
        node * curr = table[i];
        while (curr != nullptr)
        {
            cout << curr -> key;
            curr = curr -> next;
        }
        cout << endl;
    }
 }
