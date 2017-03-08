#define all(c) begin(c), end(c)
#include <iostream>
#include "Sortings.h"
#include "PriorityQueue.h"
#include "Heap.h"
using namespace std;

template<typename Iterator>
void printRange(Iterator first, Iterator last) {
    for (auto it = first ; it < last ; it++) {
        cout << *it << ' ';
    }
    cout << endl;
}

int main()
{
    vector<int> vec;
    vec.push_back(-1);
    vec.push_back(1);
    vec.push_back(50);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(-19);
    vec.push_back(50);
    printRange(all(vec));
    quickSort(all(vec), greater<int>());
    printRange(all(vec));
    heapSort(vec.begin(), vec.end());
    printRange(all(vec));
    PriorityQueue<int, greater_equal<int>> pq(vec.begin(), vec.end());
    for (auto el : vec) {
        cout << pq.extractRoot() << ' ';
    }
    cout << endl;
    for (auto el : vec) {
        pq.insert(el);
    }
    for (auto el : vec) {
        cout << pq.extractRoot() << ' ';
    }
    return 0;
}
