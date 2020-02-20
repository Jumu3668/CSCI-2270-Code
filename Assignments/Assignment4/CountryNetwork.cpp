/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represet communication paths between nations             */
/****************************************************************/

#include "CountryNetwork.hpp"

using namespace std;

/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
 Country* head;
 CountryNetwork::CountryNetwork()
 {
   head = NULL;
 }


/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool CountryNetwork::isEmpty()
{
  if (head == NULL)
    return true;
  else
    return false;
}


/*
 * Purpose: Add a new Country to the network
 *   between the Country *previous and the Country that follows it in the network.
 * @param previous name of the Country that comes before the new Country
 * @param countryName name of the new Country
 * @return none
 */
 void CountryNetwork::insertCountry(Country* previous, string countryName)
 {
   //Insert new country with name countryName in the linked list after the country pointed to by previous.
   //If previous is null, then add the new country to the beginning of the list. Print the name of the country you added according to the following format

   Country *temp = new Country;
   if (head == NULL)
   {
     //first node
     temp -> name = countryName;
     head = temp;  // Points head to this node
     cout << "adding: " << countryName << " (HEAD)" << endl;
   }
   else if (previous == NULL)
   {
        temp -> name = countryName;
        temp -> next = head;
        head = temp;
        cout << "adding: " << countryName << " (HEAD)" << endl;
   }
   else
   {
     // rest of nodes are added here
     temp -> name = countryName;
     temp -> next = previous -> next;
     previous -> next = temp;

     cout << "adding: " << countryName << " (prev: " << previous->name << ")" << endl;
   }
 }


/*
 * Purpose: delete the country in the network with the specified name.
 * @param countryName name of the country to delete in the network
 * @return none
 */
 void CountryNetwork::deleteCountry(string countryName)
 {
   Country* pointer = searchNetwork(countryName);  //returns pointer for that country
   Country* temp = head;
   if(pointer == NULL)
   {
     cout << "Country does not exist.\n";
   }
   else if (pointer == head)
   {
     head = head -> next;
     delete pointer;
   }
   else
   {
     while (temp != NULL && temp -> name != countryName)
     {
       if(temp -> next == pointer)
       {
         temp -> next = temp -> next -> next;
         delete pointer;
         break;
       }
       temp = temp -> next;
     }
   }
 }

/*
 * Purpose: populates the network with the predetermined countries
 * @param none
 * @return none
 */
 void CountryNetwork::loadDefaultSetup()
 {
   insertCountry(head, "United States");
   insertCountry(searchNetwork("United States"), "Canada");
   insertCountry(searchNetwork("Canada"), "Brazil");
   insertCountry(searchNetwork("Brazil"), "India");
   insertCountry(searchNetwork("India"), "China");
   insertCountry(searchNetwork("China"), "Australia");
 }


/*
 * Purpose: Search the network for the specified country and return a pointer to that node
 * @param countryName name of the country to look for in network
 * @return pointer to node of countryName, or NULL if not found
 * @see insertCountry, deletecountry
 */
 Country* CountryNetwork::searchNetwork(string countryName)    //returns country pointer
 {
   Country* temp = head;
   while (temp != NULL && temp -> name != countryName)
   {
     temp = temp -> next;
   }
   return temp;
 }


/*
 * Purpose: deletes all countries in the network starting at the head country.
 * @param none
 * @return none
 */
 void CountryNetwork::deleteEntireNetwork()
 {
   while (head != NULL)
   {
     Country* temp = head;
     cout << "deleting: " << head -> name << endl;
     head = head -> next;
     delete temp;
   }
   cout << "Deleted network" << endl;
 }


/*
 * Purpose: Rotate the linked list i.e. move 'n' elements from
 * the back of the the linked to the front in the same order.
 * @param number elements to be moved from the end of the list to the beginning
 * @return none
 */
void CountryNetwork::rotateNetwork(int n)
{
  Country *temp = head;
  int listCount = 0;

  while (temp != NULL)
  {
    listCount++;
    temp = temp -> next;
  }
  int countRemaining = listCount - n;

  if(head == NULL)
  {
    cout << "Linked List is Empty" << endl;
  }
  else if (n < 1 || n > listCount)
  {
    cout << "Rotate not possible\n";
  }
  else
  {
    Country *prev = new Country;
    prev = head;
    Country *current = new Country;
    current = head;
    Country *last = new Country;
    last = head;

    for (int i = 0; i < n; i++)
    {
      current = current -> next;
    }

    for (int i = 0; i < (n-1); i++)
    {
      prev = prev -> next;
    }

    while (last -> next != NULL)
    {
      last = last -> next;
    }

    last -> next = head;
    head = current;
    prev -> next = NULL;

    cout << "Rotate Complete" << endl;
  }
}

/*
 * Purpose: reverse the entire network
 * @param ptr head of list
 */
 void CountryNetwork::reverseEntireNetwork()
 {
   Country *temp = head;
   Country *previousNode = new Country, *currentNode = new Country, *nextNode = new Country;

   previousNode = NULL;
   currentNode = head;

   while (currentNode != NULL)
   {
     nextNode = currentNode -> next;
     currentNode -> next = previousNode;
     previousNode = currentNode;
     currentNode = nextNode;
   }
   head = previousNode;
 }

/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
 void CountryNetwork::printPath()
 {
   cout <<"== CURRENT PATH =="<< endl;
   if (head != NULL)
   {
     Country *node = head;

     while (node != NULL)
     {
       cout << node -> name;
       if (node -> next != NULL) cout << " -> ";
       node = node -> next;
     }
     cout << " -> NULL\n===" << endl;
   }
   else
   {
     cout << "nothing in path\n===\n";
   }
   return;
 }
