#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class MaxHeap {
public:
    vector <int> v;

    MaxHeap() {
    }

    bool isRoot(int i) {
        return (i == 0);
    }

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    int lastIndex() {
        return v.size() - 1;
    }

    int top() {
        if (v.size() == 0) {
            return -1;
        } else {
            return v[0];
        }
    }

    void push(int x) {
        v.push_back(x);
        int i = lastIndex();
        heapifyUp(i);
    }

    void heapifyUp(int i) {
        while (true) {
            int p = parent(i);

            if (isRoot(i) || v[p] >= v[i]) {
                return;
            }

            swap(v[i], v[p]);
            i = p;
        }
    }

    void pop() {
        if (v.size() == 0) {
            return;
        }
        swap(v[0], v[lastIndex()]);
        v.pop_back();
        if (lastIndex() >= 0) {
            heapifyDown(0);
        } else {
            return;
        }
    }

    void heapifyDown(int i) {
        int last = lastIndex();

        while (true) {
            int l = left(i);
            int r = right(i);
            int largest = i;

            if (l <= last && v[l] > v[largest]) {
                largest = l;
            }

            if (r <= last && v[r] > v[largest]) {
                largest = r;
            }

            if (largest == i) {
                return;
            }

            swap(v[i], v[largest]);
            i = largest;
        }  
    }
};

int main() {
    cout << "Hello, World!";
    return 0;
}