#ifndef Sortings_H
#define Sortings_H
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include "Heap.h"
template<typename RandomAccessIterator, typename Comparator>
void heapSort(RandomAccessIterator first, RandomAccessIterator last, Comparator comparator) {
    auto origLast = last;
    using Type = typename std::iterator_traits<RandomAccessIterator>::value_type;
    Heap<Type, Comparator> heap;
    heap.buildHeap(first, last);
    int size = last - first;
    for (int i = size - 1; i > 0; i--) {
        Type temp = first[0];
        first[0] = first[i];
        first[i] = temp;
        heap.heapify(first, --last, first);
    }
    std::reverse(first, origLast);
}
template<typename RandomAccessIterator>
void heapSort(RandomAccessIterator first, RandomAccessIterator last) {
    using Type = typename std::iterator_traits<RandomAccessIterator>::value_type;
    heapSort(first, last, std::less<Type>());
}
#endif // Sortings_H
