class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class List:
    def __init__(self):
        self.head = None

    def push(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def pop_front(self):
        if self.head is not None:
            data = self.head.data
            self.head = self.head.next
            return data
        raise IndexError('List is empty')

    def append(self, data):
        new_node = Node(data)

        if self.head is None:
            self.head = new_node
            return

        itr = self.head
        while itr.next is not None:
            itr = itr.next

        itr.next = new_node

    def pop_back(self):
        if self.head is not None:
            prev = None
            itr = self.head
            while itr.next is not None:
                prev = itr
                itr = itr.next

            data = itr.data
            prev.next = itr.next
            return data
        raise IndexError('List is empty')

    def __repr__(self):
        sb = []
        itr = self.head
        while itr is not None:
            sb.append(str(itr.data))
            itr = itr.next
        
        return '->'.join(sb)
