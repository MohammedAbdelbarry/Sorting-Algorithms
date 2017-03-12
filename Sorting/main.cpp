#define all(c) begin(c), end(c)
#include <iostream>
#include <fstream>
#include <chrono>
#include <stdexcept>
#include <functional>
#include <string>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include "Sortings.h"
#include "PriorityQueue.h"
std::vector<double> n, merge, quick, heap, std_sort, std_stable_sort, bubble, insertion, selection, intro;

template <typename Number>
std::string toString (Number num) {
     std::ostringstream stringStream;
     stringStream << num;
     return stringStream.str();
}

template<typename Iterator>
void printRange(Iterator first, Iterator last) {
    for (auto it = first ; it < last ; it++) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
}

void readArray(std::string fileName, auto &&vec) {
    std::ifstream stream(fileName);
    vec = std::vector<double>((std::istream_iterator<double>(stream)),
                                 std::istream_iterator<double>());
}

template<typename RandomAccessIterator, typename Comparator>
void testPerformance(////function<void(RandomAccessIterator, RandomAccessIterator, Comparator)> sortFunctor
                        RandomAccessIterator first, RandomAccessIterator last, Comparator comparator) {
    n.push_back(std::distance(first, last));
    std::vector<double> vecs(first, last);

    std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
    sort::mergeSort(vecs.begin(), vecs.end(), comparator);
    std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedTime = end - start;
    merge.push_back(elapsedTime.count());
    if(!std::is_sorted(vecs.begin(), vecs.end(), comparator))
        throw std::runtime_error("Merge Sort Failed to Sort");

    std::copy(first, last, vecs.begin());
    start = std::chrono::high_resolution_clock::now();
    sort::heapSort(vecs.begin(), vecs.end(), comparator);
    end = std::chrono::high_resolution_clock::now();
    elapsedTime = end - start;
    heap.push_back(elapsedTime.count());
    if(!std::is_sorted(vecs.begin(), vecs.end(), comparator))
        throw std::runtime_error("Heap Sort Failed to Sort");

    std::copy(first, last, vecs.begin());
    start = std::chrono::high_resolution_clock::now();
    sort::quickSort(vecs.begin(), vecs.end(), comparator);
    end = std::chrono::high_resolution_clock::now();
    elapsedTime = end - start;
    quick.push_back(elapsedTime.count());
    if(!std::is_sorted(vecs.begin(), vecs.end(), comparator))
        throw std::runtime_error("Quick Sort Failed to Sort");

    std::copy(first, last, vecs.begin());
    start = std::chrono::high_resolution_clock::now();
    sort::insertionSort(vecs.begin(), vecs.end(), comparator);
    end = std::chrono::high_resolution_clock::now();
    elapsedTime = end - start;
    insertion.push_back(elapsedTime.count());
    if(!std::is_sorted(vecs.begin(), vecs.end(), comparator))
        throw std::runtime_error("Insertion Sort Failed to Sort");

    std::copy(first, last, vecs.begin());
    start = std::chrono::high_resolution_clock::now();
    sort::bubbleSort(vecs.begin(), vecs.end(), comparator);
    end = std::chrono::high_resolution_clock::now();
    elapsedTime = end - start;
    bubble.push_back(elapsedTime.count());
    if(!std::is_sorted(vecs.begin(), vecs.end(), comparator))
        throw std::runtime_error("Bubble Sort Failed to Sort");

    std::copy(first, last, vecs.begin());
    start = std::chrono::high_resolution_clock::now();
    sort::selectionSort(vecs.begin(), vecs.end(), comparator);
    end = std::chrono::high_resolution_clock::now();
    elapsedTime = end - start;
    selection.push_back(elapsedTime.count());
    if(!std::is_sorted(vecs.begin(), vecs.end(), comparator))
        throw std::runtime_error("Selection Sort Failed to Sort");

    std::copy(first, last, vecs.begin());
    start = std::chrono::high_resolution_clock::now();
    std::sort(vecs.begin(), vecs.end(), comparator);
    end = std::chrono::high_resolution_clock::now();
    elapsedTime = end - start;
    std_sort.push_back(elapsedTime.count());
    if(!std::is_sorted(vecs.begin(), vecs.end(), comparator))
        throw std::runtime_error("std::sort Failed to Sort");

    std::copy(first, last, vecs.begin());
    start = std::chrono::high_resolution_clock::now();
    std::stable_sort(vecs.begin(), vecs.end(), comparator);
    end = std::chrono::high_resolution_clock::now();
    elapsedTime = end - start;
    std_stable_sort.push_back(elapsedTime.count());
    if(!std::is_sorted(vecs.begin(), vecs.end(), comparator))
        throw std::runtime_error("std::stable_sort Failed to Sort");

    std::copy(first, last, vecs.begin());
    start = std::chrono::high_resolution_clock::now();
    sort::introSort(vecs.begin(), vecs.end(), comparator);
    end = std::chrono::high_resolution_clock::now();
    elapsedTime = end - start;
    intro.push_back(elapsedTime.count());
    if(!std::is_sorted(vecs.begin(), vecs.end(), comparator))
        throw std::runtime_error("std::stable_sort Failed to Sort");

}

