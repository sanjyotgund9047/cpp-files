/*. Create a class called LIST with two pure virtual function store() and retrieve(). To store a
value call store and to retrieve call retrieves function. Derive two classes stack and queue
from it and override store and retrieve.*/
#include <iostream>

using namespace std;

// Base class LIST
class LIST {
public:
    // Pure virtual function to store a value
    virtual void store(int value) = 0;

    // Pure virtual function to retrieve a value
    virtual int retrieve() = 0;
};

// Derived class Stack from LIST
class Stack : public LIST {
private:
    int data[100];
    int top;

public:
    // Constructor to initialize stack
    Stack() : top(-1) {}

    // Override store function to push value onto stack
    void store(int value) override {
        if (top >= 99) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        data[++top] = value;
    }

    // Override retrieve function to pop value from stack
    int retrieve() override {
        if (top < 0) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        return data[top--];
    }
};

// Derived class Queue from LIST
class Queue : public LIST {
private:
    int data[100];
    int front;
    int rear;

public:
    // Constructor to initialize queue
    Queue() : front(0), rear(-1) {}

    // Override store function to enqueue value into queue
    void store(int value) override {
        if (rear >= 99) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        data[++rear] = value;
    }

    // Override retrieve function to dequeue value from queue
    int retrieve() override {
        if (front > rear) {
            cout << "Queue Underflow!" << endl;
            return -1;
        }
        return data[front++];
    }
};

int main() {
    Stack stack;
    Queue queue;

    // Store values into stack
    stack.store(10);
    stack.store(20);
    stack.store(30);

    // Retrieve values from stack
    cout << "Values retrieved from stack:" << endl;
    cout << stack.retrieve() << endl;
    cout << stack.retrieve() << endl;
    cout << stack.retrieve() << endl;

    // Store values into queue
    queue.store(100);
    queue.store(200);
    queue.store(300);

    // Retrieve values from queue
    cout << "\nValues retrieved from queue:" << endl;
    cout << queue.retrieve() << endl;
    cout << queue.retrieve() << endl;
    cout << queue.retrieve() << endl;

    return 0;
}

/*Output
Values retrieved from stack:
30
20
10

Values retrieved from queue:
100
200
300
*/