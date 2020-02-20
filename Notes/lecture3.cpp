// 9/6/19
#include <iostream>

using namespace std;

void add (int x, int y, int* z)
//whatever

int main()
{
int z;
//add (1,2,z); don't do this!!!
add (1,2,&z);
// z is a local variable
// when we call add, it gives a copy of 1 , 2 ,and z as it is passed to the funciton
// they get copied to a new stack
// & is address of. We pass the address of z to the function
// the pointer stores the address to the value
// Pass by Reference passes where the data is, NOT WHAT the data is.
// This allows us to not need to return any value as we just modify what the data is
}
