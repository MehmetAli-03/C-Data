#include <iostream>
#include <string>
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

class Queue {
private:
    Node* head;
    Node* tail;
    int count;

public:
    Queue() : head(NULL), tail(NULL), count(0) {}

    ~Queue() {
        Node* tmp = head;
        while (head) {
            head = head->next;
            delete tmp;
            tmp = head;
        }
    }

    void enqueue(int value) {
        Node* node = new Node(value);
        if (count == 0) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
        count++;
    }

    int dequeue() {
        if (count == 0)
            return INT_MIN;

        Node* tmp = head;
        int value = head->value;
        head = head->next;
        delete tmp;
        count--;
        if (count == 0)
            tail = NULL;
        return value;
    }

    int getCount() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }
};

int josephus(int n, int k) {
    Queue q;
    for (int i = 1; i <= n; i++) {
        q.enqueue(i);
    }
    while (q.getCount() > 1) {
        for (int i = 0; i < k - 1; i++) {
            q.enqueue(q.dequeue());
        }
        q.dequeue();
    }
    return q.dequeue();
}

bool isPalindrome(string str) {
    Queue q;
    for (char c : str) {
        q.enqueue(c);
    }
    for (int i = 0; i < str.length(); i++) {
        char front = q.dequeue();
        if (front != str[str.length() - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n = 7, k = 3;
    cout << "Josephus problem result (n=" << n << ", k=" << k << "): "
         << josephus(n, k) << endl;

    string str = "kayak";
    cout << "\"" << str << "\" is a palindrome? "
         << (isPalindrome(str) ? "Yes" : "No") << endl;

    str = "hello";
    cout << "\"" << str << "\" is a palindrome? "
         << (isPalindrome(str) ? "Yes" : "No") << endl;

    return 0;
}
