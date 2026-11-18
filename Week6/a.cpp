struct Node {
    string key;
    int value;
    Node* next;
};

// Tao Symbol Table
struct SymbolTable {
    Node* head = NULL;

    // Them hoac cap nhat phan tu
    void put(string key, int value) {
        Node* p = head;

        // Kiem tra key da ton tai chua
        while (p != NULL) {
            if (p->key == key) {
                p->value = value;
                return;
            }
            p = p->next;
        }

        // Neu chua ton tai thi them vao dau
        Node* newNode = new Node;
        newNode->key = key;
        newNode->value = value;
        newNode->next = head;
        head = newNode;
    }

    // Tim value theo key
    bool get(string key, int &value) {
        Node* p = head;

        while (p != NULL) {
            if (p->key == key) {
                value = p->value;
                return true;
            }
            p = p->next;
        }

        return false;
    }

    // Kiem tra key co ton tai khong
    bool contains(string key) {
        Node* p = head;

        while (p != NULL) {
            if (p->key == key)
                return true;

            p = p->next;
        }

        return false;
    }

    void removeKey(string key) {
        Node* p = head;
        Node* prev = NULL;

        while (p != NULL) {
            if (p->key == key) {
                if (prev == NULL) {
                    head = p->next;
                } else {
                    prev->next = p->next;
                }

                delete p;
                return;
            }

            prev = p;
            p = p->next;
        }
    }

    bool isEmpty() {
        return head == NULL;
    }

    int size() {
        int count = 0;
        Node* p = head;

        while (p != NULL) {
            count++;
            p = p->next;
        }

        return count;
    }

    void display() {
        Node* p = head;

        while (p != NULL) {
            cout << p->key << " : " << p->value << endl;
            p = p->next;
        }
    }

    void clear() {
        while (head != NULL) {
            Node* p = head;
            head = head->next;
            delete p;
        }
    }

    ~SymbolTable() {
        clear();
    }
};