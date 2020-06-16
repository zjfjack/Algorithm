#include "ListNode.h"

void reverseLinkedList(ListNode** head)
{
    ListNode* current = *head;
    ListNode *prev = nullptr, *next = nullptr;

    while (current)
    {
        // Store next
        next = current->next;

        // Reverse current node's pointer 
        current->next = prev;

        // Move pointers one position ahead
        prev = current;
        current = next;
    }
    // Replace header to last prev
    *head = prev;
}