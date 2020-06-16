#include "ListNode.hpp"

void DeleteNodeInLinkedList(ListNode** head, ListNode* node)
{
    if (!head || !node)
        return;

    // node is not tail pointer
    if (node->next != nullptr)
    {
        ListNode* next = node->next;
        node->val = next->val;
        node->next = next->next;
        delete next;
        next = nullptr;
    }
    // node is tail pointer and only one node in this list
    else if (node == *head)
    {
        delete node;
        node = nullptr;
        *head = nullptr;
    }
    else
    {
        ListNode* currentNode = *head;
        while (currentNode->next != node)
            currentNode = currentNode->next;
        currentNode->next = nullptr;
        delete node;
        node = nullptr;
    }
}

int main()
{
    ListNode* deleteMidNode = new ListNode(2, new ListNode(3, nullptr));
    ListNode* headNode1 = new ListNode(1, deleteMidNode);
    DeleteNodeInLinkedList(&headNode1, deleteMidNode);
    ListNode::printLinkedList(headNode1);

    ListNode* deleteOnlyHeadNode = new ListNode(1, nullptr);
    DeleteNodeInLinkedList(&deleteOnlyHeadNode, deleteOnlyHeadNode);
    ListNode::printLinkedList(deleteOnlyHeadNode);

    ListNode* deleteTailNode = new ListNode(3, nullptr);
    ListNode* headNode2 = new ListNode(1, deleteTailNode);
    DeleteNodeInLinkedList(&headNode2, deleteTailNode);
    ListNode::printLinkedList(headNode2);
}