//stringstream test
#include <iostream>
#include <sstream>
using namespace std;
int main()
{
  string str = "456";        //string containing the number
  int num;                 //number which will contain the result

  stringstream convert(str); // stringstream used for the conversion initialized with the contents of Text

  if ( !(convert >> num) )//give the value to Result using the characters in the string
      num = 0;            //if that fails set Result to 0
                             //Result now equal to 456
  cout << num + 1 << endl;
}
