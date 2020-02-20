//NOTES
#include <iostream>

using namespace std;

int main()
{
  // Dynamic memory allocation
  int *ptr1 = new int;
  int *ptr2 = new int[10];

  // Deleting dynamic memory
  delete ptr1;
  delete [] ptr2;
}
/**
class DestructorExample
{
  private:
    char *s;
    int size;

  public:
    DestructorExample(char *c); // constructor
    ~DestructorExample();       // destructor
}                               // doesn't take anything and doesn't return anything

DestructorExample::DestructorExample(char *c)
{
  size = strlen(c);
  s = new char[size + 1];
  strcpy(s,c);
}

DestructorExample::~DestructorExample()
{
  delete []s;
}
**/
