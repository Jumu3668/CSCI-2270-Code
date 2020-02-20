/****************************************************************/
/*                Producer Consumer Driver File                 */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "ProducerConsumer.hpp"
#include <iostream>
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */
void menu()
{
	cout << "*----------------------------------------*" << endl;
	cout << "Choose an option:" << endl;
    cout << "1. Producer (Produce items into the queue)" << endl;
	cout << "2. Consumer (Consume items from the queue)" << endl;
	cout << "3. Return the queue size and exit" << endl;
	cout << "*----------------------------------------*" << endl;
}

int main(int argc, char const *argv[])
{
	string input = "";
	string enqueue;
	ProducerConsumer pc;
	while (input != "3")
	{
		menu();
		getline(cin, input);
		switch(stoi(input))
		{
			case 1:
			{
				cout << "Enter the number of items to be produced:" << endl;
				getline(cin, enqueue);
				int n = stoi(enqueue);
				if (!cin.fail())
				{
					for (int i = 0; i < n; i++)
					{
						cout << "Item" << i+1 << ":" << endl;
						getline(cin, input);
						pc.enqueue(input);
					}
				}
				else
				{
					cout << "invalid input" << endl;
				}
			}
			break;
			case 2:
			{
				cout << "Enter the number of items to be consumed:" << endl;
				getline(cin, enqueue);
				int m = stoi(enqueue);
				if(!cin.fail())
				{
					for (int i = 0; i < m; i++)
					{
						if(pc.isEmpty())
						{
							cout << "No more items to consume from queue" << endl;
							break;
						}
						cout << "Consumed: " << pc.peek() << endl;
						pc.dequeue();
					}
				}
			}
			break;
			case 3:
			{
				cout << "Number of items in the queue:" << pc.queueSize() << endl;
			}
			break;
		}
	}
}
