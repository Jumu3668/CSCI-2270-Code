#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>
using namespace std;

struct User {
string username;
float gpa;
int age;
};
void addUser(User users[], string _username, float _gpa, int _age, int length)
{
    users[length].username = _username;
    users[length].gpa = _gpa;
    users[length].age = _age;
}
void printList(const User users[], int length)
{
  for(int g = 0; g < length; g++)
  {
  cout << users[g].username << " [" << users[g].gpa << "] " << "age: " << users[g].age << endl;
  }
}
int main(int argc, char *argv[])
{

User userData[100];
ifstream fin(argv[1]);

if(fin.is_open())
{
  int j = 0;
  string data;
  string name;
  float gpa;
  int age;

  while(!fin.eof())
  {
   getline(fin, data, ',');
    name = data;
    cout << j << '.' << name << endl;
   getline(fin, data, ',');
    stringstream to(data);
    to >> gpa;
  cout << j << '.' << gpa << endl;
    getline(fin, data, '\n');
    stringstream to2(data);
    to2 >> age;
    cout << j << '.' << age << endl;
    addUser(userData, name, gpa, age, j++);

  }
  printList(userData, j);
 fin.close();
 ofstream fout(argv[2]);
 if(fout.is_open())
 {
   int min;
   stringstream to3(argv[3]);
   to3 >> min;
   for(int a = 0; a < j; a++)
   {
     if(userData[a].gpa > min)
     {
    fout << userData[a].username << ',' << " [" << userData[a].gpa << "] "<< ',' << "age: " << userData[a].age << endl;
     }
   }

 }
}
else
{
  cout<< "Failed to open the file.\n" << endl;
}


return 0;
}
