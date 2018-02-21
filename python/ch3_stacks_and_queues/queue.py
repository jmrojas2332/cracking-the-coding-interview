class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

class Queue:
    def __init__(self):
        self.head = None
        self.tail = None

    def get(self):
        if self.head is not None:
            data = self.head.data
            self.head.next.prev = None
            self.head = self.head.next
            return data
        raise IndexError('Queue is empty')

    def put(self, data):
        new_node = Node(data)
        if self.head == None:
            self.head = new_node
            self.tail = new_node
        else:
            new_node.prev = self.tail
            self.tail.next = new_node
            self.tail = new_node

    def __repr__(self):
        sb = []
        itr = self.head
        while itr is not None:
            sb.append(str(itr.data))
            itr = itr.next
        return ' '.join(sb)
