#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <forward_list>
#include <iostream>
#include <memory>
#include <utility>

template <class K, class V>
class HashTable;

template <typename K, typename V>
std::ostream& operator<<(std::ostream& out, const HashTable<K,V> &table);

template <class K, class V>
class HashTable
{
public:
    HashTable(int size = 31);

    HashTable(const HashTable<K, V> &table);

    HashTable(HashTable<K, V> &&table);

    HashTable<K, V> operator=(const HashTable<K, V> &table);

    HashTable<K, V> operator=(HashTable<K, V> &&table);

    ~HashTable() = default;

    friend std::ostream& operator<< <> (std::ostream& out, const HashTable<K,V> &table);

    bool isEmpty() const { return size == 0; }

    bool contains(const K& key) const;

    void insert(const K& key, const V& value);

    typedef std::forward_list<std::pair<K, V>>* iterator;

    typedef const std::forward_list<std::pair<K, V>>* const_iterator;

    iterator begin() { return &table[0]; }

    const_iterator begin() const { return &table[0]; }

    iterator end() { return &table[size]; }

    const_iterator end() const { return &table[size]; }

private:
    int hash(const K& key);
    std::unique_ptr<std::forward_list<std::pair<K, V>>[]> table;  // array of forward_lists containing pairs
    int capacity;  // not complete size, just size of array (that contains linked lists)
    int size;
};

template <typename K, typename V>
HashTable<K, V>::HashTable(int size)
    : table(std::make_unique<std::forward_list<std::pair<K, V>>[]>(size)), capacity(size), size(0)
{
}

template <typename K, typename V>
std::ostream& operator<<(std::ostream& out, const HashTable<K,V> &table)
{
    out << "HashTable:\n";
    for (const auto& list : table)
    {
        out << "[";

        for (const auto& pair : list)
        {
            out << "(" << pair.first << " -> " << pair.second << ") ";
        }

        out << "]\n";
    }

    return out;
}

#endif
