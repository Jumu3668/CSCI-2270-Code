#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

#define file "testFile.txt"
#define START_SIZE 4

// Define struct -> No data initialized!
struct PhoneContact {
	string name, nickName;
	int number;
	bool block;
} globalStruct1, globalStruct2; // won't use these!

void parse(string filename, PhoneContact phoneBook[], int* numEntries, int* maxEntries) {
	ifstream fs; // input stream OBJECT
	fs.open(filename);


	// Keep loop relavent variables above loop for organization
	string name; // moved outside loop for scope
	while (getline(fs, name, ',')) {
		cout << "Made it to: " << *numEntries << endl;
		if (*numEntries == *maxEntries) { // Double the array!
			// Figure out the size of the new array
			cout << "Doubling from "<< *maxEntries << " to " << *maxEntries*2 << endl;
			*maxEntries = *numEntries*2;
			PhoneContact* newArray = new PhoneContact[*maxEntries]; // Allocate space for the new array

			cout << "Allocated new array, filling with old data...\n";
			// Copy old data to new Array
			for (int i=0; i<*numEntries; i++) {
				// NOTE: The pointers to our name & nickname strings within our PhoneContact structs are copied
				//       This is why if we delete the phoneBook array, we segfault when accessing these
				newArray[i] = phoneBook[i];
			}

			// Delete old array
			cout << "Old array started at " << &phoneBook[0] << endl;
			//delete [] phoneBook;
			phoneBook = newArray;
			cout << "New array started at " << &phoneBook[0] << endl;
		}

		// Initialize line variables
		string nickName;
		string number;
		string block;

		// Populate all the line variables
		getline(fs, nickName, ',');
		getline(fs, number, ',');
		getline(fs, block);

		// Populate the struct at index "numEntries"
		phoneBook[*numEntries].name = name;
		phoneBook[*numEntries].nickName = nickName;
		phoneBook[*numEntries].number = stoi(number);
		phoneBook[*numEntries].block = stoi(block); // 
		(*numEntries)++;
	}

	// Test that we filled these in correctly
	for (int i=0; i<*numEntries; i++) { // don't forget to change here as well!
		cout << phoneBook[i].name << endl;
		cout << phoneBook[i].nickName << endl;
		cout << phoneBook[i].number << endl;
		cout << phoneBook[i].block << endl;
		cout << endl;
	}
}

int main(int argc, char* argv[]) {
	// Take in command line args
	string filename = "";
	if (argc < 2) {
		cout << "Not enough arguments!\n";
	} else if (argc > 2) {
		cout << "Too many arguments\n";
	} else {
		filename = argv[1];
	}

	// Declare on the Stack
	int numEntries_Data = 0; // Static destination for numEntries_StaticData onto the STACK
	int* numEntries_StaticData = &numEntries_Data; // Pointers need data to point to

	// Declare on the Heap
	int* maxEntries = new int;
	*maxEntries = START_SIZE;
	int* numEntries_DynamicData = new int; // Allocates an integer onto the HEAP
	*numEntries_DynamicData = 0;

	PhoneContact phoneBook[START_SIZE];
	parse(filename, phoneBook, numEntries_DynamicData, maxEntries); // try both the static/dynamic variables!

	return 0;
}
