#include <iostream>
#include <stack>
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
    std::cout << std::endl;
}

void printLinkedListReverseImmutableStack(ListNode* head)
{
    std::stack<int> stack;
    ListNode* node = head;
    while (node)
    {
        stack.push(node->val);
        node = node->next;
    }
    while (!stack.empty())
    {
        std::cout << stack.top();
        stack.pop();
    }
    std::cout << std::endl;
}

void printLinkedListReverseImmutableRecursive(ListNode* head)
{
    if (!head)
        return;
    printLinkedListReverseImmutableRecursive(head->next);
    std::cout << head->val;
}

int main()
{
    ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(3, nullptr)));
    printLinkedListReverseMutable(&list1);

    ListNode* list2 = new ListNode(1, new ListNode(2, new ListNode(3, nullptr)));
    printLinkedListReverseImmutableStack(list2);
    printLinkedListReverseImmutableRecursive(list2);
}