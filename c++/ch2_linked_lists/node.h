struct Node
{
    Node *next;
    int data;

    Node(int d) : next(nullptr), data(d)
    {
    }
};

void printList(Node *itr)
{
    while (itr != nullptr)
    {
        std::cout << itr->data << "->";
        itr = itr->next;
    }
}
