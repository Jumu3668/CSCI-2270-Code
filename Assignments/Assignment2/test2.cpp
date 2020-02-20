#include <iostream>

using namespace std;

int* foo(int x)
{
  int *y = new int[x*x];
  return y;
}

int main()
{
  int * z = foo(10);
  //free space
  delete [] z;
cout << z;
}
