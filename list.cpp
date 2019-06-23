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

    List ()
    {
      size = 0;
      firstElement = nullptr;
    }


};

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
