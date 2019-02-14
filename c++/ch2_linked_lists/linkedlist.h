#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cassert>
#include <cstddef>
#include <iostream>
#include <memory>

template <class T>
class LinkedList;

template <typename T>
std::ostream& operator<<(std::ostream &out, const LinkedList<T> &list);

template <class T>
class LinkedList
{
public:
    LinkedList();

    LinkedList(const LinkedList<T> &list);

    LinkedList(LinkedList<T> &&list);

    LinkedList<T> operator=(const LinkedList<T> &list);

    LinkedList<T> operator=(LinkedList<T> &&list);

    ~LinkedList() = default;

    friend std::ostream& operator<< <> (std::ostream &out, const LinkedList<T> &list);

    void pushFront(const T &data);

    T popFront();

    std::size_t getSize() const { return size; }

    bool empty() const { return size == 0; }

private:
    struct Node
    {
        T data;
        std::shared_ptr<Node> next;

        Node(int d) : data(d), next(nullptr)
        {
        }
    };

    void printList(std::ostream &out) const;

    std::shared_ptr<Node> head;

    std::size_t size;
};

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), size(0)
{
}

template <typename T>
std::ostream& operator<<(std::ostream &out, const LinkedList<T> &list)
{
    list.printList(out);

    return out;
}

template <typename T>
void LinkedList<T>::pushFront(const T &data)
{
    if (size == 0)
    {
        head = std::make_shared<Node>(data);
    }
    else
    {
        std::shared_ptr<Node> newNode = std::make_shared<Node>(data);
        newNode->next = head;
        head = newNode;
    }

    ++size;
}

template <typename T>
T LinkedList<T>::popFront()
{
    assert(size > 0);

    --size;

    T tmp = head->data;
    Node *next = head->next.get();
    head.reset(next);

    return tmp;
}

template <typename T>
void LinkedList<T>::printList(std::ostream &out) const
{
    out << "List(";
    std::shared_ptr<Node> itr = head;
    while (itr != nullptr)
    {
        out << itr->data << "->";
        itr = itr->next;
    }
    out << "null)";
}

#endif
