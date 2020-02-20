#include <iostream>
using namespace std;

void swap0(int* ptr1, int* ptr2)  //swap by pointer
{
  int *temp;
  temp = ptr1;
  ptr1 = ptr2;
  ptr2 = temp;
}

void swap1 (int ptr1, int ptr2) //swap by value
{
  int temp;
  temp = ptr1;
  ptr1 = ptr2;
  ptr2 = temp;
}

void swap2 (int *&ptr1, int *&ptr2)
{
    int* temp;
    temp = ptr1;
    ptr1 = ptr2;
    ptr2 = temp;
}

void swap3(int &ptr1, int &ptr2)
{
    int temp;
    temp = ptr1;
    ptr1 = ptr2;
    ptr2 = temp;
}

void swap4(int** ptr1, int** ptr2)
{
    int *temp;
    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}
int main(){
    int *ptr1 = new int[5];
    int *ptr2 = new int[5];

    for (int i = 0; i < 5; i++)
    {
        ptr1[i] = i;
    }
    for (int i = 0; i < 5; i++)
    {
        ptr2[i] = 4-i;
    }
    for (int i = 0; i < 5; i++)
    {
        cout << ptr1[i] << " ";
    }
    cout << endl;

    // swap0(ptr1, ptr2);
    // swap1(*ptr1, *ptr2);
    // swap2(ptr1, ptr2);
    // swap3(*ptr1, *ptr2);
    swap4(&ptr1, &ptr2);

    for (int i = 0; i < 5; i++)
    {
        cout << ptr1[i] << " ";
    }
    return 0;
}
