#include <QCoreApplication>
#include <iostream>

#include "DoublyLinkedList.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    DoublyLinkedList<int> l1;
      l1.addBegin(3);
      l1.addEnd(5);
      l1.addEnd(12);
      l1.addBegin(6);
      l1.addEnd(88);
      cout << l1 <<"\n";
      l1.deleteVal(12);
      cout<<l1<<"\n";
//      l1.insertBefore(next,77);
      cout<<l1<<"\n";

     system("PAUSE");

    return a.exec();
}
