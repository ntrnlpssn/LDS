#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#endif // DOUBLYLINKEDLIST_H

#include <iostream>
#include<QList>

template<class T>
class DoublyLinkedList
{
public:
    struct Node
    {
        T data;
        Node* next;
        Node* prev;
        Node(T val): data(val), next(nullptr), prev(nullptr) {}
    };
    Node *head, *tail;

      DoublyLinkedList(): head(nullptr), tail(nullptr) {}

     ~DoublyLinkedList()
      {
          Node *tmp = nullptr;
          while (head)
          {
              tmp = head;
              head = head->next;
              delete tmp;
          }
          head = nullptr;
      }

      void addBegin(T val)
      {
          Node *node = new Node(val);
        //  Node *tmp = head;
          if (head == nullptr)
          {
              head = node;
              tail = node;
          }
          else
          {
              node->next = head;
              head = node;
              node->next->prev = node;
          }
      }

      void addEnd(T val)
      {
          Node *node = new Node(val);
          if(tail == nullptr)
          {
              head = node;
              tail = node;
          }
          else
          {
              tail->next = node;
              node->prev = tail;
              tail = node;
          }
      }

      void deleteNode(Node *node)
      {
           Node *tmp = head;

           while(tmp != node && tmp != nullptr)
           {
               tmp = tmp->next;
           }
           if(tmp == head)
           {
               head = head->next;
               head->prev = nullptr;
           }
           else if(tmp == tail)
           {
               tail = tmp->prev;
               tail->next = nullptr;
           }
           else
           {
               tmp->prev->next = tmp->next;
               tmp->next->prev = tmp->prev;
           }
           delete tmp;
       }

      void insertBefore(Node *node, T val)
      {
          if(node == head)
          {
              addBegin(val);
              return;
          }

          Node *newNode = new Node(val);
          node->prev->next = newNode;
          newNode->prev = node->prev;
          node->prev = newNode;
          newNode->next = node;
      }

      void insertAfter(Node *node, T val)
      {
          if(node == tail)
          {
              addEnd(val);
              return;
          }

          Node *newNode = new Node(val);
          node->next->prev = newNode;
          newNode->next = node->next;
          node->next = newNode;
          newNode->prev = node;
      }

      Node *findVal(T val) //returns node of the given number
      {
          Node *tmp = head;
          while(tmp->data != val && tmp != nullptr)
          {
              tmp = tmp->next;
          }
          return tmp;
       }

      template <class U>
      friend std::ostream & operator<<(std::ostream & os, const DoublyLinkedList<U> & dll){
       dll.display(os);
       return os;
      }

      private:

    void display(std::ostream& out = std::cout) const
    {
         Node *node = head;
         while(node != nullptr)
         {
             out << node->data << " ";
             node = node->next;
         }
     }

};
