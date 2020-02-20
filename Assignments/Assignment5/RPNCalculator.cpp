
#include "RPNCalculator.hpp"

using namespace std;
Operand *stackHead;
RPNCalculator::RPNCalculator()
{
    stackHead = NULL;
}

RPNCalculator::~RPNCalculator()
{
  //Deletes the entire network
}

bool RPNCalculator::isEmpty()
{
    if (stackHead == NULL)
    return true;
    else
    return false;
}

void RPNCalculator::push(float num)
{
    Operand *op = new Operand;
    op -> number = num;
    op -> next = stackHead;
    // op -> next = NULL;
    stackHead = op;
    // cout << "Pushed " << stackHead -> number << " to top of stack" << endl;
}
void RPNCalculator::pop()
{
    if (!isEmpty())
    {
        Operand* temp = stackHead;
        stackHead = stackHead -> next;
        delete temp;
    }
    else
    {
        std::cout << "Stack empty, cannot pop an item." << endl;
    }
}

Operand* RPNCalculator::peek()
{
    if (!isEmpty())
    {
        return stackHead;
    }
    else
    {
        std::cout <<"Stack empty, cannot peek." << endl;
        return NULL;
    }

}
// Operand* RPNCalculator::getStackHead()
// {
//     return stackHead;
// }
bool RPNCalculator::compute (std::string symbol)
{
    if (symbol == "+" || symbol == "*" || symbol == "=")
    {
        if(isEmpty())
        {
            cout << "err: not enough operands" << endl;
            return false;
        }
        else
        {
            if (symbol == "+")
            {
                float sum = getStackHead() -> number;
                pop();
                if(isEmpty())
                {
                    cout << "err: not enough operands" << endl;
                    push(sum);
                    return false;
                }
                else
                {
                    sum = sum + getStackHead() -> number;
                    pop();
                    push(sum);
                    return true;
                }
            }
            else if (symbol == "*")
            {
                float temp1 = getStackHead() -> number;
                pop();
                if (isEmpty())
                {
                    cout << "err: not enough operands" << endl;
                    push(temp1);
                    return false;
                }
                else
                {
                    float temp2 = getStackHead() -> number;
                    pop();
                    push((temp1*temp2));
                    return true;
                }
            }
            else;
        }
    }
    else
    {
        cout << "err: invalid operation" << endl;
        return false;
    }
}
