class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

class List:
    def __init__(self):
        self.head = None
        self.tail = None

    def push(self, data):
        new_node = Node(data)
        if self.head == None:
            self.head = new_node
            self.tail = new_node
        else:
            new_node.next = self.head
            self.head.prev = new_node
            self.head = new_node

    def pop_front(self):
        if self.head is not None:
            data = self.head.data
            self.head.next.prev = None
            self.head = self.head.next
            return data
        raise IndexError('List is empty')

    def append(self, data):
        new_node = Node(data)
        if self.head == None:
            self.head = new_node
            self.tail = new_node
        else:
            new_node.prev = self.tail
            self.tail.next = new_node
            self.tail = new_node

    def pop_back(self):
        if self.head is not None:
            data = self.tail.data
            self.tail.prev.next = None
            self.tail = self.tail.prev
            return data
        raise IndexError('List is empty')

    def __repr__(self):
        sb = []
        itr = self.head
        while itr is not None:
            sb.append(str(itr.data))
            itr = itr.next
        return '->'.join(sb)
