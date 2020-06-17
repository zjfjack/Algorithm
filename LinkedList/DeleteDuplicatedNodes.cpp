#include "ListNode.hpp"

void deleteDuplicatedNodes(ListNode** head)
{
    if (head == nullptr)
        return;

    ListNode* node = *head;
    ListNode* prev = nullptr;

    while (node)
    {
        ListNode* next = node->next;
        bool needDeleteNode = next && node->val == next->val;
        if (needDeleteNode)
        {
            int needDeleteVal = node->val;
            while (node && node->val == needDeleteVal)
            {
                next = node->next;
                delete node;
                node = nullptr;
                node = next;
            }
            if (prev == nullptr)
                *head = node;
            else
                prev->next = node;
        }
        else
        {
            prev = node;
            node = next;
        }
    }
}

int main()
{
    int array[] = { 1, 1, 2, 3, 4, 5, 6, 6 };
    ListNode* head = new ListNode(array, std::end(array));
    deleteDuplicatedNodes(&head);
    ListNode::printLinkedList(head);
}