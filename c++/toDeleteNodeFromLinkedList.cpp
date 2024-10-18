#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        if (node == nullptr || node->next == nullptr) {
            // Edge case: cannot delete the last node or a null node using this method
            return;
        }
        // Copy the value of the next node to the current node
        node->val = node->next->val;
        // Skip the next node
        ListNode* temp = node->next;
        node->next = node->next->next;
        delete temp; // Free the memory of the deleted node
    }
};

// Function to create a linked list from an array
ListNode* createLinkedList(int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < n; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Function to print the linked list
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "null" << endl;
}

int main() {
    int arr[] = {4, 5, 1, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    ListNode* head = createLinkedList(arr, n);
    cout << "Original Linked List: ";
    printLinkedList(head);

    Solution sol;
    ListNode* nodeToDelete = head->next; // This is the node with value 5
    sol.deleteNode(nodeToDelete);

    cout << "Linked List after deleting node with value 5: ";
    printLinkedList(head);

    // Cleanup: Free allocated memory
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
