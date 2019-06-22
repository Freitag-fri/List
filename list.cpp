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
    void addElement(int data);
    void addElement2(int data);
    int GetSize() {return size;}

    List ()
    {
      size = 0;
      firstElement = nullptr;
    }
};

void List::addElement2(int data)
{
  if(firstElement->next == nullptr)
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

void List::addElement(int data)
{
    if (firstElement == nullptr)
    {
       firstElement = new Element(data);
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
   size ++;
}
