

using namespace std;
#include "ProducerConsumer.hpp"
#include <string>
#include <iostream>

ProducerConsumer::ProducerConsumer()
{
    queueFront = 0;
    queueEnd = 0;
}

bool ProducerConsumer::isEmpty()
{
    if (counter == 0)
    return true;
    else
    return false;
}

bool ProducerConsumer::isFull()
{
  //test if queue is full
  if (counter == 20)
  return true;
  else
  return false;
}

void ProducerConsumer::enqueue(std::string item)
{
    if(!isFull())
    {
        queue[counter] = item;
        queueEnd++;
        counter++;
    }
    else
    {
        cout << "Queue full, cannot add new item" << endl;
    }
}

void ProducerConsumer::dequeue()
{
    if(!isEmpty())
    {
        queue[queueFront] = "";
        queueFront++;
        counter--;
        if(queueFront == SIZE)
        {
            queueFront = 0;
        }
        queueEnd = counter - queueFront;
        if (queueEnd < 0)
        {
            queueEnd = abs(queueFront + counter - SIZE);
        }
    }
    else
    {
        cout << "Queue empty, cannot dequeue an item" << endl;
    }

}

string ProducerConsumer::peek()
{
    if (!isEmpty())
    {
        //return first item in the queue
        return queue[queueFront];
    }
    else
    {
        cout << "Queue empty, cannot peek" << endl;
        return "";
    }
}

int ProducerConsumer::queueSize()
{
    return counter;
}
