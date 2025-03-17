#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int value) {
        this->value = value;
        next = NULL;
    }
};

class Stack {
private:
    Node* top;
    int count;

public:
    Stack(int value) {
        Node* node = new Node(value);
        top = node;
        count = 1;
    }

    ~Stack() {
        Node* tmp = top;
        while (top != NULL) {
            top = top->next;
            delete tmp;
            tmp = top;
        }
    }

    void printAll() {
        Node* tmp = top;
        while (tmp != NULL) {
            cout << tmp->value << endl;
            tmp = tmp->next;
        }
    }

    void printTop() {
        if (top != NULL)
            cout << "Top value: " << top->value << endl;
        else
            cout << "Stack is empty!" << endl;
    }

    int getCount() {
        return count;
    }

    void push(int value) {
        Node* node = new Node(value);
        node->next = top;
        top = node;
        count++;
    }

    int pop() {
        if (count == 0) {
            cout << "Stack is empty! Cannot perform pop operation." << endl;
            return -1;
        }

        Node* tmp = top;
        int value = top->value;
        top = top->next;
        delete tmp;
        count--;
        return value;
    }

    bool isEmpty() {
        return count == 0;
    }
};

int main() {
    int Size;
    int value;

    cout << "How many numbers to enter in stack: " << endl;
    cin >> Size;

    Stack* stack = new Stack(0);

    for (int i = 0; i < Size; i++) {
        cout << "Enter value for stack: ";
        cin >> value;
        stack->push(value);
    }

    cout << "Stack contents:" << endl;
    stack->printAll();

    delete stack;
    return 0;
}
