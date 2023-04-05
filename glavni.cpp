#include "CSortList.h"

int main()
{
    CSortList list;

    list.AddToHead(3);
    list.AddToHead(1);
    list.AddToHead(4);
    list.AddToHead(2);

    cout << "Before sorting:" << endl;
    list.Display();

    cout << "Ascending order:" << endl;
    list.InsertionSort(true);
    list.Display();

    cout << "Descending order:" << endl;
    list.InsertionSort(false);
    list.Display();

    return 0;
}