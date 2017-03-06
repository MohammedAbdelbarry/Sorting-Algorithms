#include <iostream>
#include "Sortings.h"
#include "PriorityQueue.h"
#include "Heap.h"
using namespace std;

int main()
{
    vector<int> vec;
    vec.push_back(-1);
    vec.push_back(1);
    vec.push_back(50);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(-19);
    for (int el : vec)
        cout << el << ' ';
    cout << endl;
    heapSort(vec.begin(), vec.end());
    for (int el : vec)
        cout << el << ' ';
    cout << endl;
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
