#include <vector>
#include <stdexcept>
#include "Heap.h"
#ifndef HeapImpl_H
#define HeapImpl_H
/**
* @file HeapImpl.h
* A header file containing the
* implementation of the Heap interface.
* @author Mohammed Abdelbarry.
*/
/**
* The implementation of the heap interface.
* @author Mohammed Abdelbarry.
*/
template<typename Type, typename Comparator =  std::less_equal<Type>>
class HeapImpl: public Heap<Type, Comparator> {
public:
    /**
    * Default constructor.
    * Constructs a Heap.
    */
    HeapImpl() {

    }
    /**
    * Heap copy constructor.
    * Constructs a heap by copying all elements in a range.
    * @param first An iterator pointing to the first element in the
    * range.
    * @param last An iterator pointing to the element that comes after the last element
    * in the range.
    */
    template<typename Iterator>
    HeapImpl(Iterator first, Iterator last);
    /**
    * Returns the size of the heap.
    * @return The size of the heap.
    */
    inline int size() {
        return heap.size();
    }
    /**
    * Checks whether the heap is empty or not.
    * @return A boolean indicating whether the heap is empty or not.
    */
    inline bool isEmpty() {
        return heap.empty();
    }
    /**
    * Copies a range of elements into the heap.
    * @param first An iterator pointing to the first element in the
    * range.
    * @param last An iterator pointing to the element that comes after the last element
    * in the range.
    */
    template<typename Iterator>
    void copy(Iterator first, Iterator last);
    /**
    * Removes and returns the root of the heap.
    * @return The value at the root of the heap.
    * @throw std::underflow_error When the heap is empty.
    */
    Type extractRoot();
    /**
    * Retrieves and returns the root of the heap.
    * @return The value at the root of the heap.
    */
    Type getRoot();
    /**
    * Inserts an element to the heap.
    * @param element the element to be inserted.
    */
    void insert(Type element);
    //void modify(int index, Type key); TO BE IMPLEMENTED
private:
    std::vector<Type> heap;
};

/*
* Priority Queue Class Implementation
*/

template<typename Type, typename Comparator>
template<typename RandomAccessIterator>
HeapImpl<Type, Comparator>::HeapImpl(RandomAccessIterator first, RandomAccessIterator last) {
    copy(first, last);
}

template<typename Type, typename Comparator>
Type HeapImpl<Type, Comparator>::extractRoot() {
    if (this->heap.size() <= 0) {
        throw std::underflow_error("The priority heap is empty");
    }
    Type root = this->heap[0];
    this->heap[0] = this->heap.back();
    this->heap.pop_back();
    Heap<Type, Comparator>::heapify(heap.begin(), heap.end(), heap.begin());
    return root;
}

template<typename Type, typename Comparator>
template<typename RandomAccessIterator>
void HeapImpl<Type, Comparator>::copy(RandomAccessIterator first, RandomAccessIterator last) {
    heap = std::vector<Type>(first, last);
    Heap<Type, Comparator>::buildHeap(heap.begin(), heap.end());
}

template<typename Type, typename Comparator>
void HeapImpl<Type, Comparator>::insert(Type element) {
    heap.push_back(element);
    Heap<Type, Comparator>::siftUp(heap.begin(), heap.end() - 1);
}

template<typename Type, typename Comparator>
Type HeapImpl<Type, Comparator>::getRoot() {
    return this->heap[0];
}

#endif // HeapImpl_H
