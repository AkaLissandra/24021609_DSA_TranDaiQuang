const int MAX = 100;

struct SymbolTable {
    string keys[MAX];
    int values[MAX];
    int n = 0;

    int rank(string key) {
        int left = 0;
        int right = n - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (keys[mid] == key)
                return mid;

            if (keys[mid] < key)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return left;
    }

    void put(string key, int value) {
        int i = rank(key);

        // Neu key da ton tai thi cap nhat
        if (i < n && keys[i] == key) {
            values[i] = value;
            return;
        }

        if (n == MAX) {
            cout << "Mang da day!" << endl;
            return;
        }

        for (int j = n; j > i; j--) {
            keys[j] = keys[j - 1];
            values[j] = values[j - 1];
        }

        // Chen phan tu moi
        keys[i] = key;
        values[i] = value;
        n++;
    }


    bool get(string key, int &value) {
        int i = rank(key);

        if (i < n && keys[i] == key) {
            value = values[i];
            return true;
        }

        return false;
    }

    bool contains(string key) {
        int i = rank(key);

        return (i < n && keys[i] == key);
    }

    void removeKey(string key) {
        int i = rank(key);

        if (i == n || keys[i] != key)
            return;

        // Dich cac phan tu sang trai
        for (int j = i; j < n - 1; j++) {
            keys[j] = keys[j + 1];
            values[j] = values[j + 1];
        }

        n--;
    }

    bool isEmpty() {
        return n == 0;
    }

    int size() {
        return n;
    }

    void display() {
        for (int i = 0; i < n; i++) {
            cout << keys[i] << " : "
                 << values[i] << endl;
        }
    }
};