void writeVectorToFile(auto&& vec, std::string path) {
    std::ofstream stream(path);
    for (auto el : vec) {
        stream << el << ' ';
    }
}

void writeVectors() {
    std::string path = "D:\\Whatever\\C++ Projects\\Data Structure\\Lab1\\Performance\\";
    writeVectorToFile(n, path + "n.txt");
    writeVectorToFile(merge, path + "merge.txt");
    writeVectorToFile(quick, path + "quick.txt");
    writeVectorToFile(heap, path + "heap.txt");
    writeVectorToFile(bubble, path + "bubble.txt");
    writeVectorToFile(insertion, path + "insertion.txt");
    writeVectorToFile(selection, path + "selection.txt");
    writeVectorToFile(std_sort, path + "std_sort.txt");
    writeVectorToFile(std_stable_sort, path + "std_stable_sort.txt");
    writeVectorToFile(intro, path + "intro.txt");
}
/*template<typename RandomAccessIterator, typename Comparator>
void testPerformanceIntro(RandomAccessIterator first, RandomAccessIterator last, Comparator comparator) {
    std::vector<double> vecs(first, last);
    std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
    sort::introSort(vecs.begin(), vecs.end(), comparator);
    std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedTime = end - start;
    intro.push_back(elapsedTime.count());
    if(!std::is_sorted(vecs.begin(), vecs.end(), comparator))
        throw std::runtime_error("Merge Sort Failed to Sort");
}*/
void testSeveralArrays() {
    const int NUM_OF_TEST_CASES = 201;
    n.reserve(NUM_OF_TEST_CASES);
    n[0] = 0;
    merge.reserve(NUM_OF_TEST_CASES);
    merge[0] = 0;
    quick.reserve(NUM_OF_TEST_CASES);
    quick[0] = 0;
    heap.reserve(NUM_OF_TEST_CASES);
    heap[0] = 0;
    bubble.reserve(NUM_OF_TEST_CASES);
    bubble[0] = 0;
    selection.reserve(NUM_OF_TEST_CASES);
    selection[0] = 0;
    insertion.reserve(NUM_OF_TEST_CASES);
    insertion[0] = 0;
    std_sort.reserve(NUM_OF_TEST_CASES);
    std_sort[0] = 0;
    std_stable_sort.reserve(NUM_OF_TEST_CASES);
    std_stable_sort[0] = 0;
    intro.reserve(NUM_OF_TEST_CASES);
    intro[0] = 0;
    std::vector<double> vec;
    for (int i = 1 ; i < NUM_OF_TEST_CASES ; i++) {
        std::string fileName = std::string("D:\\Whatever\\C++ Projects\\Data Structure\\Lab1\\Datasets\\random\\test") + toString(i) + ".txt";
        readArray(fileName, vec);
        testPerformance(all(vec), std::greater<double>());
    }
    writeVectors();
}

