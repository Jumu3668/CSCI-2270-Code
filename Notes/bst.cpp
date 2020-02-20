#include <iostream>

using namespace std;

struct Node {
	int key;
	Node *left, *right;
};

class BinarySearchTree {
private:
	Node* root;
	void printTreeHelper(Node* root);
	void printRecursiveCallsHelper(Node* root, int count);
	Node* insertNodeHelper(Node* r, int k);
	Node* searchKeyHelper(Node* root, int k);
	Node* createNode(int k);
	Node* deleteNodeHelper(Node* r, int k);
public:
	BinarySearchTree();
	void printTree();
	void searchKey(int k);
	void printRecursiveCalls();
	void insertNode(int k);
	void deleteNode(int k);	//delete the node given the key. All other info is protected as a part of the node
};

BinarySearchTree::BinarySearchTree() {
	root = NULL; // 'nullptr' is not an int, 'NULL' can be
}

void BinarySearchTree::printTree() {
	printTreeHelper(root);
	cout << endl;
}
void BinarySearchTree::printTreeHelper(Node* root) {
	if (root) {
		// Left subtree
		printTreeHelper(root->left);
		// middle node (parent)
		cout << root->key << " ";
		// Right subtree
		printTreeHelper(root->right);
	}
}

// NEW METHOD FOR DISPLAYING RECURSIVE DEPTH
void BinarySearchTree::printRecursiveCalls() {
	printRecursiveCallsHelper(root, 0);
	cout << endl;
}
void BinarySearchTree::printRecursiveCallsHelper(Node* root, int count) {
	if (root) {
		for(int i=0; i<count; i++)
			cout << "\t";
		cout << "printTree(" << root->key << ", " << count <<  ")"<< endl;

		// Left subtree
		printRecursiveCallsHelper(root->left, ++count); // In class this was 'count++', that's POST-decrementing, we need it PRE-incremented!
		// middle node (parent)
		//cout << root->key << " ";
		// Right subtree
		printRecursiveCallsHelper(root->right, ++count);
	}
}

Node* BinarySearchTree::createNode(int k) {
	Node* newNode = new Node;
	newNode->key = k;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

void BinarySearchTree::insertNode(int k) {
	root = insertNodeHelper(root, k);
}

void BinarySearchTree::searchKey(root, k) {
	Node * ret = printTreeHelper(root);
	cout << ret -> key
}

void BinarySearchTree::serachKeyHelper(Node* root, int k) {
	if (root) {
		if (root -> key < k)
			return root;
		else if (root -> key < k)
			return searchKeyHelper(root -> right, k);
		else if (root -> key > k)
			return serachKeyHelper(root -> key > k);
		else{
			cout << "Key is not in tree :(" << endl;
			return NULL;
		}
	}
}

void BinarySearchTree::deleteNode(int k) {
	root = deleteNodeHelper(root, k);

}
Node* BinarySearchTree::deleteNodeHelper(Node* r, int k) {
	Node* toDelete = searchKeyHelper(root, k);
	if (!toDelete) {
		cout << "Node was not in tree" << endl;
		return r;
	}

	return r;
}
Node* BinarySearchTree::insertNodeHelper(Node* r, int k) {
	// Insert at the head
	if (root == NULL) {		//base case for our recurisve function
		root = createNode(k);
	} else if (r->key < k) { // 'r' is not NULL
		r->right = insertNodeHelper(r->right, k);
	}else {
		r->left = insertNodeHelper(r->left, k);
	}

	return r;	//new node created for head
}


int main() {
	BinarySearchTree bst;

	bst.insertNode(10);
	bst.printTree();
	bst.insertNode(12);
	bst.printTree();
	bst.insertNode(5);
	bst.printTree();
	bst.insertNode(4);
	bst.printTree();
	bst.printRecursiveCalls();
	return -12;
	bst.insertNode(6);
	bst.printTree();
	bst.insertNode(13);
	bst.printTree();
	bst.insertNode(17);
	bst.printTree();

	return 0;
}
