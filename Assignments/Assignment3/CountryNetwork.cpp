/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represet communication paths between nations             */
/****************************************************************/

#include "CountryNetwork.hpp"

using namespace std;

Country* head;  // Points to the first node in the linked list. Makes head pointer global
CountryNetwork::CountryNetwork()
{
  head = NULL;
}


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

  else
  {
    // rest of nodes are added here
    temp -> name = countryName;
    temp -> next = previous -> next;
    previous -> next = temp;

    cout << "adding: " << countryName << " (prev: " << previous->name << ")" << endl;
  }
}

void CountryNetwork::loadDefaultSetup()
{
  insertCountry(head, "United States");
  insertCountry(searchNetwork("United States"), "Canada");
  insertCountry(searchNetwork("Canada"), "Brazil");
  insertCountry(searchNetwork("Brazil"), "India");
  insertCountry(searchNetwork("India"), "China");
  insertCountry(searchNetwork("China"), "Australia");
}

Country* CountryNetwork::searchNetwork(string countryName)    //returns country pointer
{
  Country* temp = head;
  while (temp != NULL && temp -> name != countryName)
  {
    temp = temp -> next;
  }
  return temp;
}

void CountryNetwork::transmitMsg(string receiver, string message)
{
  //store message accross each country

  if (searchNetwork(receiver) == NULL)
  {
    cout << "Country not found" << endl;
    return;
  }
  else if (head != NULL)
  {
    Country *temp = head;
    while (temp -> name != receiver)
    {
      // set each country message and message increment
      temp -> message = message;
      (temp -> numberMessages)++;
      cout << temp -> name << " [# messages received: " << temp -> numberMessages << "] received: " << message << endl;
      temp = temp -> next;
    }

    temp -> message = message;
    (temp -> numberMessages)++;
    cout << temp -> name << " [# messages received: " << temp -> numberMessages << "] received: " << message << endl;
  }
  else
  {
    cout << "Empty list\n";
  }
}

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
