// Cracking the Coding Interview Question 2.7 Intersection
//
// Given two (singly) linked lists, determine if the two lists intersect. Return
// the insecting node. Note that the intersection is defined based on reference,
// not value. That is, if the kth node of the first linked list is the exact
// same node (by reference) as the jth node of the second linked list, then they
// are intersecting.

#include <iostream>

#include "node.h"

int getNodeLength(Node *itr)
{
    int length = 0;
    while (itr)
    {
        ++length;
        itr = itr->next;
    }

    return length;
}

bool nodesIntersect(Node *itr1, Node *itr2)
{
    if (itr1 == nullptr || itr2 == nullptr)
    {
        return false;
    }

    if (itr1 == itr2)
    {
        return true;
    }

    int length1 = getNodeLength(itr1);
    int length2 = getNodeLength(itr2);
    Node * longer = length1 > length2 ? itr1 : itr2;
    Node * shorter = longer == itr1 ? itr2 : itr1;

    int diff = abs(length1 - length2);

    while (diff-- > 0)
    {
        longer = longer->next;
    }

    while (longer != nullptr && shorter != nullptr)
    {
        if (longer == shorter)
        {
            return true;
        }
        longer = longer->next;
        shorter = shorter->next;
    }

    return false;
}

int main()
{
    Node *head1 = new Node(0);
    Node *head2 = new Node(1);
    Node *head3 = new Node(2);
    Node *itr = head1;

    for (int i = 10; i > 0; --i)
    {
        itr->next = new Node(i);
        itr = itr->next;
    }

    itr = head2;
    head2->next = head1;
    itr = head3;

    for (int i = 100; i > 90; --i)
    {
        itr->next = new Node(i);
        itr = itr->next;
    }

    printNodeList(head1);
    std::cout << "\n";
    printNodeList(head2);
    std::cout << "\n";
    printNodeList(head3);
    std::cout << "\n";

    std::cout << "L1 intersects with L2: " << nodesIntersect(head1, head2) << "\n";
    std::cout << "L1 intersects with L3: " << nodesIntersect(head1, head3) << "\n";

    return 0;
}
