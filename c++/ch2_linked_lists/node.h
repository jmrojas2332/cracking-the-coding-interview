struct Node
{
    Node *next;
    int data;

    Node(int d) : next(nullptr), data(d)
    {
    }
};

void printNodeList(Node *itr)
{
    while (itr != nullptr)
    {
        std::cout << itr->data << "->";
        itr = itr->next;
    }
}
