#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void heapifyDown(vector<int>& a, int i, int heapSize) {
    int lastIndex = heapSize - 1;

    while (true) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left <= lastIndex && a[left] > a[largest]) {
            largest = left;
        }
        if (right <= lastIndex && a[right] > a[largest]) {
            largest = right;
        }

        if (largest == i) {
            return;
        }

        swap(a[largest], a[i]);
        i = largest;
    }
}

void buildMaxHeap(vector<int>& a) {
    int n = a.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyDown(a, i, n);
    }
}

void heapSort(vector<int>& a) {
    buildMaxHeap(a);
    int n = a.size();

    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapifyDown(a, 0, i);
    }
}

int main() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    heapSort(a);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}