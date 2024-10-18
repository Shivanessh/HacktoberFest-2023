#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

// Global pointer to the first node of the linked list
Node* first = nullptr;

void Create(int A[], int n) {
    Node* t, * last;
    first = new Node; // Create the first node
    first->data = A[0];
    first->next = nullptr;
    last = first; // Set last to the first node

    // Create the rest of the nodes
    for (int i = 1; i < n; i++) {
        t = new Node; // Create a new node
        t->data = A[i];
        t->next = nullptr;
        last->next = t; // Link the last node to the new node
        last = t; // Update last to the new node
    }
}

Node* Search(Node* head, int key) {
    Node* p = head;
    while (p != nullptr) {
        if (p->data == key) {
            cout << "\nElement found";
            return p;
        }
        p = p->next;
    }
    cout << "\nElement not found";
    return nullptr;
}

Node* RecSearch(Node* head, int key) {
    if (head == nullptr)
        return nullptr; // Base case: key not found
    if (head->data == key)
        return head; // Key found
    return RecSearch(head->next, key); // Recursive call
}

int main() {
    int n, a[100];
    cout << "Enter the size of the array: ";
    cin >> n;

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    Create(a, n); // Create the linked list

    int key;
    cout << "\nEnter the element to be searched: ";
    cin >> key;

    // Search using recursion
    Node* p = RecSearch(first, key);
    if (p == nullptr)
        cout << "\nElement not found";
    else
        cout << "\nElement found: " << p->data;

    return 0;
}
