// Cracking the Coding Interview Question 2.4 Partition
//
// Write code to partition a linked list around a value x, such that all nodes
// less than x come before all nodes greater than or equal to x. If x is
// contained within the list, the values of x only need to be after the elements
// less than x.

#include <iostream>
#include <memory>

struct Node
{
    Node *next;
    int data;

    Node(int d) : next(nullptr), data(d)
    {
    }
};

Node * partitionList(Node *itr, int x)
{
    Node *head = itr;
    Node *tail = itr;

    while (itr != nullptr)
    {
        Node *next = itr->next;
        if (itr->data < x)
        {
            itr->next = head;
            head = itr;
        }
        else
        {
            tail->next = itr;
            tail = itr;
        }

        itr = next;
    }

    tail->next = nullptr;

    return head;
}

int main()
{
    Node *head = new Node(0);
    Node *itr = head;

    for (int i = 10; i > 0; --i)
    {
        itr->next = new Node(i);
        itr = itr->next;
    }

    itr = head;
    while (itr != nullptr)
    {
        std::cout << itr->data << "->";
        itr = itr->next;
    }
    std::cout <<"\n";

    head = partitionList(head, 5);
    itr = head;
    while (itr != nullptr)
    {
        std::cout << itr->data << "->";
        itr = itr->next;
    }
    std::cout <<"\n";
}
