#include <vector>
#include "Heap.h"
#ifndef PriorityQueue_H
#define PriorityQueue_H

/*
* Priority Queue Class Declaration
*/
template<typename Type, typename Comparator =  std::less_equal<Type>>
class PriorityQueue {
public:
    template<typename Iterator>
    PriorityQueue(Iterator first, Iterator last);
    inline int size() {
        return queue.size();
    }
    /**
    * Builds a Heap and assigns it to the internal Array.
    */
    template<typename Iterator>
    void copy(Iterator first, Iterator last);
    Type extractRoot();
    Type getRoot();
    void insert(Type element);
    //void modify(int index, Type key);
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
    heap.shiftUp(queue.begin(), queue.end() - 1);
}

template<typename Type, typename Comparator>
Type PriorityQueue<Type, Comparator>::getRoot() {
    return this->queue[0];
}

#endif // PriorityQueue_H
