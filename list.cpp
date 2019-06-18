#include <iostream>

using namespace std;

class List
{
public:


private:

    class Element
    {
    public:
        Element *next;
        int data;

        Element (Element *Knext, int Kdata)
        {
         next = Knext;
         data = Kdata;
        }

    };
};

