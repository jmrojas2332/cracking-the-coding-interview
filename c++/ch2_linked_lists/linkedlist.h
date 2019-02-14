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
        std::unique_ptr<Node> next;
    };

    std::unique_ptr<Node> head;

    std::size_t size;
};

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), size(0)
{
}

template <typename T>
void LinkedList<T>::pushFront(const T &data)
{
    
}

#endif
