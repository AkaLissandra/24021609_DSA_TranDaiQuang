#include <iostream>
using namespace std;

int temp[1000];
int a[1000];

void merge(int a[], int left, int mid, int right) {
    int x = left;
    int y = mid + 1;
    int z = left;

    while (z <= right) {
        if (y > right) {
            temp[z] = a[x];
            x++;
        } else if (x > mid) {
            temp[z] = a[y];
            y++;
        } else if (a[x] <= a[y]) {
            temp[z] = a[x];
            x++;
        } else {
            temp[z] = a[y];
            y++;
        }
        z++;
    }

    for (int i = left; i <= right; i++) {
        a[i] = temp[i];
    }
}

void mergeSort(int a[], int left, int right) {
    if (left == right) {
        return;
    }

    int mid = (left + right) / 2;

    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);

    merge(a, left, mid, right);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    mergeSort(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}