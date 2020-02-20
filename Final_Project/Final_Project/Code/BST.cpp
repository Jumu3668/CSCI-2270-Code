#include <iostream>
#include "BST.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
#define COUNT 10

// Create a node with key as data

Node* HashTableBST:: createNode(int data)
{
    Node* newNode = new Node;
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


int HashTableBST::hashFunction(int key) {
    return key % tableSize;
}


// parameterized constructor. It will create the root and put the data in the root.


HashTableBST::HashTableBST(int data)
{
    this -> tableSize = data;
    table = new Node*[tableSize];
    for (int i = 0; i < data; i++)
        table[i] = nullptr;
    numElements = 0;
    root = createNode(data);
    cout<< "New tree created with "<<data<<endl;
}

// default constructor. It will create the default sized hash table

HashTableBST::HashTableBST() {
    this -> tableSize = TABLE_SIZE;
    table = new Node*[tableSize];
    for (int i = 0; i < TABLE_SIZE; i++)
        table[i] = nullptr;
    numElements = 0;

}




Node* HashTableBST::getRoot(){
    return root;
}


 // This function will destroy the subtree rooted at currNode.
 // Think about in what order should you destroy. POSTORDER. or right-left-root

void HashTableBST:: destroyNode(Node *currNode){
     if(currNode!=NULL)
     {
         destroyNode(currNode->left);
         destroyNode(currNode->right);

         delete currNode;
         currNode = NULL;
     }
 }


//--------------------------- Get Max and Min value Node ------------------------------------------------

Node* HashTableBST::getMaxValueNode(Node* currNode){
    if(currNode->right == NULL){
        return currNode;
    }
    return getMaxValueNode(currNode->right);
}

Node* HashTableBST::getMinValueNode(Node* currNode){

    if(currNode->left == NULL){
      return currNode;
    }
    return getMinValueNode(currNode->left);
}

//---------------------------- INSERT NODE IN THE TREE --------------------------------------

/**
This function will add the data in the tree rooted at currNode.
We will call this function from addNode.
**/

Node* HashTableBST:: insertBSTHelper(Node* currNode, int key)
{
    if(currNode == NULL){
        return createNode(key);
    }
    else if(currNode->key < key){
        currNode->right = insertBSTHelper(currNode->right,key);
    }
    else if(currNode->key > key){
        currNode->left = insertBSTHelper(currNode->left,key);
    }
    return currNode;

}


void HashTableBST:: insertBST(int key)
{
    int index = hashFunction(key);

    table[index] = insertBSTHelper(table[index], key);
    numElements++;
}

//-----------------------------------------PRINT TREE (INORDER TRAVERSAL)--------------------------------

/** This function will traverse the tree in-order and print out the node elements.
printTree() function will call this function.
**/

void HashTableBST:: printTreeHelper(Node* currNode){
     if(currNode)
     {
        printTreeHelper( currNode->left);
        cout << " "<< currNode->key;
        printTreeHelper( currNode->right);
     }
 }

void HashTableBST::printTree() {
    for (int i = 0; i < tableSize; i++) {
        printTreeHelper(table[i]);

    }
     cout<<endl;
}

 //------------------------------------------------SEARCH A KEY------------------------------------------
 /** This function will search the data in a tree
     We will call this function from searchKey.
 **/

Node* HashTableBST::lookupHelper(Node* currNode, int data){
    if(currNode == NULL)
        return NULL;

    if(currNode->key == data)
        cout << "Found " << data << " in the tree";
        return currNode;

    if(currNode->key > data)
        return lookupHelper(currNode->left, data);

    return lookupHelper (currNode->right, data);
}

// This function will return whether a key is in the tree
bool HashTableBST::lookup(int key){
    int index = hashFunction(key);

    Node* tree = lookupHelper(table[index], key);
    if(tree != NULL) {
        return true;
    }
    cout<<"Key not present in the tree"<<endl;
    return false;
}

//--------------------------- Delete a Node ------------------------------------------------

// This function deletes the Node with 'value' as it's key. This is to be called inside removeRange() function
Node* HashTableBST::deleteHelper(Node *currNode, int value)
{

  if(currNode == NULL)
  {
    return NULL;
  }
  else if(value < currNode->key)
  {
    currNode->left = deleteHelper(currNode->left, value);
  }
  else if(value > currNode->key)
  {
    currNode->right = deleteHelper(currNode->right, value);
  }
  // We found the node with the value
  else
  {
    if(currNode->left == NULL && currNode->right == NULL)
    {
        delete currNode;
        return NULL;
    }
    else if(currNode->left == NULL)
    {
        Node *temp = new Node;
        temp = currNode -> right;
        delete currNode;
    }
    else if(currNode->right == NULL)
    {
        Node *temp = new Node;
        temp = currNode -> left;
        delete currNode;
    }
    else
    {
        Node* temp = getMinValueNode(currNode->right);
        currNode->key = temp->key;
        currNode -> right = deleteHelper(currNode->right, temp->key);

      ///Replace with Minimum from right subtree
      // Find lowest element from right subtree
    }
    return currNode;

  }
return currNode;
}

void HashTableBST::deleteNode(int key) {
    int index = hashFunction(key);
    table[index] = deleteHelper(table[index], key);
    cout << "deleting " << "key..." << endl;


}

// This function removes nodes with values in the range low and high.
// You need to call deleteNode() function inside this function

int HashTableBST::getTableSize() {
    return tableSize;
}
double HashTableBST::loadFactor() {
    return numElements / (double)tableSize;
}

int HashTableBST::getNumElements() {
    return numElements;
}
