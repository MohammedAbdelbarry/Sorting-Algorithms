#ifndef Sortings_H
#define Sortings_H
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include "Heap.h"
/**
* @mainpage Sorting Algorithms
* The implementation of some basic sorting algorithms in C++
*/
/**
* @file Sortings.h
* A header file containing the implementation of some sorting
* algorithms.
* @author Mohammed Abdelbarry.
*/
/**
* Swaps *first with *second.
* @param first The first iterator.
* @param second The second iterator.
*/
template<typename Iterator>
void swapIteratorData(Iterator first, Iterator second) {
    auto temp = *second;
    *second = *first;
    *first = temp;
}
/**
* Sorts the range [first, last[ using heap sort algorithm.
* Runs in O(nlogn) in the average case and O(nlogn) in the worst case.
* Has a space complexity of O(1).
* @param first An iterator pointing to the first element in the
* range.
* @param last An iterator pointing to the element that comes after the last element
* in the range.
* @param comparator The comparator boolean function used to compare each two elements
* while sorting.
*/
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
/**
* Sorts the range [first, last[ using heap sort algorithm.
* Runs in O(nlogn) in the average case and O(nlogn) in the worst case.
* Has a space complexity of O(1).
* @param first An iterator pointing to the first element in the
* range.
* @param last An iterator pointing to the element that comes after the last element
* in the range.
*/
template<typename RandomAccessIterator>
void heapSort(RandomAccessIterator first, RandomAccessIterator last) {
    using Type = typename std::iterator_traits<RandomAccessIterator>::value_type;
    heapSort(first, last, std::less<Type>());
}
/**
* Sorts the range [first, last[ using selection sort algorithm.
* Runs in O(n^2) in the average case and O(n^2) in the worst case.
* Has a space complexity of O(1).
* @param first An iterator pointing to the first element in the
* range.
* @param last An iterator pointing to the element that comes after the last element
* in the range.
* @param comparator The comparator boolean function used to compare each two elements
* while sorting.
*/
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
/**
* Sorts the range [first, last[ using selection sort algorithm.
* Runs in O(n^2) in the average case and O(n^2) in the worst case.
* Has a space complexity of O(1).
* @param first An iterator pointing to the first element in the
* range.
* @param last An iterator pointing to the element that comes after the last element
* in the range.
*/
template<typename RandomAccessIterator>
void selectionSort(RandomAccessIterator first, RandomAccessIterator last) {
    using Type = typename std::iterator_traits<RandomAccessIterator>::value_type;
    selectionSort(first, last, std::less<Type>());
}
/**
* Sorts the range [first, last[ using insertion sort algorithm.
* Runs in O(n^2) in the average case and O(n^2) in the worst case.
* Has a space complexity of O(1).
* @param first An iterator pointing to the first element in the
* range.
* @param last An iterator pointing to the element that comes after the last element
* in the range.
* @param comparator The comparator boolean function used to compare each two elements
* while sorting.
*/
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
/**
* Sorts the range [first, last[ using insertion sort algorithm.
* Runs in O(n^2) in the average case and O(n^2) in the worst case.
* Has a space complexity of O(1).
* @param first An iterator pointing to the first element in the
* range.
* @param last An iterator pointing to the element that comes after the last element
* in the range.
*/
template<typename RandomAccessIterator>
void insertionSort(RandomAccessIterator first, RandomAccessIterator last) {
    using Type = typename std::iterator_traits<RandomAccessIterator>::value_type;
    insertionSort(first, last, std::less<Type>());
}
/**
* Sorts the range [first, last[ using bubble sort algorithm.
* Runs in O(n^2) in the average case and O(n^2) in the worst case.
* Has a space complexity of O(1).
* @param first An iterator pointing to the first element in the
* range.
* @param last An iterator pointing to the element that comes after the last element
* in the range.
* @param comparator The comparator boolean function used to compare each two elements
* while sorting.
*/
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
/**
* Sorts the range [first, last[ using bubble sort algorithm.
* Runs in O(n^2) in the average case and O(n^2) in the worst case.
* Has a space complexity of O(1).
* @param first An iterator pointing to the first element in the
* range.
* @param last An iterator pointing to the element that comes after the last element
* in the range.
*/
template<typename RandomAccessIterator>
void bubbleSort(RandomAccessIterator first, RandomAccessIterator last) {
    using Type = typename std::iterator_traits<RandomAccessIterator>::value_type;
    bubbleSort(first, last, std::less<Type>());
}
/**
* Merges the two sorted ranges [first, mid[ and [mid, last[.
* Has a space complexity of O(n) and runs in O(n) time.
* @param first The first element of the first range.
* @param mid The first element in the second range and
* the element that comes after the last element in the first
* range.
* @param last The element that comes after the last element in the second
* range.
* @param comparator The comparator boolean function used to compare each two elements
* while sorting.
*/
template<typename Iterator, typename Comparator>
void merge(Iterator first, Iterator mid, Iterator last, Comparator comparator) {
    using Type = typename std::iterator_traits<Iterator>::value_type;
    int size = last - first;
    Type temp[size];
    int index = 0;
    auto i = first, j = mid;
    while(i < mid && j < last) {
        if (comparator(*i, *j)) {
            temp[index++] = *i;
            i++;
        } else if (comparator(*j, *i)) {
            temp[index++] = *j;
            j++;
        } else {
            temp[index++] = *i;
            i++;
            temp[index++] = *j;
            j++;
        }
    }
    while (i < mid) {
        temp[index++] = *i;
        i++;
    }
    while (j < last) {
        temp[index++] = *j;
        j++;
    }
    std::copy(temp, temp + size, first);
}
/**
* Sorts the range [first, last[ using merge sort algorithm.
* Runs in O(nlogn) in the average case and O(nlogn) in the worst case.
* Has a space complexity of O(n).
* @param first An iterator pointing to the first element in the
* range.
* @param last An iterator pointing to the element that comes after the last element
* in the range.
* @param comparator The comparator boolean function used to compare each two elements
* while sorting.
* @see merge();
*/
template<typename RandomAccessIterator, typename Comparator>
void mergeSort(RandomAccessIterator first, RandomAccessIterator last, Comparator comparator) {
    int size = last - first;
    if (size > 1) {
        RandomAccessIterator mid = first + size / 2;
        mergeSort(first, mid, comparator);
        mergeSort(mid, last, comparator);
        merge(first, mid, last,  comparator);
    }
}
/**
* Sorts the range [first, last[ using merge sort algorithm.
* Runs in O(nlogn) in the average case and O(nlogn) in the worst case.
* Has a space complexity of O(n).
* @param first An iterator pointing to the first element in the
* range.
* @param last An iterator pointing to the element that comes after the last element
* in the range.
* @see merge()
*/
template<typename RandomAccessIterator>
void mergeSort(RandomAccessIterator first, RandomAccessIterator last) {
    using Type = typename std::iterator_traits<RandomAccessIterator>::value_type;
    mergeSort(first, last, std::less<Type>());
}
/**
* Sorts the range [first, last[ using bogo sort algorithm.
* Runs in O((n + 1)!) in the average case and has an unbounded runtime in the worst case.
* Has a space complexity of O(1).
* This function should only be used for educational purposes.
* @param first An iterator pointing to the first element in the
* range.
* @param last An iterator pointing to the element that comes after the last element
* in the range.
* @param comparator The comparator boolean function used to compare each two elements
* while sorting.
*/
//USE IT ON YOUR OWN RISK. :D
template<typename RandomAccessIterator, typename Comparator>
void bogoSort(RandomAccessIterator first, RandomAccessIterator last, Comparator comparator) {
    while(!std::is_sorted(first, last, comparator)) {
        std::random_shuffle(first, last);
    }
}
/**
* Sorts the range [first, last[ using bogo sort algorithm.
* Runs in O((n + 1)!) in the average case and has an unbounded runtime in the worst case.
* Has a space complexity of O(1).
* This function should only be used for educational purposes.
* @param first An iterator pointing to the first element in the
* range.
* @param last An iterator pointing to the element that comes after the last element
* in the range.
*/
//A very inefficient sorting algorithm. :D
template<typename RandomAccessIterator>
void bogoSort(RandomAccessIterator first, RandomAccessIterator last) {
    using Type = typename std::iterator_traits<RandomAccessIterator>::value_type;
    bogoSort(first, last, std::less<Type>());
}
/**
* Partitions a range around a pivot using Lomuto partitioning algorithm and returns
* an iterator pointing to that pivot.
* Has a worst case complexity of O(n) and a space complexity of O(1).
* @param first The first element in the range to be partitioned.
* @param last An iterator pointing to the element that comes after the last element
* in the range.
* @param comparator The comparator boolean function used to compare each two elements
* while sorting.
* @return An iterator pointing to the pivot.
*/
template<typename RandomAccessIterator, typename Comparator>
RandomAccessIterator lomutoPartitioning(RandomAccessIterator first, RandomAccessIterator last, Comparator comparator) {
    auto pivot = last - 1;
    auto pivotPos = first;
    for (auto it = first ; it < pivot ; it++) {
        if (comparator(*it, *pivot)) {
            swapIteratorData(pivotPos, it);
            pivotPos++;
        }
    }
    swapIteratorData(pivot, pivotPos);
    return pivotPos;
}
/**
* Sorts the range [first, last[ using quick sort algorithm.
* Runs in O(nlogn) in the average case and O(n^2) in the worst case.
* Has a space complexity of O(1).
* @param first An iterator pointing to the first element in the
* range.
* @param last An iterator pointing to the element that comes after the last element
* in the range.
* @param comparator The comparator boolean function used to compare each two elements
* while sorting.
* @see lomutoPartitioning()
*/
template<typename RandomAccessIterator, typename Comparator>
void quickSort(RandomAccessIterator first, RandomAccessIterator last, Comparator comparator) {
    if (first < last) {
        auto pivot = lomutoPartitioning(first, last, comparator);
        quickSort(first, pivot, comparator);
        quickSort(pivot + 1, last, comparator);
    }
}
/**
* Sorts the range [first, last[ using quick sort algorithm.
* Has a space complexity of O(1).
* @param first An iterator pointing to the first element in the
* range.
* @param last An iterator pointing to the element that comes after the last element
* in the range.
* @see lomutoPartitioning()
*/
template<typename RandomAccessIterator>
void quickSort(RandomAccessIterator first, RandomAccessIterator last) {
    using Type = typename std::iterator_traits<RandomAccessIterator>::value_type;
    quickSort(first, last, std::less<Type>());
}

#endif // Sortings_H
