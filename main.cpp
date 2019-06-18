#include <QCoreApplication>
#include <iostream>
using namespace std;

int *foo(int *oldarr, int n, int q);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int n = 1;
    int q;
    int *arr = new int[n];
    cin >> q;
    arr[n - 1] = q;

    while(true)
    {
        cin >> q;
        arr = foo(arr , n, q);
        n++;
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << ", ";
        }cout << endl;
    }
    return a.exec();
}


int *foo(int *oldarr, int n, int q)
{
    int *newArr = new int[n + 1];
    for (int i = 0; i < n; i++)
    {
        newArr[i] =  oldarr[i];
    }
    newArr[n] = q;

    delete [] oldarr;
    return newArr;
}
