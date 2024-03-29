#include <iostream>
#include <fstream>

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
    void Erase(int pos);
    void Save();

    enum operation {OpPush_back, OpPush_front, OpPop_back, OpPop_front, OpInsert, OpErase, OpSize, OpSave, OpClear};
    List ()
    {
        size = 0;
        firstElement = nullptr;
    }


};

void List::clear()              //переписать
{
    Element *temp;
    while(true)
    {
        temp = firstElement->next;
        delete firstElement;
        firstElement = temp;
        if (temp == nullptr)
            break;
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

void List::push_front(int data)             ////исправить
{
    if(firstElement == nullptr)
    {
        firstElement = new Element (data);
    }
    else
    {
        firstElement->next = new Element(firstElement->data, firstElement->next);
        firstElement->data = data;
        size++;
    }

}

void List::Erase(int pos)           //удалить элемент с нужной позициии
{
    if (pos == 0)
        pop_front();
    else if (pos == GetSize() -1)
        pop_back();

    else if(pos < GetSize())
    {
        int counter = 0;

        Element *buffer = firstElement;
        Element *temp;
        while(counter != pos)
        {
            temp =  buffer;
            buffer = buffer->next;
            counter++;
            //temp =  buffer->next;
        }
        temp->next = buffer->next;
        delete buffer;
        size--;


    }
}

void List::insert(int pos, int data)
{
    if (pos <= GetSize())
    {
        int counter = 1;

        if(firstElement == nullptr && pos == 0)
        {
            firstElement = new Element (data);
        }
        else if (pos == 0)
        {
            push_front(data);
            size--;                                         //???
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

    else
        return;
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
