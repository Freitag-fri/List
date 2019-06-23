#include <QCoreApplication>
#include <iostream>
#include <list.cpp>
using namespace std;

int *foo(int *oldarr, int n, int q);




int main(int argc, char *argv[])
{   QCoreApplication a(argc, argv);

    List b;

    b.push_back(5);
    b.push_back(10);
    b.push_back(15);
    b.push_back(20);
    b.push_front(1);
    b.insert(0, 6);

    for (int i = 0; i < b.GetSize(); i++)
    {
       cout << b[i] << " ";
    }

//    int n = 1;
//    int q;
//    int *arr = new int[n];
//    cin >> q;
//    arr[n - 1] = q;

//    while(true)
//    {
//        cin >> q;
//        arr = foo(arr , n, q);
//        n++;
//        for (int i = 0; i < n; i++)
//        {
//            cout << arr[i] << ", ";
//        }cout << endl;
//    }
    return a.exec();
}




//int *foo(int *oldarr, int n, int q)
//{
//    int *newArr = new int[n + 1];
//    for (int i = 0; i < n; i++)
//    {
//        newArr[i] =  oldarr[i];
//    }
//    newArr[n] = q;

//    delete [] oldarr;
//    return newArr;
//}
