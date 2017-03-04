#include <iostream>
#include <vector>
#include "Heap.h"
template<typename Type, typename Comparator>
Heap<Type, Comparator>::Heap() {
    comparator = Comparator();
}

template<typename Type, typename Comparator>
template<typename Iterator>
void Heap<Type, Comparator>::heapify(Iterator first, Iterator last, Iterator position) {
    int index = position - first;
    int size = last - first;
    if (index < 0) {
        return;
    }
    int left = this->left(index);
    int right = this->right(index);
//    std::cout << left << ' ' << right << ' ' << vec.size() << std::endl;
//    for (int el : vec) {
//        std::cout << el << ' ';
//    }
//    std::cout << std::endl;
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
template<typename Iterator>
void Heap<Type, Comparator>::buildHeap(Iterator first, Iterator last) {
    int size = last - first;
    for (int i = (size - 1) >> 1; i >= 0; i--) {
        heapify(first, last, first + i);
    }
}

template<typename Type, typename Comparator>
template<typename Iterator>
void Heap<Type, Comparator>::makeHeap(Iterator first, Iterator last) {
    buildHeap(first, last);
    this->heap = std::vector<Type>(first, last);
}

template<typename Type, typename Comparator>
void Heap<Type, Comparator>::insert(Type element) {
    heap.push_back(element);
    shiftUp(heap.size() - 1);
}

template<typename Type, typename Comparator>
Type Heap<Type, Comparator>::getRoot() {
    return this->heap[0];
}

template<typename Type, typename Comparator>
Type Heap<Type, Comparator>::extractRoot() {
    if (this->heap.size() < 0) {
        //throw std::underflow_error("The Heap is Empty");
    }
    Type root = this->heap[0];
    this->heap[0] = this->heap.back();
    this->heap.pop_back();
    heapify(this->heap, 0, this->heap.size());
    return root;
}
template<typename Type, typename Comparator>
void Heap<Type, Comparator>::shiftUp(int index) {
    if (index < 0) {
        return;
    }
    int parent = this->parent(index);
    if (!comparator(heap[parent], heap[index])) {
        int temp = heap[parent];
        heap[parent] = heap[index];
        heap[index] = temp;
        shiftUp(parent);
    }
}
