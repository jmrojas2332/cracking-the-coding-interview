#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <memory>
#include <utility>
#include <vector>

template <class K, class V>
class HashTable;

template <typename K, typename V>
std::ostream& operator<<(std::ostream& out, const HashTable<K,V> &table);

template <class K, class V>
class HashTable
{
public:
    HashTable(std::size_t capacity = 31);

    HashTable(const HashTable<K, V> &table);

    HashTable(HashTable<K, V> &&table);

    HashTable<K, V> operator=(const HashTable<K, V> &table);

    HashTable<K, V> operator=(HashTable<K, V> &&table);

    ~HashTable() = default;

    friend std::ostream& operator<< <> (std::ostream& out, const HashTable<K,V> &table);

    std::size_t getSize() const { return size; }

    std::size_t getCapacity() const { return capacity; }

    bool isEmpty() const { return size == 0; }

    bool contains(const K& key) const;

    void insert(const K& key, const V& value);

    typedef std::vector<std::pair<K, V>>* iterator;

    typedef const std::vector<std::pair<K, V>>* const_iterator;

    iterator begin() { return &table[0]; }

    const_iterator begin() const { return &table[0]; }

    iterator end() { return &table[capacity]; }

    const_iterator end() const { return &table[capacity]; }

private:
    std::hash<K> hash;
    std::unique_ptr<std::vector<std::pair<K, V>>[]> table;  // array of forward_lists containing pairs
    std::size_t capacity;  // not complete size, just size of array (that contains linked lists)
    std::size_t size;
};

template <typename K, typename V>
HashTable<K, V>::HashTable(std::size_t capacity)
    : table(std::make_unique<std::vector<std::pair<K, V>>[]>(capacity)), capacity(capacity), size(0)
{
}

template <typename K, typename V>
HashTable<K, V>::HashTable(const HashTable<K, V> &table)
{

}

template <typename K, typename V>
HashTable<K, V>::HashTable(HashTable<K, V> &&table)
{
    capacity = table.getCapacity();
    size = table.getSize();
    this->table = std::move(table.table);
    table.capacity = 0;
    table.size = 0;
}

template <typename K, typename V>
HashTable<K, V> HashTable<K, V>::operator=(const HashTable<K, V> &table)
{

}

template <typename K, typename V>
HashTable<K, V> HashTable<K, V>::operator=(HashTable<K, V> &&table)
{
    if (this == &table)  // self-copy check
    {
        return *this;
    }

    capacity = table.getCapacity();
    size = table.getSize();
    this->table = std::move(table.table);
    table.capacity = 0;
    table.size = 0;

    return *this;
}

template <typename K, typename V>
std::ostream& operator<<(std::ostream& out, const HashTable<K,V> &table)
{
    out << "HashTable:";
    for (const auto& list : table)
    {
        out << "\n[";

        for (const auto& pair : list)
        {
            out << "(" << pair.first << ", " << pair.second << "), ";
        }

        if (!list.empty())
        {
            out << "\b\b";
        }

        out << "]";
    }

    return out;
}

template <typename K, typename V>
bool HashTable<K, V>::contains(const K& key) const
{
    std::vector<std::pair<K, V>> &list = table[hash(key) % capacity];
    bool exists = false;

    for (const auto &val : list)
    {
        if (val.first == key)
        {
            exists = true;
        }
    }

    return exists;
}

template <typename K, typename V>
void HashTable<K, V>::insert(const K& key, const V& value)
{
    if (!contains(key))
    {
        table[hash(key) % capacity].push_back(std::make_pair(key, value));
        ++size;
    }
    else
    {
        std::vector<std::pair<K, V>> &list = table[hash(key) % capacity];

        for (auto &val : list)
        {
            if (val.first == key)
            {
                val.second = value;
            }
        }
    }
}

#endif