void testHeap(int n) {
    std::vector<double> vecs;
    vecs.reserve(n);
    for (int i = 0 ; i < n ; i++) {
        vecs.push_back(i);
    }

    std::random_shuffle(all(vecs));
    sort::heapSort(all(vecs), std::less<double>());
    std::cout << std::endl;
    if (!std::is_sorted(all(vecs), std::less<double>()))
        throw std::runtime_error("Heap sort failed to sort with std::less");
    std::random_shuffle(all(vecs));
    sort::heapSort(all(vecs), std::greater<double>());
    if (!std::is_sorted(all(vecs), std::greater<double>()))
        throw std::runtime_error("Heap sort failed to sort with std::greater");

    std::random_shuffle(all(vecs));
    sort::heapSort(all(vecs), std::less_equal<double>());
    if (!std::is_sorted(all(vecs), std::less_equal<double>()))
        throw std::runtime_error("Heap sort failed to sort with std::less_equal");

    std::random_shuffle(all(vecs));
    sort::heapSort(all(vecs), std::greater_equal<double>());
    if (!std::is_sorted(all(vecs), std::greater_equal<double>()))
        throw std::runtime_error("Heap sort failed to sort with std::greater_equal");

    std::random_shuffle(all(vecs));
    PriorityQueue<double, std::less<double>> pq1(all(vecs));
    for (int i = 0 ; i < vecs.size() ; i++) {
        vecs[i] = pq1.pop();
    }
    if (!std::is_sorted(all(vecs), std::less<double>()))
        throw std::runtime_error("priority queue sort failed to sort with std::less and copying");

    std::random_shuffle(all(vecs));
    PriorityQueue<double, std::less_equal<double>> pq2(all(vecs));
    for (int i = 0 ; i < vecs.size() ; i++) {
        vecs[i] = pq2.pop();
    }
    if (!std::is_sorted(all(vecs), std::less_equal<double>()))
        throw std::runtime_error("priority queue sort failed to sort with std::less_equal and copying");

    std::random_shuffle(all(vecs));
    PriorityQueue<double, std::greater<double>> pq3(all(vecs));
    for (int i = 0 ; i < vecs.size() ; i++) {
        vecs[i] = pq3.pop();
    }
    if (!std::is_sorted(all(vecs), std::greater<double>()))
        throw std::runtime_error("priority queue sort failed to sort with std::greater and copying");

    std::random_shuffle(all(vecs));
    PriorityQueue<double, std::greater_equal<double>> pq4(all(vecs));
    for (int i = 0 ; i < vecs.size() ; i++) {
        vecs[i] = pq4.pop();
    }
    if (!std::is_sorted(all(vecs), std::greater_equal<double>()))
        throw std::runtime_error("priority queue sort failed to sort with std::greater_equal and copying");

    std::random_shuffle(all(vecs));
    for (auto el : vecs) {
        pq1.push(el);
    }
    for (int i = 0 ; i < vecs.size() ; i++) {
        vecs[i] = pq1.pop();
    }
    if (!std::is_sorted(all(vecs), std::less<double>()))
        throw std::runtime_error("priority queue sort failed to sort with std::less and insertion");

    std::random_shuffle(all(vecs));
    for (auto el : vecs) {
        pq2.push(el);
    }
    for (int i = 0 ; i < vecs.size() ; i++) {
        vecs[i] = pq2.pop();
    }
    if (!std::is_sorted(all(vecs), std::less_equal<double>()))
        throw std::runtime_error("priority queue sort failed to sort with std::less_equal and insertion");

    std::random_shuffle(all(vecs));
    for (auto el : vecs) {
        pq3.push(el);
    }
    for (int i = 0 ; i < vecs.size() ; i++) {
        vecs[i] = pq3.pop();
    }
    if (!std::is_sorted(all(vecs), std::greater<double>()))
        throw std::runtime_error("priority queue sort failed to sort with std::greater and insertion");

    std::random_shuffle(all(vecs));
    for (auto el : vecs) {
        pq4.push(el);
    }
    for (int i = 0 ; i < vecs.size() ; i++) {
        vecs[i] = pq4.pop();
    }
    if (!std::is_sorted(all(vecs), std::greater_equal<double>()))
        throw std::runtime_error("priority queue sort failed to sort with std::greater_equal and insertion");

}

int main()
{
    std::vector<int> vec;
    vec.push_back(-1);
    vec.push_back(1);
    vec.push_back(50);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(-19);
    vec.push_back(50);
    printRange(all(vec));
    sort::quickSort(all(vec), std::less<int>());
    printRange(all(vec));
    //sort::heapSort(vec.begin(), vec.end());
//    printRange(all(vec));
    PriorityQueue<int, std::less<int>> pq(all(vec));
    for (auto el : vec) {
        std::cout << pq.pop() << ' ';
    }
    std::cout << std::endl;
    for (auto el : vec) {
        pq.push(el);
    }
    for (auto el : vec) {
        std::cout << pq.pop() << ' ';
    }
//    testHeap(100000);
    //std::vector<double> vecs;
//    testSeveralArrays();
    //readArray("D:\\Whatever\\C++ Projects\\Data Structure\\Lab1\\Datasets\\test139Random100k.txt", vecs);
//    printRange(all(vecs));
//    testPerformance(sort::heapSort, all(vecs), std::greater<double>());
    //testPerformance(all(vecs), std::greater<double>());
    //cout << vecs.size();
    return 0;
}
