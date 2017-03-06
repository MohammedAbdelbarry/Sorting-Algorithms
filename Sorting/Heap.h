#include <vector>
#include <iostream>
#ifndef Heap_H
#define Heap_H

/*
* Heap Class Declaration
*/
template<typename Type, typename Comparator =  std::greater_equal<Type>>
class Heap {
public:
    template<typename RandomAccessIterator>
    void heapify(RandomAccessIterator first, RandomAccessIterator last, RandomAccessIterator position);
    /**
    * Builds a Heap.
    */
    template<typename RandomAccessIterator>
    void buildHeap(RandomAccessIterator first, RandomAccessIterator last);
    template<typename RandomAccessIterator>
    void shiftUp(RandomAccessIterator first, RandomAccessIterator position);
private:
    Comparator comparator;
    inline int parent(int index) {
        return (index - 1) >> 1;
    }
    inline int left(int index) {
        return (index << 1) + 1;
    }
    inline int right(int index) {
        return (index << 1) + 2;
    }
};

/*
* Heap Class Implementation
*/

template<typename Type, typename Comparator>
template<typename RandomAccessIterator>
void Heap<Type, Comparator>::heapify(RandomAccessIterator first, RandomAccessIterator last, RandomAccessIterator position) {
    int index = position - first;
    int size = last - first;
    if (index < 0) {
        return;
    }
    int left = this->left(index);
    int right = this->right(index);
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
void Heap<Type, Comparator>::shiftUp(RandomAccessIterator first, RandomAccessIterator position) {
    int index = position - first;
    if (index < 0) {
        return;
    }
    int parent = this->parent(index);
    if (!comparator(first[parent], first[index])) {
        int temp = first[parent];
        first[parent] = first[index];
        first[index] = temp;
        shiftUp(first, first + parent);
    }
}

#endif // Heap_H
