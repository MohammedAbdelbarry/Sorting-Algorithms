#include <vector>
#ifndef Heap_H
#define Heap_H
template<typename Type, typename Comparator>
class Heap {
public:
    Heap();
    //Heap(Type[] arr);
    inline int size() {
        return heap.size();
    }
    template<typename Iterator>
    void heapify(Iterator first, Iterator last, Iterator position);
    /**
    * Builds a Heap.
    */
    template<typename Iterator>
    void buildHeap(Iterator first, Iterator last);
    /**
    * Builds a Heap and assigns it to the internal Array.
    */
    template<typename Iterator>
    void makeHeap(Iterator first, Iterator last);
    Type extractRoot();
    Type getRoot();
    void insert(Type element);
    void modify(int index, Type key);
    //~Heap();
private:
    std::vector<Type> heap;
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
    void shiftUp(int index);
};
#endif // Heap_H
