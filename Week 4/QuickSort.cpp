int partition(int a[], int left, int right) {
    int pivot = a[right];
    int L = left;
    int R = right - 1;
    while (L <= R) {
        if (a[L] > pivot && a[R] < pivot) {
            swap(a[L], a[R]);
        }
        if (a[L] <= pivot) {
            L++;
        }
        if (a[R] >= pivot) {
            R--;
        }   
    }
    swap(a[L], a[right]);

    return L;
}

void quickSort(int a[], int left, int right) {
    if (right - left < 1) {
        return;
    }

    int p = partition(a, left, right);

    quickSort(a, left, p - 1);
    quickSort(a, p + 1, right);
}