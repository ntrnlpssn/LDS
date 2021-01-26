#include <QCoreApplication>
#include <iostream>
#include <fstream>

#include "DoublyLinkedList.h"

using namespace std;

void file_output_commented();
int file_input(const string& filename);

template <typename T>
int file_output(const string& filename, const DoublyLinkedList<T>& data);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    DoublyLinkedList<int> l1;
    l1.addBegin(3);
    l1.addEnd(5);
    auto someNode = l1.end().current;
    l1.addEnd(12);
    l1.addBegin(6);
    l1.addEnd(88);
    cout << l1 <<"\n";
    l1.insertBefore(someNode, 77);
    l1.insertAfter(someNode, 90);
    someNode->value = 1488;
    cout<<l1<<"\n";
    l1.deleteNode(someNode);
    cout<<l1<<"\n";
    auto anotherNode = l1.findVal(6);
    anotherNode->value = 99;
    cout<<l1<<"\n";
    l1.deleteNode(anotherNode);
    cout<<l1<<"\n";
    file_output("list1.txt",l1);
    file_input("list1.txt");
    file_output_commented();
    file_input("result.txt");

    system("PAUSE");

    return a.exec();
}

template <typename T>
int file_output(const string& filename, const DoublyLinkedList<T>& data)
{
    ofstream out_file(filename.c_str(), ios_base::out);

    if (!out_file.is_open())
    {
        cerr << "Error! Unable to open output file: " << filename << endl;
        // C-style!
        return -1;
    }

    out_file << data << endl;
    out_file.close();

    return 0;
}

int file_input(const string& filename)
{
    DoublyLinkedList<int> tmp;

    ifstream in_file(filename, ios_base::in);

    if (!in_file.is_open())
    {
        cerr << "Error! Unable to open output file: " << filename << endl;
        // C-style!
        return -1;
    }

    in_file >> tmp;

    in_file.close();

    cout << "list = " << tmp << ";" << endl;
    return 0;
}

void file_output_commented()
{
    const DoublyLinkedList<int> tmp = { 1, 2, 3, 4, 5 };
    cout << tmp << endl;

    const auto code = file_output("result.txt", tmp);
    cout << "code = " << code << endl;

    cout << "END!" << endl;
}
