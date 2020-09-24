#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstddef>
#include <memory>


namespace datastructures
{
    template <class T>
    class LinkedList {      
      private:
        struct Node {
            Node(T data) : mData(data), mNext(nullptr)
            {
            }
            
            T mData;
            Node* mNext;
        };

      public:
        class const_iterator {
          public:
            const_iterator(): mCurrent(nullptr)
            {                
            }

            const T& operator*() const { return mCurrent->mData; }

            const_iterator& operator++() 
            {
                mCurrent = mCurrent->mNext; 
                return *this;
            }

            const_iterator& operator++(int) 
            {
                const_iterator old = *this;
                ++(*this); 
                return old;
            }

            bool operator==(const const_iterator &rhs) const { return mCurrent == rhs.mCurrent; }

            bool operator!=(const const_iterator &rhs) const { return !(*this == rhs); }

          protected:
            const_iterator(Node *p) : mCurrent(p)
            {                
            }

            Node *mCurrent;
            friend class LinkedList<T>;
        };

        class iterator : public const_iterator {
          public:
            iterator()
            {                
            }

            T& operator*() { return const_iterator::mCurrent->mData; }

            const T& operator*() const { return const_iterator::operator*(); }

            iterator& operator++()
            {
                const_iterator::mCurrent = const_iterator::mCurrent->mNext;
                return *this;
            }

            iterator& operator++(int)
            {
                iterator old = *this;
                ++(*this);
                return old;
            }

          protected:
            iterator(Node *p) : const_iterator(p)
            {                
            }

            friend class LinkedList<T>;
        };

        LinkedList();

        // Copy Constructor. Delete to avoid shallow copy.
        LinkedList(const LinkedList<T> &list) = delete;

        // Move Constructor
        LinkedList(LinkedList<T> &&list);

        // Copy assignment. Delete to avoid shallow copy.
        LinkedList& operator=(const LinkedList<T> &list) = delete;

        // Move assignment
        LinkedList& operator=(LinkedList<T> &&list);

        ~LinkedList();

        bool empty() const { return mSize == 0; }

        std::size_t size() const { return mSize; }

        T& front() { return *begin(); }

        const T& front() const { return *begin(); }

        T& back() { return *--end(); }

        const T& back() const { return *--end(); }

        void clear();

        void pushFront(const T &data);

        T popFront();

        void remove(const T &value);

        iterator begin() { return iterator(mHead); }

        const_iterator begin() const { return iterator(mHead); }

        iterator end() { return iterator(mTail); }

        const_iterator end() const { return iterator(mTail); }

      private:
        Node *mHead;
        Node *mTail;
        std::size_t mSize;
    };

    template <class T>
    LinkedList<T>::LinkedList() : mHead(nullptr), mSize(0)
    {
        mTail = mHead;
    }

    template <class T>
    LinkedList<T>::LinkedList(LinkedList<T> &&list)
    {
        mSize = list.mSize;
        mHead = list.mHead;
        list.mHead = nullptr;
        list.mSize = 0;
    }

    template <class T>
    LinkedList<T>& LinkedList<T>::operator=(LinkedList<T> &&list)
    {
        if (this == &list) {
            return *this;
        }

        mSize = list.mSize;
        mHead = list.mHead;
        list.mHead = nullptr;
        list.mSize = 0;

        return *this;
    }


    template <class T>
    LinkedList<T>::~LinkedList()
    {
        while (mHead != mTail) {
            Node *tmp = mHead;
            mHead = mHead->mNext;
            delete tmp;
        }
    }

    template <class T>
    void LinkedList<T>::clear()
    {
        while (mSize > 0) {
            popFront();
        }
    }

    template <class T>
    void LinkedList<T>::pushFront(const T &data)
    {
        Node* newNode = new Node(data);

        if (mSize == 0)
        {
            newNode->mNext = mTail;
        }
        else
        {
            newNode->mNext = mHead;
        }

        mHead = newNode;
        ++mSize;
    }

    template <class T>
    T LinkedList<T>::popFront()
    {
        if (mSize == 0) {
            throw std::out_of_range("index out of range");
        }

        --mSize;

        T tmp = mHead->mData;
        Node *next = mHead->mNext;
        delete mHead;
        mHead = next;

        return tmp;
    }

    template <class T>
    void LinkedList<T>::remove(const T &value)
    {
        Node *itr = mHead;
        if (mHead->mData == value) {
            mHead = mHead->mNext;
            delete itr;
        } else {
            while (itr != mTail) {
                if (itr->mNext->mData == value) {
                    Node *tmp = itr->mNext;
                    itr->mNext = itr->mNext->mNext;
                    delete tmp;
                }
            }
        }
    }
}

#endif
