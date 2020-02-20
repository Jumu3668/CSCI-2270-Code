#include "LinkedList.hpp"

using namespace std;

LinkedList::LinkedList(){
        head = NULL;
    }

LinkedList::~LinkedList(){
	Node* crawler;
	while(head!=nullptr){
		crawler = head->next;
		delete head;
		head = crawler;
	}
}

// Add a new Node to the list
void LinkedList::insert(Node* prev, int newKey){

    //Check if head is Null i.e list is empty
    if(head == NULL){
        head = new Node;
        head->key = newKey;
        head->next = NULL;
    }

        // if list is not empty, look for prev and append our Node there
    else if(prev == NULL)
    {
        Node* newNode = new Node;
        newNode->key = newKey;
        newNode->next = head;
        head = newNode;
    }

    else{

        Node* newNode = new Node;
        newNode->key = newKey;
        newNode->next = prev->next;
        prev->next = newNode;

    }
}



// Building list
void LinkedList::loadList(int* keys , int length) {

    insert(NULL, keys[0]);

    Node* prev = head;

    for(int i = 1; i < length; i++)
    {
        insert(prev, keys[i]);
        prev = prev->next;
    }

}

// Print the keys in your list
void LinkedList::printList(){
    Node* temp = head;

    while(temp->next != NULL){
        cout<< temp->key <<" -> ";
        temp = temp->next;
    }

    cout<<temp->key<<" -> NULL"<<endl;
}

///////////////////////////////////////////////////////////////
// TODO : Complete the following function
void LinkedList::removeNthFromEnd(int n)
{
    //first we use a crawler to count the length of the LinkedList
    //starting from the beginning of the Linked List
    Node *crawler = head;
    int counter = 1;
    while (crawler -> next != NULL)
    {
        crawler = crawler -> next;
        counter ++;

    }

    cout <<"Length of the array is "<< counter<<" units" << endl;
    // we then subtract from the total length the node we want to be deleted from the end, which is n units.
    n = counter - n;
    // now n = the index for where the node is but counted from the left/head as opposed to the right/end
    crawler = head;
    Node *previous;
    if (n == 0) //checks to see if the node being deleted is the head node
    {
        Node *temp = head;
        head = head -> next;
        delete temp;
    }
    else    //now we sift through the linked list n times so we can get a pointer to the node to be deleted
    {       //and to one before that one
        for (int i = 0; i < n; i++)
        {
            previous = crawler;
            crawler = crawler -> next;
        }

        //delete crawler node

        previous -> next = previous -> next -> next;
        delete crawler;
    }
}
