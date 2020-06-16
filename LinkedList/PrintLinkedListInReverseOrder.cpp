#include <iostream>
#include "ListNode.h"

extern void reverseLinkedList(ListNode** head);

void printLinkedListReverseMutable(ListNode** head)
{
    reverseLinkedList(head);

    ListNode* node = *head;
    while (node)
    {
        std::cout << node->val;
        node = node->next;
    }
}

int main()
{
    ListNode* list = new ListNode(1, new ListNode(2, new ListNode(3, nullptr)));
    printLinkedListReverseMutable(&list);
}