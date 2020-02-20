#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include "LinearProbe.hpp"
#include <math.h>
#include <iomanip>


int TABLE_SIZE = 10009;

HashTableLinear::HashTableLinear(){
    this -> table_size = TABLE_SIZE;
    table = new int[table_size];
    for(int i=0;i<TABLE_SIZE;i++){
        //cout << "loop" << endl;
        table[i] = -1;
    }
    //cout << "LOOP DONE" << endl;
}

int HashTableLinear::hashFunction(int key){
    int hashVal = key % TABLE_SIZE;
    //cout << key << " " << hashVal;
    //cout << hashVal << endl;
    return hashVal;
}

int HashTableLinear::hashFunction2(int key){
    int hashVal2 = (int)(floor((key/TABLE_SIZE)%TABLE_SIZE));
    cout << "HASHVAL2" << hashVal2 << endl;
    return hashVal2;
}



bool HashTableLinear::insertItemLinearProbe(int key){
        // Use the hash function on the key to get the index/slot,
        // create a new node with the key and insert it in this slot's list
        int index = hashFunction(key);
        int count = 0;
        //cout << index << endl;
        if(table[index] == -1){
            table[index] = key;
            //cout << "inserted item at " << index << endl;
            return true;
        }else if(table[index] != -1){
            while(table[index] != -1){
                index++;
                if(index > TABLE_SIZE)
                {
                    index = 0;
                }
                count++;
                if(count > TABLE_SIZE)
                {
                    cout << "TABLE IS FULL, CANNOT INSERT" << endl;
                    return false;
                }
            }
            table[index] = key;
            //cout << "inserted item at " << index << endl;
            return true;
        }
        return false;
}

bool HashTableLinear::deleteItemLinearProbe(int key){
    int index = hashFunction(key);
    int count = 0;
    if(table[index] == key){
        table[index] = -1;
        return true;
    }else if(table[index] != key){
        while(table[index] != key){
            index++;
            if(index > TABLE_SIZE)
            {
                index =0;
            }
            count++;
            if(count > TABLE_SIZE)
            {
                cout << "Item: " << key << " not in table, cannot delete" << endl;
                return false;
            }
        }
        table[index] = -1;
        return true;
    }
    return false;
}



int HashTableLinear::lookUpLinearProbe(int key){
    int index = hashFunction(key);
    int count =0;
    if(table[index] == key){
        //cout << "key exists at index " << index << endl;
        return index;
    }else if(table[index] !=  key){
        while(table[index] != key){
            index ++;
            if(index > TABLE_SIZE){
                index =0;
            }
            count++;
            if(count > TABLE_SIZE){
                //cout << "Key does not exist" << endl;
                return -1;
            }
        }
    }
    if(table[index] != key){
        //cout << "Key does not exist" << endl;
        return -1;
    }else if(table[index] == key){
        //cout << "Key exists at index " << index << endl;
        return index;
    }
    return -1;
}

void HashTableLinear::printTableLinearProbe(){
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << "[" << table[i] << "]";
    }
    cout << " " << endl;
    cout << " " << endl;
}
/*if(table[i] != -1){
            cout << table[i]  << " ";
        }else{
            cout << table[i] << " ";
        }
    }
    cout << endl;
    */

int main(int argc, char *argv[]){

    HashTableLinear ht;
    string temp;
    int count =0;
    int arrayIndex = 0;
    int newValue;
    int startTime, endTime;
    double execTime;
    startTime = clock();
    int array[100];
    ifstream fs;
    string filename = argv[1];
    fs.open(filename);

    if(fs.is_open())
    {
        // cout << "here "<< endl;
         for (int i =0; i < 10009; i++) {
            getline(fs,temp, ',');
            newValue = stoi(temp);
            // cout << "here" << endl;
            //
            ht.insertItemLinearProbe(newValue);
            cout << newValue<< endl;
            // cout << "here "<< endl;
            if (arrayIndex <= 100) {
                array[arrayIndex] = newValue;
                arrayIndex++;
                // cout << "here "<< endl;
            }
            // if (i = 10009) {
            //     break;
            // }
        }

    } else {
        cout << "Cant open file" << endl;
        return 0;
    }
    endTime = clock();
    execTime = (double)(endTime-startTime)/CLOCKS_PER_SEC;
    cout << "execution time: " << execTime << endl;
    //ht.printTableLinearProbe();
    int count2 = 0;
    int j =0;
    int startTime2, endTime2;
    double execTime2;
    startTime2 = clock();
    if(fs.is_open())
    {
       /* while(count2 < 100)
        {
            ht.deleteItemLinearProbe(array[count2]);
            count2++;
        }*/
        //cout << count2 << endl;
        for(int i =0; i < 100; i++)
        {
            //getline(fs, temp, ',');
            //ht.insertItemLinearProbe(stoi(temp));
            //ht.deleteItemLinearProbe(array[i]);
            ht.lookUpLinearProbe(array[i]);
        }
    }
    endTime2 = clock();
    execTime2 = (double)(endTime2-startTime2)/CLOCKS_PER_SEC;
    cout << "execution time2: " << execTime2 << endl;




    return 0;

}
