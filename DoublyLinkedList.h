#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#endif // DOUBLYLINKEDLIST_H

#include <iostream>
#include<QList>

template<class T>
class DoublyLinkedList
{   
    struct Node
        {
            T data;
            Node* next;
            Node* prev;
            Node(T val): data(val), next(nullptr), prev(nullptr) {}
        };
        Node *head, *tail;

public:
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
          if(tail->next == nullptr)
          {
              tail->next = node;
              tail = node;
          }
      }

      void deleteVal(T val)
          {
               Node* find = findVal(val);
               Node *tmp = head;

               if(tmp == find)
               {
                   head = tmp->next;
               }
               else
               {
                   while(find != nullptr)
                   {
                       if(tmp->next == find)
                       {
                           tmp->next = find->next;
                           find->next->prev = tmp;
                           delete find;
                           return;
                       }
                       tmp = tmp->next;
                   }
               }
           }

      void insertBefore(Node *position,T val)
      {
          Node *node = new Node(val);
        //  Node *tmp = position ;
          if(position == 0)
          {
              node->prev=nullptr;
              node->next = head;
              head = node;
//              head = node;
//              node->next->prev = node;
//              Node* find = sizeList();
//              std::cout<< find;
          }
         else
          {
              node->next = position;
              node->prev = position->prev;
              position->prev = node;
          }
      }

      void insertAfter(Node *position,T val)
      {
          Node *node = new Node(val);
          node->prev = position;
          node->next = position->next;
          position->next= node;

          if(position == nullptr)
              tail =node;
      }


      template <class U>
      friend std::ostream & operator<<(std::ostream & os, const DoublyLinkedList<U> & dll){
       dll.display(os);
       return os;
      }

      private:

      Node *findVal(T n) //returns node of the given number
      {
           Node *node = head;
           while(node != nullptr)
           {
                 if(node->data == n)
                       return node;

                 node = node->next;
           }
           std::cerr << "No such element in the list \n";
           return nullptr;
       }

//      Node *sizeList()
//      {
//           Node *node = head;
//           int count=0;
//           while(node != nullptr)
//           {
//               count++;
//               node = node->next;
//               if (node->next == nullptr)
//               return count;
//           }
//           std::cerr << "No such element in the list \n";
//           return nullptr;
//       }

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
