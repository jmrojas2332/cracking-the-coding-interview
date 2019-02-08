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
    ArrayList(const std::size_t capacity = 23);

    ~ArrayList();

    friend std::ostream& operator<< <> (std::ostream &out, const ArrayList<T> &array);

    T& operator[](const std::size_t index);

    const T& operator[](const std::size_t index) const;

    void append(const T &value);

    void resize(std::size_t capacity);

    std::size_t getCapacity() const { return capacity; }

    std::size_t getSize() const { return size; }

    typedef T* iterator;

    typedef const T* const_iterator;

    iterator begin() { return &array[0]; }

    const_iterator begin() const { return &array[0]; }

    iterator end() { return &array[size]; }

    const_iterator end() const { return &array[size]; }

private:
    std::unique_ptr<T[]> array;
    std::size_t capacity;
    std::size_t size;
};

template <typename T>
ArrayList<T>::ArrayList(std::size_t capacity)
    : array(std::make_unique<T[]>(capacity)), size(0)
{
    this->capacity = capacity;
}

template <typename T>
ArrayList<T>::~ArrayList() {}

template <typename T>
std::ostream& operator<<(std::ostream &out, const ArrayList<T> &array)
{
    out << "ArrayList(";

    for (const auto &val : array)
    {
        out << val << " ";
    }

    if (array.getSize() > 0)
        out << '\b';  // remove trailing space of last element

    out << ")";
    return out;
}

template <typename T>
T& ArrayList<T>::operator[](const std::size_t index)
{
    assert(index >= 0 && index < capacity);

    return array[index];
}

template <typename T>
const T& ArrayList<T>::operator[](const std::size_t index) const
{
    assert(index >= 0 && index < capacity);

    return array[index];
}

template <typename T>
void ArrayList<T>::append(const T &val)
{
    if (size == capacity)
        resize(size * 2 + 1);  // make new array more than double in size

    array[size++] = val;
}

template <typename T>
void ArrayList<T>::resize(std::size_t capacity)
{
    auto new_array(std::make_unique<T[]>(capacity));

    for (unsigned int i = 0; i < capacity; ++i)
    {
        if (i < size)  // prevent index out of bounds on old array
            new_array[i] = array[i];
    }

    this->capacity = capacity;
    array = std::move(new_array);
}

#endif
