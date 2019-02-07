#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <cassert>
#include <cstddef>
#include <iostream>
#include <memory>

template <class T>
class ArrayList;

template <typename T>
std::ostream& operator<<(std::ostream &out, const ArrayList<T> &array);

template <class T>
class ArrayList
{
public:
    ArrayList(const int size = 23);

    ArrayList(const ArrayList<T> &array);

    ~ArrayList();

    friend std::ostream& operator<< <> (std::ostream &out, const ArrayList<T> &array);

    T& operator[](const std::size_t index);

    const T& operator[](const std::size_t index) const;

    void append(const T &value);

    inline std::size_t getCapacity() const { return capacity; }

    inline std::size_t getLength() const { return length; }


private:
    std::unique_ptr<T[]> array;
    std::size_t capacity;
    std::size_t length;
};

template <typename T>
ArrayList<T>::ArrayList(int size)
    : array(new T[size]), capacity(size), length(0) {}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T> &array)
    : capacity(array.getCapacity()), length(array.getLength())
{
    this->array = std::make_unique<T[capacity]>;  // initialize smart ptr

    for (int i = 0; i < length; ++i)
    {
        this->array[i] = array[i];
    }
}

template <typename T>
ArrayList<T>::~ArrayList() {}

template <typename T>
std::ostream& operator<<(std::ostream &out, const ArrayList<T> &array)
{
    out << "ArrayList(";

    for (unsigned int i = 0; i < array.getLength(); ++i)
    {
        out << array.array[i] << " ";
    }

    if (array.getLength() > 0)
        out << '\b';  // remove last space

    out << ")";
    return out;
}

template <typename T>
T& ArrayList<T>::operator[](const std::size_t index)
{
    assert(index >= 0 && index < length);

    return array[index];
}

template <typename T>
const T& ArrayList<T>::operator[](const std::size_t index) const
{
    assert(index >= 0 && index < length);

    return array[index];
}

template <typename T>
void ArrayList<T>::append(const T &val)
{
    if (length == capacity)
        //resize();

    array[length] = val;
    ++length;
}

#endif
