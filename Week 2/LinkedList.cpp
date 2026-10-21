class Node {
public:
    int data;
    Node* next;

    Node() {
        data = 0;
        next = nullptr;
    }

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Stack {
public:
    Node* head;
    int n = 0;

    Stack() {
        head = nullptr;
        n = 0;
    }

    bool isEmpty() {
        return (n == 0);
    }

    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
        n++;
    }

    int pop() {
        if (n == 0) {
            return -1;
        }
        Node* temp = head;
        head = head->next;
        int a = temp->data;
        delete temp;
        n--;
        return a;
    }

    int top() {
        if (n == 0) {
            return -1;
        } else {
            return head->data;
        }
    }

    int size() {
        return n;
    }
};

class Queue {
public:
    Node* head;
    Node* tail;
    int n;

    Queue() {
        head = nullptr;
        tail = nullptr;
        n = 0;
    }

    bool isEmpty() {
        return (n == 0);
    }

    void enqueue(int x) {
        Node* newNode = new Node(x);
        if (isEmpty()) {
            head = newNode;
        } else {
            tail->next = newNode;         
        }
        n++;
        tail = newNode;
        return;
    }

    int dequeue() {
        if (isEmpty()) {
            return -1;
        }
        Node* temp = head;
        head = head->next;
        n--;
        int a = temp->data;
        delete temp;
        if (isEmpty()) {
            tail = nullptr;
        }
        return a;
    }

    int front() {
        if (isEmpty()) {
            return -1;
        } else {
            return head->data;
        }
    }

    int size() {
        return n;
    }
};

// Do phuc tap thoi gian va bo nho phu deu la O(1)