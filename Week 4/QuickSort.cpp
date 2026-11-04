#include <iostream>
#include <algorithm>
using namespace std;

int a[1000];

int partition(int a[], int left, int right) {
    int pivot = a[right];
    int x = left;

    for (int i = left; i <= right - 1; i++) {
        if (a[i] < pivot) {
            swap(a[i], a[x]);
            x++;
        }
    }

    swap(a[right], a[x]);

    return x;
}

void quickSort(int a[], int left, int right) {
    if (left >= right) {
        return;
    }

    int pivotIndex = partition(a, left, right);

    quickSort(a, left, pivotIndex - 1);
    quickSort(a, pivotIndex + 1, right);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    quickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}