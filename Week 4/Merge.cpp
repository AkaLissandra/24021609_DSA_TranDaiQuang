
#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector<int> a, vector<int> b) {
    vector<int> result;

    int sz1 = a.size();
    int sz2 = b.size();
    int sz = sz1 + sz2;

    int i1 = 0;
    int i2 = 0;

    for (int i = 0; i < sz; i++) {
        if (i1 >= sz1) {
            result.push_back(b[i2]);
            i2++;
        }
        else if (i2 >= sz2) {
            result.push_back(a[i1]);
            i1++;
        }
        else if (a[i1] <= b[i2]) {
            result.push_back(a[i1]);
            i1++;
        }
        else {
            result.push_back(b[i2]);
            i2++;
        }
    }

    return result;
}

vector<int> mergeSort(vector<int> a) {
    
    if (a.size() <= 1) {
        return a;
    }

    
    int sz = a.size();
    vector<int> left;
    vector<int> right;

    for (int i = 0; i < sz; i++) {
        if (i < sz / 2) {
            left.push_back(a[i]);
        }
        else {
            right.push_back(a[i]);
        }
    }


    left = mergeSort(left);
    right = mergeSort(right);

    
    return merge(left, right);
}

int main() {
    vector<int> a = {7, 2, 6, 1, 9, 3};

    a = mergeSort(a);

    for (int x : a) {
        cout << x << " ";
    }

    return 0;
}
