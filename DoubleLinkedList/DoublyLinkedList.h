#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#endif // DOUBLYLINKEDLIST_H

#include <ostream>
#include <sstream>
#include <string>
#include <algorithm>

template <class T>
class DoublyLinkedList;

template <class Type>
std::ostream& operator<<(std::ostream&, const DoublyLinkedList<Type>&);

template <class Type>
std::istream& operator>>(std::istream&, DoublyLinkedList<Type>&);

template <class Type>
std::wostream& operator<<(std::wostream&, const DoublyLinkedList<Type>&);

template <class Type>
std::wistream& operator>>(std::wistream&, DoublyLinkedList<Type>&);

template <class T>
std::wstring ToString(const DoublyLinkedList<T>& obj);


template <class Type>
bool operator==(const DoublyLinkedList<Type>& lha, const DoublyLinkedList<Type>& rha);

template <class T>
class Iterator;

template<class T>
class ListItem
{
public:
    T value;
private:
    friend class DoublyLinkedList<T>;
    friend class Iterator<T>;

    friend std::ostream& operator<< <T> (std::ostream&, const DoublyLinkedList<T>&);
    friend std::wostream& operator<< <T> (std::wostream&, const DoublyLinkedList<T>&);

    friend std::istream& operator>> <T> (std::istream&, DoublyLinkedList<T>&);
    friend std::wistream& operator>> <T> (std::wistream&, DoublyLinkedList<T>&);

    friend bool operator== <T> (const DoublyLinkedList<T>& lha, const DoublyLinkedList<T>& rha);

    explicit ListItem(const T& value);
    ListItem* next;
    ListItem* prev;
};

template <class T>
ListItem<T>::ListItem(const T& value) : value(value), next(nullptr), prev(nullptr)
{
}

template<class T>
class DoublyLinkedList
{
public:
    DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList<T>& list);

    DoublyLinkedList(std::initializer_list<T> other);

    DoublyLinkedList<T>& operator= (const DoublyLinkedList<T>& other);

    friend std::ostream& operator<< <T> (std::ostream&, const DoublyLinkedList<T>&);
    friend std::wostream& operator<< <T> (std::wostream&, const DoublyLinkedList<T>&);

    friend std::istream& operator>> <T> (std::istream&, DoublyLinkedList<T>&);
    friend std::wistream& operator>> <T> (std::wistream&, DoublyLinkedList<T>&);

    friend bool operator== <T> (const DoublyLinkedList<T>& lha, const DoublyLinkedList<T>& rha);

    ~DoublyLinkedList();

    void addBegin(const T& val);
    void addEnd(const T& val);
    void removeFirst();
    void removeLast();
    void deleteNode(ListItem<T>* node);
    void insertBefore(ListItem<T>* node, const T& val);
    void insertAfter(ListItem<T>* node, const T& val);

    ListItem<T>* findVal(const T& val); //returns node of the given value

    Iterator<T> begin();
    Iterator<T> end();

    Iterator<const T> cbegin() const;
    Iterator<const T> cend() const;

    int count();

private:

    ListItem<T>* head, * tail;
    void destroy();
    void copyElements(const DoublyLinkedList<T>&);
    int _count;

};


template <class T>
std::istream& operator>> (std::istream& in, DoublyLinkedList<T>& list)
{
    if (in.peek() == '\n' || in.eof())
    {
        return in;
    }

    T value;
    while (in >> value)
    {
        list.addEnd(value);

        if (in.peek() == '\n' || in.eof())
        {
            break;
        }
    }

    return in;
}

template <class T>
std::wistream& operator>> (std::wistream& in, DoublyLinkedList<T>& list)
{
    T value;
    while (in >> value)
    {
        list.addEnd(value);
        if (in.peek() == L'\n' || in.eof())
        {
            break;
        }
    }
    return in;
}

template <class T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr), _count(0)
{
}

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList& list)
    : DoublyLinkedList()
{
    this->copyElements(list);
}

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(std::initializer_list<T> other)
    : DoublyLinkedList()
{
    std::for_each(other.begin(), other.end(), [this](const T item) { this->addEnd(item); });
}

template <class T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& other)
{
    if (*this != other)
    {
        this->destroy();
        this->copyElements(other);
    }
    return *this;
}

template <class T>
bool operator==(DoublyLinkedList<T>& lha, DoublyLinkedList<T>& rha)
{
    if (lha.count() != rha.count()) { return false; }

    return std::equal(lha.begin(), lha.end(), rha.begin());
}

template <class T>
bool operator==(const DoublyLinkedList<T>& lha, const DoublyLinkedList<T>& rha)
{
    auto current_lha = lha.head;
    auto current_rha = rha.head;
    while (current_lha != nullptr && current_rha != nullptr)
    {
        if (current_lha->value != current_rha->value)
        {
            return false;
        }

        current_lha = current_lha->next;
        current_rha = current_rha->next;
    }
    return current_lha == current_rha;
}

template <class T>
std::ostream& operator<< (std::ostream& out, const DoublyLinkedList<T>& list)
{
    if (list.head == nullptr)
    {
        return out << " ";
    }

    //out << "{ ";
    auto current = list.head;
    while (current->next != nullptr)
    {
        out << current->value << " ";
        current = current->next;
    }
    return out << current->value; // << " }";
}

