#include <iostream>

using namespace std;

struct Date {
	int day, month, year;
	Date* date;
};

class Calendar {	//if you include the header, you gain access to the class contained within
private:
	// Stores data to be kept away from the user
	// Only to be accessed by internal class methods
	Date* date;
public:
	// Anything here a user can see and modify/use
	Calendar();
	~Calendar();

	void setDate(int d, int m, int y);
	void printDate();
};

Calendar::Calendar()
{
	date = new Date;
}

Calendar::~Calendar()
{
	delete date;	//always delete if we have new
}

void Calendar::setDate(int d, int m, int y)
{
	date->day;	// pointer to struct replaces the dot operator (Date date date.day, date.month, date.year)
						// we use (Date* date date->month, date->day, date->year)
						// struct.member == (*struct).member
	date->month;
	date->year;
}

void Calendar::printDate()
{
		cout << date->day <<"/" << date->month << "/" << date->year << endl;
}

int main() {
	Date date{13, 9, 2019};
	Calendar myDate; // Calls the constructor implicitly	therefore does not need parenthesis

	myDate.printDate();

	return 0;
}
