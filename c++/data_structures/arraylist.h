#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <memory>
#include <stdexcept>


namespace datastructures
{
    constexpr std::size_t defaultCapacity = 23;

    template <class T>
    class ArrayList {
      public:
        // Default Constructor. Optionally take in initial capacity.
        ArrayList(std::size_t capacity = defaultCapacity);

        // Copy Constructor. Delete to avoid shallow copy.
        ArrayList(const ArrayList<T> &arrayList) = delete;

        // Move Constructor
        ArrayList(ArrayList<T> &&arrayList);

        // Copy assignment. Delete to avoid shallow copy.
        ArrayList& operator=(const ArrayList<T> &arrayList) = delete;

        // Move assignment
        ArrayList& operator=(ArrayList<T> &&arrayList);

        // Destructor. Virtual in case this class is used as base class.
        virtual ~ArrayList();

        bool empty() const { return mSize == 0; };

        size_t size() const { return mSize; };

        size_t capacity() const { return mCapacity; };

        T& at(size_t index);

        const T& at(size_t index) const;

        T& operator[](size_t index);

        const T& operator[](size_t index) const;

        T* data() { return mArray; };

        const T* data() const { return mArray; };

        // Reserves storage.
        void reserve(size_t newCapacity);

        void clear();

        void pushBack(const T &item);

        void popBack();

        typedef T* iterator;

        typedef const T* const_iterator;

        iterator begin() { return &mArray[0]; }

        const_iterator begin() const { return &mArray[0]; }

        iterator end() { return &mArray[mSize]; }

        const_iterator end() const { return &mArray[mSize]; }

      private:
        T *mArray;
        std::size_t mSize {0};
        std::size_t mCapacity {0};
    };

    template<class T>
    ArrayList<T>::ArrayList(std::size_t capacity)
        : mArray(new T[capacity]), mCapacity(capacity)
    {        
    }

    template <class T>
    ArrayList<T>::ArrayList(ArrayList<T> &&arrayList)
    {
        mCapacity = arrayList.mCapacity;
        mSize = arrayList.mSize;
        mArray = std::move(arrayList.mArray);
        arrayList.mArray = nullptr;
        arrayList.mCapacity = 0;
        arrayList.mSize = 0;
    }

    template <class T>
    ArrayList<T>& ArrayList<T>::operator=(ArrayList<T> &&arrayList)
    {
        if (this == &arrayList) {
            return *this;
        }

        // release any previously owned resource
        delete[] mArray;

        mCapacity = arrayList.mCapacity;
        mSize = arrayList.mSize;
        mArray = std::move(arrayList.mArray);
        arrayList.mArray = nullptr;
        arrayList.mCapacity = 0;
        arrayList.mSize = 0;

        return *this;
    }

    template <class T>
    ArrayList<T>::~ArrayList()
    {
        if (mArray) {
            delete[] mArray;
        }
    }

    template <class T>
    T& ArrayList<T>::at(size_t index)
    {
        if (index >= mSize || index < 0) {
            throw std::out_of_range("index out of range");
        }
        return mArray[index];
    }

    template <class T>
    const T& ArrayList<T>::at(size_t index) const
    {
        if (index >= mSize || index < 0) {
            throw std::out_of_range("index out of range");
        }
        return mArray[index];
    }

    template <class T>
    T& ArrayList<T>::operator[](size_t index)
    {
        return at(index);
    }

    template <class T>
    const T& ArrayList<T>::operator[](size_t index) const
    {
        return at(index);
    }

    template <class T>
    void ArrayList<T>::clear()
    {
        while(mSize >0) {
            popBack();
        }
    }
    
    template <class T>
    void ArrayList<T>::pushBack(const T &item)
    {
        if (mSize == mCapacity) {
            // double capcity of array
            reserve(mCapacity << 1);
        }

        mArray[mSize++] = item;
    }

    template <class T>
    void ArrayList<T>::popBack()
    {
        if (mSize == 0) {
            return;
        }

        --mSize;
    }

    template <class T>
    void ArrayList<T>::reserve(size_t newCapacity)
    {        
        T* mNewArray(new T[newCapacity]);

        for (unsigned int i = 0; i < mSize; ++i) {
            mNewArray[i] = mArray[i];
        }

        delete[] mArray;
        mCapacity = newCapacity;
        mArray = std::move(mNewArray);
    }
}

#endif