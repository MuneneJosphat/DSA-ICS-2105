#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to find the node where the cycle begins
struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Cycle detected, now find entry point
            struct ListNode* start = head;
            while (start != slow) {
                start = start->next;
                slow = slow->next;
            }
            return start;
        }
    }

    return NULL; // No cycle
}

// Helper to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

int main() {
    // Create nodes
    struct ListNode* a = createNode(3);
    struct ListNode* b = createNode(2);
    struct ListNode* c = createNode(0);
    struct ListNode* d = createNode(-4);

    // Connect nodes with a cycle
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = b; // cycle starts at b

    struct ListNode* cycleStart = detectCycle(a);
    if (cycleStart)
        printf("Cycle starts at node with value: %d\n", cycleStart->val);
    else
        printf("No cycle.\n");

    return 0;
}
