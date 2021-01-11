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
      DoublyLinkedList<int>::Node *someNode = l1.tail;
      l1.addEnd(12);
      l1.addBegin(6);
      l1.addEnd(88);
      cout << l1 <<"\n";
      l1.insertBefore(someNode, 77);
      l1.insertAfter(someNode, 90);
      someNode->data = 1488;
      cout<<l1<<"\n";
      l1.deleteNode(someNode);
      cout<<l1<<"\n";
      auto anotherNode = l1.findVal(6);
      anotherNode->data = 99;
      cout<<l1<<"\n";
      l1.deleteNode(anotherNode);
      cout<<l1<<"\n";

     system("PAUSE");

    return a.exec();
}
