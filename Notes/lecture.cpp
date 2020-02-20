#include <iostream>
using namespace std;



struct PhoneContacts
{
  int something;
};

int main()
{
  char A[5] = {'B','i','!', 0, '0' };
  int X[4] = {0,1,2,3};

  cout << *A << endl;
  cout << A << endl; //adding size of one int.
  cout << &(*A) << endl;
  cout << X << endl;  //prints out the address for the array
  cout << *X << endl; //dereferencing pointer
  cout << &(*X) << endl;
}

  // -Wall and -Wextra are additional arguments you can add to the g++ command
  // putting an '&' infront of the array value, such as 'A' or 'X'
  // will display the address of the array instead of what it is pointing to.
