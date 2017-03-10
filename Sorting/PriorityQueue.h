#include <vector>
#include <stdexcept>
#include "HeapImpl.h"
#ifndef PriorityQueue_H
#define PriorityQueue_H
/**
* @file PriorityQueue.h
* A header file containing both the declaration
* and the implementation of the PriorityQueue class.
* @author Mohammed Abdelbarry.
*/
/**
* A priority queue implementation using binary heaps.
* @author Mohammed Abdelbarry.
*/
template<typename Type, typename Comparator =  std::less_equal<Type>>
class PriorityQueue {
public:
    /**
    * Default constructor.
    * Constructs a priority queue.
    */
    PriorityQueue() {

    }
    /**
    * Priority Queue copy constructor.
    * Constructs a priority queue by copying all elements in a range.
    * @param first An iterator pointing to the first element in the
    * range.
    * @param last An iterator pointing to the element that comes after the last element
    * in the range.
    */
    template<typename Iterator>
    PriorityQueue(Iterator first, Iterator last);
    /**
    * Returns the size of the priority queue.
    * @return The size of the priority queue.
    */
    inline int size() {
        return heap.size();
    }
    /**
    * Checks whether a priority queue is empty or not.
    * @return A boolean indicating whether the priority queue is empty or not.
    */
    inline bool isEmpty() {
        return heap.isEmpty();
    }
    /**
    * Copies a range of elements into the priority queue.
    * @param first An iterator pointing to the first element in the
    * range.
    * @param last An iterator pointing to the element that comes after the last element
    * in the range.
    */
    template<typename Iterator>
    void copy(Iterator first, Iterator last);
    /**
    * Removes and returns the root of the priority queue.
    * @return The value at the root of the priority queue.
    * @throw std::underflow_error When the priority queue is empty.
    */
    Type pop();
    /**
    * Retrieves and returns the root of the priority queue.
    * @return The value at the root of the priority queue.
    */
    Type top();
    /**
    * Inserts an element to the priority queue.
    * @param element the element to be inserted.
    */
    void push(Type element);
    //void modify(int index, Type key); TO BE IMPLEMENTED
private:
    HeapImpl<Type, Comparator> heap;
};

/*
* Priority Queue Class Implementation
*/

template<typename Type, typename Comparator>
template<typename RandomAccessIterator>
PriorityQueue<Type, Comparator>::PriorityQueue(RandomAccessIterator first, RandomAccessIterator last) {
    heap.copy(first, last);
}

template<typename Type, typename Comparator>
Type PriorityQueue<Type, Comparator>::pop() {
    return heap.extractRoot();
}

template<typename Type, typename Comparator>
template<typename RandomAccessIterator>
void PriorityQueue<Type, Comparator>::copy(RandomAccessIterator first, RandomAccessIterator last) {
    heap.copy(first, last);
}

template<typename Type, typename Comparator>
void PriorityQueue<Type, Comparator>::push(Type element) {
    heap.insert(element);
}

template<typename Type, typename Comparator>
Type PriorityQueue<Type, Comparator>::top() {
    return heap.getRoot();
}

#endif // PriorityQueue_H
