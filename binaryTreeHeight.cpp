#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

int findMax(Node* root) {
    if (root == nullptr) {
        return -1;
    }

    Node* current = root;
    while (current != nullptr && current->right != nullptr) {
        current = current->right;
    }

    return current->data;
}

int findMin(Node* root) {
    if (root == nullptr) {
        return -1;
    }

    Node* current = root;
    while (current != nullptr && current->left != nullptr) {
        current = current->left;
    }

    return current->data;
}

int height(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return max(leftHeight, rightHeight) + 1;
}

int main() {
    Node* root = nullptr;
    int numValues, value;

    cout << "How many numbers will you enter? ";
    cin >> numValues;

    cout << "Enter the numbers: " << endl;
    for (int i = 0; i < numValues; i++) {
        cin >> value;
        root = insert(root, value);
    }

    cout << "Maximum value in the tree: " << findMax(root) << endl;
    cout << "Minimum value in the tree: " << findMin(root) << endl;
    cout << "Height of the tree: " << height(root) << endl;

    return 0;
}
