class Node {
public:
    int key;
    int value;
    Node* next;

    Node(int key, int value) : key(key), value(value), next(nullptr) {
    }
};

class Hashtable {
public:
    vector<Node*> v;
    int n;
    int sizee;

    Hashtable(int n) : n(n), sizee(0), v(n, nullptr) {
    }

    int hash(int key) {
        return abs(key) % n;
    }

    void insert(int key, int value) {  
        int h = hash(key);
        Node* temp = v[h];
        while (temp != nullptr) {
            if (temp->key == key) {
                temp->value = value;
                return;
            }
            temp = temp->next;
        }
        Node* newNode = new Node(key, value);
        newNode->next = v[h];
        v[h] = newNode;
        sizee++;
    }
    
    bool remove(int key) {
        int h = hash(key);
        Node* temp = v[h];
        if (temp == nullptr) {
            return false;
        }
        if (temp->key == key) {
            Node* removeNode = temp;
            v[h] = temp->next;
            delete removeNode;
            sizee--;
            return true;
        }
        while (temp->next != nullptr) {
            if (temp->next->key == key) {
                Node* removeNode = temp->next;
                temp->next = removeNode->next;
                delete removeNode;
                sizee--;
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    bool contains(int key) {
        int h = hash(key);
        Node* temp = v[h];
        while (temp != nullptr) {
            if (temp->key == key) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    int size() {
        return sizee;
    }
};