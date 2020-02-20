/****************************************************************/
/*                   Assignment 3 Driver File                   */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "CountryNetwork.hpp"
#include <string>
// you may include more libraries as needed
using namespace std;
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

    Country *prevPointer = new Country;
    while (input1 != "8")
    {
      displayMenu();
      getline(cin, input1);

      switch(stoi(input1))
      {
        case 1:
        {
            CountryNet.loadDefaultSetup();
            CountryNet.printPath();
            break;
        }
        case 2:
        {
            CountryNet.printPath();
            break;
        }
        case 3:
        {
            cout << "Enter a new country name:" << endl;
            getline(cin, country);
            cout << "Enter the previous country name (or First):" << endl;
            getline(cin, input2);
            while (CountryNet.searchNetwork(input2) == NULL && input2 != "First")
            {
              cout << "INVALID(previous country name)...Please enter a VALID previous country name!" << endl;
              getline(cin, input2);
            }

            prevPointer = CountryNet.searchNetwork(input2);


            CountryNet.insertCountry(prevPointer, country);
            CountryNet.printPath();
            break;
        }
        case 4:
        {
            cout << "Enter a country name:" << endl;
            getline(cin, country);
            CountryNet.deleteCountry(country);
            CountryNet.printPath();
            break;
        }
        case 5:
        {
            CountryNet.reverseEntireNetwork();
            CountryNet.printPath();
            break;
        }
        case 6:
        {
            cout << "Enter the count of values to be rotated:" << endl;
            getline(cin , input2);
            CountryNet.rotateNetwork(stoi(input2));
            CountryNet.printPath();
            break;
        }
        case 7:
        {
            cout << "Network before deletion" << endl;
            CountryNet.printPath();
            CountryNet.deleteEntireNetwork();
            cout << "Network after deletion" << endl;
            CountryNet.printPath();
            break;
        }
        case 8:
        {
            cout << "Quitting... cleaning up path:" << endl;
            if (CountryNet.isEmpty() == true)
            {
                CountryNet.printPath();
                cout << "Path cleaned\n";
            }
            else
            {
                CountryNet.printPath();
                CountryNet.deleteEntireNetwork();
                cout << "Path cleaned\n";
            }
            cout << "Goodbye!";
            break;
        }
        default:
          cout << "Invalid input\n\n";
      }
    }
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
    cout << " 3. Add Country " << endl;
    cout << " 4. Delete Country " << endl;
    cout << " 5. Reverse Network " << endl;
    cout << " 6. Rotate Network " << endl;
    cout << " 7. Clear Network " << endl;
    cout << " 8. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}
