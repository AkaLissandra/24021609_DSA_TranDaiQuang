class Stack {
public:
    int a[1000];
    int n;

    Stack() {
        n = 0;
    }

    bool isEmpty() {
        return (n == 0);
    }

    bool isFull() {
        return (n >= 1000);
    }

    void push(int x) {
        if (isFull()) {
            return;
        }
        a[n] = x;
        n++;
    }

    int pop() {
        if (isEmpty()) {
            return -1;
        }
        n--;
        return a[n];
    }

    int top() {
        if (isEmpty()) {
            return -1;
        }
        return a[n - 1];
    }

    int size() {
        return n;
    }
};

class Queue {
public:
    int a[1000];
    int front;
    int back;
    int n;

    Queue() {
        front = 0;
        back = 0;
        n = 0;
    }

    bool isEmpty() {
        return (n == 0);
    }

    bool isFull() {
        return (n >= 1000);
    }

    void enqueue(int x) {
        if (isFull()) {
            return;
        }
        a[back] = x;
        back++;
        n++;
    }

    int dequeue() {
        if (isEmpty()) {
            return -1;
        }
        front++;
        n--;
        return a[front - 1];
    }
    
    int peek() {
        if (isEmpty()) {
            return -1;
        }
        return a[front];
    }

    int size() {
        return n;
    }
};

// Do phuc tap thoi gian va bo nho phu deu la O(1)