#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to detect cycle
bool hasCycle(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return false;

    struct ListNode* slow = head;
    struct ListNode* fast = head->next;

    while (slow != fast) {
        if (fast == NULL || fast->next == NULL)
            return false;
        slow = slow->next;
        fast = fast->next->next;
    }

    return true;
}

// Helper to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Test the cycle detection
int main() {
    struct ListNode* a = createNode(3);
    struct ListNode* b = createNode(2);
    struct ListNode* c = createNode(0);
    struct ListNode* d = createNode(-4);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = b;  // Creates a cycle back to node b

    if (hasCycle(a))
        printf("Cycle detected!\n");
    else
        printf("No cycle.\n");

    // Note: Since there’s a cycle, we don't free memory here to avoid infinite loop.

    return 0;
}
