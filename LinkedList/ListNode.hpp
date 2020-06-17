#pragma once
#include <iostream>

struct ListNode {
    int val = 0;
    ListNode* next = nullptr;

    ListNode() = default;
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    ListNode(int *array, int *end)
    {
        val = *array;
        if (++array != end)
            next = new ListNode(array, end);
    }

    inline static void printLinkedList(ListNode* head);
    inline static void reverseLinkedList(ListNode** head);
};

void ListNode::printLinkedList(ListNode* head)
{
    ListNode* node = head;
    while (node)
    {
        std::cout << node->val;
        node = node->next;
    }
    std::cout << std::endl;
}

void ListNode::reverseLinkedList(ListNode** head)
{
    ListNode* current = *head;
    ListNode* prev = nullptr, * next = nullptr;

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