#include <vector>
#include <iostream>
#ifndef Heap_H
#define Heap_H
/**
* @file Heap.h
* A header file containing the declaration of the heap
* interface.
* @author Mohammed Abdelbarry.
*/
/**
* An interface that defines a heap.
* @author Mohammed Abdelbarry.
*/
template<typename Type, typename Comparator =  std::greater_equal<Type>>
class Heap {
public:
    /**
    * Performs the operation heapify on a range.
    * Has a worst case time of O(logn).
    * @param first An iterator pointing to the first element in the range.
    * @param second An iterator pointing to the second element in the range.
    * @param position The starting position of the heapify operation.
    */
    template<typename RandomAccessIterator>
    static void heapify(RandomAccessIterator first, RandomAccessIterator last, RandomAccessIterator position);
    /**
    * Transforms a range into a heap.
    * Has a worst case time of O(n).
    * @param first An iterator pointing to the first element in the range.
    * @param second An iterator pointing to the second element in the range.
    */
    template<typename RandomAccessIterator>
    static void buildHeap(RandomAccessIterator first, RandomAccessIterator last);
    /**
    * Performs the operation sift-up on a range of elements.
    * Has a worst case time of O(logn).
    * @param first An iterator pointing to the first element in the range.
    * @param position The starting position of the sift-up operation.
    */
    template<typename RandomAccessIterator>
    static void siftUp(RandomAccessIterator first, RandomAccessIterator position);
    /**
    * Inserts an element to the heap.
    * @param element the element to be inserted.
    */
    virtual void insert(Type element) = 0;
    /**
    * Removes and returns the root of the heap.
    * @return The value at the root of the heap.
    * @throw std::underflow_error When the heap is empty.
    */
    virtual Type extractRoot() = 0;
    /**
    * Retrieves and returns the root of the heap.
    * @return The value at the root of the heap.
    */
    virtual Type getRoot() = 0;
    /**
    * Returns the size of the heap.
    * @return The size of the heap.
    */
    virtual int size() = 0;
    /**
    * Checks whether the heap is empty or not.
    * @return A boolean indicating whether the heap is empty or not.
    */
    virtual bool isEmpty() = 0;
private:
    /**
    * Returns the index of the parent of a node.
    * @return the index of the parent of a node.
    */
    static inline int parent(int index) {
        return (index - 1) >> 1;
    }
    /**
    * Returns the index of the left child of a node.
    * @return the index of the left child of a node.
    */
    static inline int left(int index) {
        return (index << 1) + 1;
    }
    /**
    * Returns the index of the right child of a node.
    * @return the index of the right child of a node.
    */
    static inline int right(int index) {
        return (index << 1) + 2;
    }
};

/*
* Heap Class Implementation
*/

template<typename Type, typename Comparator>
template<typename RandomAccessIterator>
void Heap<Type, Comparator>::heapify(RandomAccessIterator first, RandomAccessIterator last, RandomAccessIterator position) {
    Comparator comparator;
    int index = position - first;
    int size = last - first;
    if (index < 0) {
        return;
    }
    int left = Heap<Type, Comparator>::left(index);
    int right = Heap<Type, Comparator>::right(index);
    int largest = index;
    if (left <  size && !comparator(first[index], first[left])) {
        largest = left;
    }
    if (right < size && !comparator(first[largest], first[right])) {
        largest = right;
    }
    if (largest != index) {
        Type temp = first[largest];
        first[largest] = first[index];
        first[index] = temp;
        heapify(first, last, first + largest);
    }
}

template<typename Type, typename Comparator>
template<typename RandomAccessIterator>
void Heap<Type, Comparator>::buildHeap(RandomAccessIterator first, RandomAccessIterator last) {
    int size = last - first;
    for (int i = (size - 1) >> 1; i >= 0; i--) {
        heapify(first, last, first + i);
    }
}

template<typename Type, typename Comparator>
template<typename RandomAccessIterator>
void Heap<Type, Comparator>::siftUp(RandomAccessIterator first, RandomAccessIterator position) {
    Comparator comparator;
    int index = position - first;
    if (index < 0) {
        return;
    }
    int parent = Heap<Type, Comparator>::parent(index);
    if (parent >= 0 && !comparator(first[parent], first[index])) {
        int temp = first[parent];
        first[parent] = first[index];
        first[index] = temp;
        siftUp(first, first + parent);
    }
}

#endif // Heap_H
