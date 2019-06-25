#include <iostream>

using namespace std;

class List
{
private:

    class Element
    {
    public:
        Element *next;
        int data;

        Element (int Kdata = 0, Element *Knext = nullptr)
        {
         next = Knext;
         data = Kdata;
        }
    };


    int size;

public:
    Element *firstElement;
    int operator[](const int index);
    void push_back(int data);
    void push_front(int data);
    int GetSize() {return size;}
    void insert(int pos, int data);
    void pop_back();
    void pop_front();
    void clear();

    List ()
    {
      size = 0;
      firstElement = nullptr;
    }


};

void List::clear()
{
    Element *temp;
    while(true)
    {
     temp = firstElement->next;
     delete firstElement;
     if (temp == nullptr)  break;
     firstElement = temp;
    }
    size = 0;
}

void List::pop_front()
{
    if (firstElement == nullptr)
        return;
    else if(firstElement->next != nullptr)
    {
        Element *buffer = firstElement->next;
        delete firstElement;
        firstElement = buffer;
    }
    else
    {
        delete firstElement;
        firstElement = nullptr;
    }
    size--;
}

void List::pop_back()
{
    Element *buffer = firstElement;
    while(buffer->next != nullptr)
    {

        buffer = buffer->next;
    }
    size--;
    delete buffer;

    int counter = 1;
    buffer = firstElement;
    while(counter != size)
    {
        buffer = buffer->next;
        counter++;
    }
    buffer->next = nullptr;
}

void List::push_back(int data)
{
  if(firstElement == nullptr)
  {
     firstElement = new Element (data);
  }

  else
  {
      Element *buffer = firstElement;
      while(buffer->next != nullptr)
      {
          buffer = buffer->next;
      }
      buffer->next = new Element(data);
  }
    size++;
}

void List::push_front(int data)
{
    firstElement->next = new Element(firstElement->data, firstElement->next);
    firstElement->data = data;
    size++;
}

 void List::insert(int pos, int data)
 {

     int counter = 1;

     if(firstElement == nullptr && pos == 0)
     {
        firstElement = new Element (data);
     }
     else if (pos == 0)
     {
         push_front(data);
         size--;
     }

     else
     {
         Element *buffer = firstElement;
         while(counter != pos)
         {
             buffer = buffer->next;
             counter++;
         }
         buffer->next = new Element(data, buffer->next);
     }
     size++;
 }

int List::operator[](const int index)
 {
     int counter = 0;
     Element *buffer = firstElement;
     if (buffer != nullptr)
     {
         while(counter != index)
         {
             buffer = buffer->next;
             counter++;
         }
         return buffer->data;
     }
 }
