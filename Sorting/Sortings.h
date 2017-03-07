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

template<typename RandomAccessIterator, typename Comparator>
void selectionSort(RandomAccessIterator first, RandomAccessIterator last, Comparator comparator) {
    for (auto it1 = first; it1 < last; it1++) {
        auto min = it1;
        for (auto it2 = it1 + 1; it2 < last; it2++) {
            if (comparator(*it2, *it1)) {
                min = it2;
            }
        }
        std::swap(it1, min);
    }
}

template<typename RandomAccessIterator>
void selectionSort(RandomAccessIterator first, RandomAccessIterator last) {
    using Type = typename std::iterator_traits<RandomAccessIterator>::value_type;
    selectionSort(first, last, std::less<Type>());
}

template<typename RandomAccessIterator, typename Comparator>
void insertionSort(RandomAccessIterator first, RandomAccessIterator last, Comparator comparator) {
    for (auto it1 = first + 1; it1 < last; it1++) {
        while (comparator(*it1, *(it1 - 1))) {
            auto temp = *it1;
            *it1 = *(it1 - 1);
            *(--it1) = temp;
        }

    }
}

template<typename RandomAccessIterator>
void insertionSort(RandomAccessIterator first, RandomAccessIterator last) {
    using Type = typename std::iterator_traits<RandomAccessIterator>::value_type;
    insertionSort(first, last, std::less<Type>());
}

template<typename RandomAccessIterator, typename Comparator>
void bubbleSort(RandomAccessIterator first, RandomAccessIterator last, Comparator comparator) {
    bool swapped = false;
    for (auto it1 = first + 1; it1 < last; it1++) {
        for (auto it2 = first; it2 < first + (last - it1); it2++) {
            if (comparator(*(it2 + 1), *it2)) {
                auto temp = *it2;
                *it2 = *(it2 + 1);
                *(it2 + 1) = temp;
            }
        }
    }
}

template<typename RandomAccessIterator>
void bubbleSort(RandomAccessIterator first, RandomAccessIterator last) {
    using Type = typename std::iterator_traits<RandomAccessIterator>::value_type;
    bubbleSort(first, last, std::less<Type>());
}

#endif // Sortings_H
