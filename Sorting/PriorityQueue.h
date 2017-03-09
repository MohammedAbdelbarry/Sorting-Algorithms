#include <vector>
#include <stdexcept>
#include "Heap.h"
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
        return queue.size();
    }
    /**
    * Checks whether a priority queue is empty or not.
    * @return A boolean indicating whether the priority queue is empty or not.
    */
    inline bool isEmpty() {
        return queue.empty();
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
    Type extractRoot();
    /**
    * Retrieves and returns the root of the priority queue.
    * @return The value at the root of the priority queue.
    */
    Type getRoot();
    /**
    * Inserts an element to the priority queue.
    * @param element the element to be inserted.
    */
    void insert(Type element);
    //void modify(int index, Type key); TO BE IMPLEMENTED
private:
    std::vector<Type> queue;
    Heap<Type, Comparator> heap;
};

/*
* Priority Queue Class Implementation
*/

template<typename Type, typename Comparator>
template<typename RandomAccessIterator>
PriorityQueue<Type, Comparator>::PriorityQueue(RandomAccessIterator first, RandomAccessIterator last) {
    copy(first, last);
}

template<typename Type, typename Comparator>
Type PriorityQueue<Type, Comparator>::extractRoot() {
    if (this->queue.size() <= 0) {
        throw std::underflow_error("The priority queue is empty");
    }
    Type root = this->queue[0];
    this->queue[0] = this->queue.back();
    this->queue.pop_back();
    heap.heapify(queue.begin(), queue.end(), queue.begin());
    return root;
}

template<typename Type, typename Comparator>
template<typename RandomAccessIterator>
void PriorityQueue<Type, Comparator>::copy(RandomAccessIterator first, RandomAccessIterator last) {
    queue = std::vector<Type>(first, last);
    heap.buildHeap(queue.begin(), queue.end());
}

template<typename Type, typename Comparator>
void PriorityQueue<Type, Comparator>::insert(Type element) {
    queue.push_back(element);
    heap.siftUp(queue.begin(), queue.end() - 1);
}

template<typename Type, typename Comparator>
Type PriorityQueue<Type, Comparator>::getRoot() {
    return this->queue[0];
}

#endif // PriorityQueue_H
