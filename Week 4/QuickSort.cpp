int partition(int a[], int left, int right) {
    int pivot = a[right];

    int x = left;
    int y = right - 1;

    while (x <= y) {
        if (a[x] > pivot && a[y] < pivot) {
            swap(a[x], a[y]);
        }
        if (a[x] <= pivot) {
            x++;
        }
        if (a[y] >= pivot) {
            y--;
        } 
    }

    swap(a[right], a[x]);

    return x;
}

void quickSort(int a[], int left, int right) {
    if (right <= left) {
        return;
    }

    int p = partition(a, left, right);

    quickSort(a, left, p - 1);
    quickSort(a, p + 1, right);
}