//              10
//             /  \
//            7    16
//Binary tree with a height of 1. has two Leaves because they have no children
//  Elements on the left side are less than 10, elements to the right are greater than 10
// This is how we sort throgh a binary search tree

#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
};

class BinarySearchTree {
private:
    Node *root;         //Data needs to be private, like header for Linked Lists
    void printTreeHelper(Node *root);   // need this to be able to pass the root value to printTree
    void insertNodeHelper(Node *root);
    Node* createNode(int k);
public:
    BinarySearchTree();
    void printTree*();
    void insertNode(int k);
};

BinarySearchTree::BinarySearchTree() {  //if you pass root as parameter, it will pass
    root = NULL;    //nullptr is not an int, NULL can be interpreted as an int. nullptr is for addresses only
    //initial tree is going to be an empty tree. Need to call insertNode to initialize with values
}

void BinarySearchTree::printTree() {
    printTreeHelper(root);

    // Middle
}

void BinarySearchTree::printTreeHelper(Node *root)
{
    if (root) { //if root is NULL
        printTreeHelper(root->left);
        // Middle node (parent)
        cout << root -> key << " " << endl;
        //Right subtree
        printTreeHelper(root -> right);
    }
}

Node* BinarySearchTree::createNode(int k)
{
    Node* newNode = new Node;
    newNode-> key = k;
    newNode -> left = NULL;
    newNode -> right = NULL;

    return newNode;
}

void BinarySearchTree::insertNode(int k)
{
    insertNodeHelper(root, k);
}

void BinarySearchTree::insertNodeHelper(Node *root, int k)
{
    if (root == NULL){
        cout << "Inserting " << k << " at the head! \n" << endl;
        root = createNode(int k);
    } else if (r) {// 'r' is not NULL
        if (r->key < k)//insert to the right/left
            if (r->right == NULL)
                r->right = createNode(k);
            else insertNodeHelper(r->right, k);
    }
}

int main()
{
    BinarySearchTree bst;
    bst.insertNode(10);
    bst.printTree();
    bst.insertNode(12);
    bst.printTree();

    return 0;
}
