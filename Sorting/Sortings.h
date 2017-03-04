#include <vector>
#include <iostream>
#include <iterator>

template<typename Iterator, typename Comparator>
void heapSort(Iterator first, Iterator last, Comparator comparator) {
    auto origLast = last;
    using Type = typename std::iterator_traits<Iterator>::value_type;
    Heap<Type, Comparator> heap;
    heap.buildHeap(first, last);
    for (auto it = first ; it < last ; it++) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
    int size = last - first;
    for (int i = size - 1; i > 0; i--) {
        Type temp = first[0];
        first[0] = first[i];
        first[i] = temp;
        heap.heapify(first, --last, first);
    }
    for (auto it = first ; it < origLast ; it++) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
}
