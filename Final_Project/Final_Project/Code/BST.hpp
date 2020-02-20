#ifndef BST_HPP
#define BST_HPP

using namespace std;

struct Node{
    int key;
    Node* left ;
    Node* right;
};

class HashTableBST{
    private:
        int tableSize;
        Node* *table;
        const int TABLE_SIZE = 10009;
        Node* root;
        int numElements;
        Node* createNode(int data);
     public:

        Node* insertBSTHelper(Node*, int);
        void printTreeHelper(Node*);
        int hashFunction(int key);
        Node* lookupHelper(Node*, int);

        Node* getMaxValueNode(Node* currNode);
        Node* getMinValueNode(Node* currNode);

        int getTableSize();

        void destroyNode(Node *root);
        Node* deleteHelper(Node *currNode, int value);
        void deleteNode(int key);

        double loadFactor();
        Node* getRoot();                // Returns the root of the tree;
        void insertBST(int);              // function to insert a node in the tree.
        bool lookup(int);            // function to search a data in the tree
        void printTree();               //function to print the tree
        HashTableBST();                          // default constructor
        HashTableBST(int data);                  // parameterized constructor
        void removeRange(int, int);
        bool isValidBST();
        int getNumElements();

};
#endif
