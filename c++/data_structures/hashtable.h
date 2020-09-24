#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <functional>
#include <memory>
#include <utility>

#include "linkedlist.h"


namespace datastructures
{
    template <class Key, class T>
    class HashTable {
      public:
        // Default Constructor. Optionally take in initial bucket size.
        HashTable(std::size_t numberBuckets = defaultCapacity);

        // Copy Constructor. Delete to avoid shallow copy.
        HashTable(const HashTable<Key, T> &hashTable) = delete;

        // Move Constructor
        HashTable(HashTable<Key, T> &&hashTable);

        // Copy assignment. Delete to avoid shallow copy.
        HashTable& operator=(const HashTable<Key, T> &hashTable) = delete;

        // Move assignment
        HashTable& operator=(HashTable<Key, T> &&hashTable);

        // Destructor.
        ~HashTable() = default;

        bool empty() const { return mSize == 0; }

        std::size_t size() const { return mSize; }

        std::size_t numBuckets() const { return mNumBuckets; }

        T& at(const Key& key);

        const T& at(const Key& key) const;

        T& operator[](const Key& key);

        const T& operator[](const Key& key) const;

        bool contains(const Key& key) const;

        void insert(const Key& key, const T& value);

        void erase(const Key& key);

        typedef LinkedList<std::pair<Key, T>>* iterator;

        typedef const LinkedList<std::pair<Key, T>>* const_iterator;

        iterator begin() { return &mTable[0]; };

        const_iterator begin() const { return &mTable[0]; };

        iterator end() { return &mTable[mNumBuckets-1]; };

        const_iterator end() const { return &mTable[mNumBuckets-1]; };

      private:
        LinkedList<std::pair<Key, T>> *mTable;
        std::hash<Key> mHash;
        std::size_t mSize {0};
        std::size_t mNumBuckets {0};
    };

    template <class Key, class T>
    HashTable<Key, T>::HashTable(std::size_t numberBuckets) : 
        mTable(new LinkedList<std::pair<Key, T>>[numberBuckets]), 
        mNumBuckets(numberBuckets)
    {
    }

    template <class Key, class T>
    HashTable<Key, T>::HashTable(HashTable<Key, T> &&hashTable)
    {
        mSize = hashTable.mSize;
        mNumBuckets = hashTable.mNumBuckets;
        mTable = std::move(hashTable.mTable);
        hashTable.mTable = nullptr;        
        hashTable.mSize = 0;
        hashTable.mNumBuckets = 0;
    }

    template <class Key, class T>
    HashTable<Key, T>& HashTable<Key, T>::operator=(HashTable<Key, T> &&hashTable)
    {
        if (this == &hashTable) {
            return *this;
        }

        // release any previously owned resources
        for (int i = 0; i < mNumBuckets; ++i)
        {
            delete mTable[i];
        }
        delete[] mTable;

        mSize = hashTable.mSize;
        mNumBuckets = hashTable.mNumBuckets;
        mTable = std::move(hashTable.mTable);
        hashTable.mTable = nullptr;
        hashTable.mSize = 0;
        hashTable.mNumBuckets = 0;

        return *this;
    }

    template<class Key, class T>
    bool HashTable<Key, T>::contains(const Key& key) const
    {
        const auto &bucket = mTable[mHash(key) % mNumBuckets];
        for (const auto &pair : bucket) {
            if (pair.first == key) {
                return true;
            }
        }

        return false;
    }

    template <class Key, class T>
    void HashTable<Key, T>::insert(const Key& key, const T& value)
    {
        mTable[mHash(key) % mNumBuckets].pushFront(std::make_pair(key, value));
        ++mSize;
    }

    template <class Key, class T>
    void HashTable<Key, T>::erase(const Key& key)
    {
        auto &bucket = mTable[mHash(key) % mNumBuckets];
        for (auto &pair : bucket) {
            if (pair.first == key) {
                bucket.remove(pair);
                return;
            }
        }        
    }
}

#endif
