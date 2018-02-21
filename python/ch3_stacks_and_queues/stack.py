class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Stack:
    def __init__(self):
        self.top = None

    def push(self, data):
        new_node = Node(data)
        new_node.next = self.top
        self.top = new_node

    def pop(self):
        if self.top is not None:
            data = self.top.data
            self.top = self.top.next
            return data
        raise IndexError('Stack is empty')

    def top(self):
        if self.top is not None:
            return self.top.data
        raise IndexError('Stack is empty')

    def __repr__(self):
        sb = []
        itr = self.top
        while itr is not None:
            sb.append(str(itr.data))
            itr = itr.next

        return '\n'.join(sb)
