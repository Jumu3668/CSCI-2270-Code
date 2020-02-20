#include <iostream>

using namespace std;

struct SingleNode
{
  int key;
  SingleNode* next;
};

void traverse(SingleNode* head)
{
  SingleNode* temp = head;  //test
  while (temp != NULL)
  {
      cout << temp -> key;
      if (temp -> next != NULL) cout << ", ";
      temp = temp -> next;
  }
  cout << endl;
  return;
}
void search(int k, SingleNode* head)
{
  SingleNode* temp = head;
  while (temp != NULL)
  {
      if (temp -> key == k)
      {
        cout << "Found it!" << endl;
        return;

        // or return the reference (Best not to return to main())
      }
      if (temp -> next != NULL) cout << ", ";
      temp = temp -> next;
  }
  cout << endl;
  return;
}

int main()
{
  // Initialize a linked list
  SingleNode* head = nullptr;
  SingleNode* temp = head;

  // Create first SingleNode struct and insert 5
  temp = new SingleNode;
  temp->key = 5;
  temp->next = nullptr;
  head = temp;

  // insert 6
  (temp->next) = new SingleNode;
  temp = temp -> next;
  (temp->next) -> key = 6;
  (temp->next) -> next = nullptr;

  // insert 7
  (temp->next) = new SingleNode;
  temp = temp -> next;
  (temp->next) -> key = 7;
  (temp->next) -> next = nullptr;

  traverse(head);
  search(5, head);
  search(6, head);
  search(8, head);
}
// Sanity checks for linked lists are good. Use  a while !NULL argument until you hit null, then return true to show that the LL has been properly initialized
//
// When inserting a node in the middle of a linked list, make sure you have the new node point to the next node
// before you have the previuos node point to the new node.
// We do this because we don't want to orphan the next node
// delete head Pointer
// save pointer to head before deleting the node. Then we set head to the new first node
