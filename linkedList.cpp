#include <iostream>
using namespace std;

// Node class: Represents each node in the linked list
class Node {
    public:
        int value;  
        Node* next; 

        // Constructor: Initializes a new node with a given value
        Node(int value) {
            this->value = value;
            next = NULL;
        }
};

// LinkedList class: Defines the linked list structure and operations
class LinkedList {
    private:
        Node* head; 
        Node* tail; 
        int count;  

    public:
        // Constructor: Initializes the list with a single node
        LinkedList(int value) {
            Node* node = new Node(value);
            head = node;
            tail = node;
            count = 1;
        }

        // Destructor: Deletes all nodes in the list
        ~LinkedList() {
            cout << "Entire list deleted" << endl;
            Node* temp = head;
            while (head != NULL) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }

        // Prints the first node
        void printHead() {
            if (head != NULL)
                cout << "Head: " << head->value << endl;
        }

        // Prints the last node
        void printTail() {
            if (tail != NULL)
                cout << "Tail: " << tail->value << endl;
        }

        // Prints the total number of nodes
        void getCount() {
            cout << "List Count: " << this->count << endl;
        }

        // Adds a new node at the end of the list
        void appendList(int value) {
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

        // Prints all nodes in the list
        void printList() {
            Node* temp = head;
            while (temp != NULL) {
                cout << temp->value << " , ";
                temp = temp->next;
            }
            cout << endl;
        }

        // Deletes the last node of the list
        void deleteLastNode() {
            if (count == 0) 
                return;

            Node* temp1 = head;
            Node* temp2 = head;

            while (temp1->next) {
                temp2 = temp1;
                temp1 = temp1->next;
            }

            tail = temp2;
            tail->next = NULL;
            count--;
            if (count == 0) {
                head = NULL;
                tail = NULL;
            }

            delete temp1;
        }

        // Deletes the first node of the list
        void deleteFirst() {
            if (count == 0) 
                return;

            Node* temp = head;

            if (count == 1) {
                head = NULL;
                tail = NULL;
            } else {
                head = head->next;
            }
            delete temp;
            count--;
        }

        // Finds a node with a given value
        Node* find(int value) {
            Node* temp = head;
            while (temp != NULL) {
                if (temp->value == value) {
                    return temp;
                }
                temp = temp->next;
            }
            return NULL;
        }

        // Finds the previous node of a given node
        Node* findPrevious(Node* node) {
            if (node == NULL || node == head) {
                return NULL;
            }

            Node* temp = head;
            while (temp != NULL && temp->next != node) {
                temp = temp->next;
            }
            return temp;
        }

        // Deletes a node with a given value
        void deleteNodeByValue(int value) {
            Node* target = find(value);
            if (!target) {
                cout << "Value not found: " << value << endl;
                return;
            }

            Node* prev = findPrevious(target);
            if (prev) {
                prev->next = target->next;
                if (target == tail) {
                    tail = prev;
                }
            } else {
                head = target->next;
                if (head == NULL) {
                    tail = NULL;
                }
            }
            delete target;
            count--;
        }
};

int main() {
    LinkedList* linkedList1 = new LinkedList(12);
    linkedList1->appendList(5);
    linkedList1->appendList(24);
    linkedList1->appendList(8);
    linkedList1->appendList(7);

    linkedList1->getCount();
    linkedList1->printHead();
    linkedList1->printTail();
    linkedList1->printList();

    linkedList1->deleteNodeByValue(24);
    linkedList1->printList();

    linkedList1->deleteNodeByValue(8);
    linkedList1->printList();

    delete linkedList1;
    return 0;
}
