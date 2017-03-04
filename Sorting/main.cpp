#include <iostream>
#include "Heap.cpp"
#include "Sortings.h"
using namespace std;

int main()
{
    greater<int> greaterz = greater<int>();
    bool grtz = greaterz(5, 7);
    Heap<int, greater_equal<int>> x = Heap<int, greater_equal<int>>();
    vector<int> vec;
    vec.push_back(-1);
    vec.push_back(1);
    vec.push_back(50);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(-19);
//    for (int el : vec)
//        cout << el << endl;
//    x.buildHeap(vec);
    heapSort(vec.begin(), vec.end(), greater<int>());
    for (int el : vec)
        cout << el << endl;
    Heap<int, greater_equal<int>> heap;
    heap.makeHeap(vec.begin(), vec.end());
    cout << heap.getRoot() << endl;
    heap.insert(19);
    //heap.getRoot() << ' ' << heap.size() << ' ' << heap.extractRoot() << ' ' << heap.size() << endl
    cout << heap.getRoot();
   //cout << greater<int>()(7, 5) << endl;
    return 0;
}