template <class T>
std::wostream& operator<< (std::wostream& out, const DoublyLinkedList<T>& list)
{
    if (list.cbegin().current == nullptr)
    {
        return out << L" ";
    }

    // out << L"{ ";
    auto current = list.head;
    while (current->next != nullptr)
    {
        // TODO: проблема с wostream << string
        out << current->value << L" ";
        current = current->next;
    }
    // TODO: проблема с wostream << string
    return out << current->value; // << L" }";
}

template <class T>
std::wstring ToString(const DoublyLinkedList<T>& obj)
{
    std::wstringstream out;
    out << obj;
    return out.str();
}

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    ListItem<T>* tmp = nullptr;
    while (head)
    {
        tmp = head;
        head = head->next;
        delete tmp;
    }
    head = nullptr;
}

template<class T>
void DoublyLinkedList<T>::addBegin(const T& val)
{
    ListItem<T>* node = new ListItem<T>(val);
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
    _count++;
}

template<class T>
void DoublyLinkedList<T>::addEnd(const T& val)
{
    ListItem<T>* node = new ListItem<T>(val);
    if (tail == nullptr)
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
    _count++;
}


template<class T>
void DoublyLinkedList<T>::removeFirst()
{
    this->head = this->head->next;
    delete this->head->prev;
    this->head->prev = nullptr;
    _count--;
}

template<class T>
void DoublyLinkedList<T>::removeLast()
{
    this->tail = this->tail->prev;
    delete this->tail->next;
    this->tail->next = nullptr;
    _count--;
}

template<class T>
void DoublyLinkedList<T>::deleteNode(ListItem<T>* node)
{
    ListItem<T>* tmp = head;

    while (tmp != node && tmp != nullptr)
    {
        tmp = tmp->next;
    }
    if (tmp == nullptr)
    {
        return;
    }

    if (tmp == head)
    {
        head = head->next;
        head->prev = nullptr;
    }
    else if (tmp == tail)
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
    _count--;
}

template<class T>
void DoublyLinkedList<T>::insertBefore(ListItem<T>* node, const T& val)
{
    if (node == head)
    {
        addBegin(val);
        return;
    }

    ListItem<T>* newNode = new ListItem<T>(val);
    node->prev->next = newNode;
    newNode->prev = node->prev;
    node->prev = newNode;
    newNode->next = node;
    _count++;
}

template<class T>
void DoublyLinkedList<T>::insertAfter(ListItem<T>* node, const T& val)
{
    if (node == tail)
    {
        addEnd(val);
        return;
    }

    ListItem<T>* newNode = new ListItem<T>(val);
    node->next->prev = newNode;
    newNode->next = node->next;
    node->next = newNode;
    newNode->prev = node;
    _count++;
}

template<class T>
ListItem<T>* DoublyLinkedList<T>::findVal(const T& val) //returns node of the given number
{
    ListItem<T>* tmp = head;
    while (tmp->value != val && tmp != nullptr)
    {
        tmp = tmp->next;
    }
    return tmp;
}

template <class T>
Iterator<T> DoublyLinkedList<T>::begin()
{
    return Iterator<T>(this->head);
}

template <class T>
Iterator<T> DoublyLinkedList<T>::end()
{
    return Iterator<T>(this->tail);
}

template <class T>
Iterator<const T> DoublyLinkedList<T>::cbegin() const
{
    return Iterator<const T>(reinterpret_cast<ListItem<const T>*>(this->head));
}


template <class T>
Iterator<const T> DoublyLinkedList<T>::cend() const
{
    return Iterator<const T>(reinterpret_cast<ListItem<const T>*>(this->tail));
}

template <class T>
int DoublyLinkedList<T>::count()
{
    return _count;
}

template <class T>
void DoublyLinkedList<T>::destroy()
{
    while (this->head != nullptr)
    {
        this->removeFirst();
    }
}

template <class T>
void DoublyLinkedList<T>::copyElements(const DoublyLinkedList<T>& other)
{
    auto current = other.head;
    while (current != nullptr)
    {
        this->addBegin(current->value);
        current = current->next;
    }
}



template <class T>
class Iterator
{
public:
    explicit Iterator(ListItem<T>* item);
    Iterator(const Iterator<T>& other);

    bool operator == (Iterator<T> const& other) const;
    bool operator != (Iterator<T> const& other) const;
    Iterator<T> operator++();
    Iterator<T> operator--();
    T& operator *();
    T& operator *() const;

    friend class DoublyLinkedList<T>;

    ListItem<T>* current;
};

template <class T>
Iterator<T>::Iterator(ListItem<T>* item)
{
    this->current = item;
}

template<class T>
Iterator<T>::Iterator(const Iterator<T>& other)
{
    this->current = other.current;
}

template <class T>
bool Iterator<T>::operator==(Iterator<T> const& other) const
{
    return (this->current == other.current);
}

template <class T>
bool Iterator<T>::operator!=(Iterator<T> const& other) const
{
    return (this->current != other.current);
}

template <class T>
Iterator<T> Iterator<T>::operator++()
{
    this->current = this->current->next;
    return Iterator<T>(this->current);
}

template <class T>
Iterator<T> Iterator<T>::operator--()
{
    this->current = this->current->prev;
    return Iterator<T>(this->current);
}

template <class T>
T& Iterator<T>::operator*()
{
    return this->current->value;
}

template <class T>
T& Iterator<T>::operator*() const
{
    return this->current->value;
}
