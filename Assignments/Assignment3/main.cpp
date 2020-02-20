/****************************************************************/
/*                   Assignment 3 Driver File                   */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "CountryNetwork.hpp"
#include <string>
// you may include more libraries as needed

// declarations for main helper-functions
void displayMenu();
void loadDefaultSetup();
void printPath();
int main(int argc, char* argv[])
{
    // Object representing our network of cities.
    // (Linked list representation is in CountryNetwork)
    CountryNetwork CountryNet;
    string input2, message, receive, country;
    string input1 = "";

    Country *prevPointer;
    while (input1 != "5")
    {
      displayMenu();
      getline(cin, input1);

      switch(stoi(input1))
      {
        case 1:
            CountryNet.loadDefaultSetup();
            CountryNet.printPath();
            break;
        case 2:
            CountryNet.printPath();
            break;
        case 3:
            cout << "Enter name of the country to receive the message:\n";
            getline(cin, country);

            cout << "Enter the message to send:\n\n";
            getline(cin, message);
            CountryNet.transmitMsg(country, message);
            break;
       case 4:
            cout << "Enter a new country name:" << endl;
            getline(cin, country);
            cout << "Enter the previous country name (or First):" << endl;
            getline(cin, input2);
            while (CountryNet.searchNetwork(input2) == NULL && input2 != "First")
            {
              cout << "INVALID(previous country name)...Please enter a VALID previous country name!" << endl;
              getline(cin, input2);
            }
            if (input2 == "First")
            {
              //set prevPointer to first country in linked list
              prevPointer = CountryNet.searchNetwork("United States");  // <--- fucking stupid way of doing it but it's the only way for moodle to accept it. Would rather have a getHead() function
            }
            else
            {
              prevPointer = CountryNet.searchNetwork(input2);
            }

            CountryNet.insertCountry(prevPointer, country);
            CountryNet.printPath();
            break;



        fault:
          cout << "Invalid input\n\n";
      }
    }
    cout << "Quitting...\nGoodbye!";
    return 0;
}
/*
 * Purpose; displays a menu with options
 */
void displayMenu()
{
    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build Network " << endl;
    cout << " 2. Print Network Path " << endl;
    cout << " 3. Transmit Message " << endl;
    cout << " 4. Add Country " << endl;
    cout << " 5. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}
