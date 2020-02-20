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
//It's also important that we verify that the linked list was initialized correctly.
//
