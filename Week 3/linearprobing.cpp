class Element {
public:
    int key;
    int value;
    int state; // -1: da~ xoa', 0: trong', 1: da~ chua'

    Element() : key(0), value(0), state(0) {
    }

    Element(int key, int value) : key(key), value(value), state(1) {   
    } 
};

class Hashtable {
public:
    vector<Element> v;
    int capacity;
    int size;

    Hashtable(int capacity) : capacity(capacity), size(0), v(capacity) {
    }

    int hash(int key) {
        return abs(key) % capacity;
    }

    bool insert(int key, int value) {
        int h = hash(key);
        bool first = false;
        int index;
        for (int i = 0; i < capacity; i++) {
            h = hash(h);
            if (v[h].state == 0) {
                if (!first) {
                    index = h;
                }
                break;
            }
            if (!first && v[h].state == -1) {
                first = true;
                index = h;
            }
            if (v[h].state == 1 && v[h].key == key) {
                v[h].value = value;
                return false;
            }
            h++;
        }
        if (capacity == size) {
            return false;
        }
        Element e(key, value);
        v[index] = e;
        size++;
        return true;
    }

    bool find(int key) {
        int h = hash(key);
        for (int i = 0; i < capacity; i++) {
            h = hash(h);
            if (v[h].state == 0) {
                return false;
            }
            if (v[h].state == 1 && v[h].key == key) {
                return true;
            }
            h++;
        }
        return false;
    }

    bool erase(int key) {
        int h = hash(key);
        for (int i = 0; i < capacity; i++) {
            h = hash(h);
            if (v[h].state == 0) {
                return false;
            }
            if (v[h].state == 1 && v[h].key == key) {
                v[h].state = -1;
                size--;
                return true;
            }
            h++; 
        }
        return false;
    }
};