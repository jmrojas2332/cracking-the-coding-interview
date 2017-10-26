"""
Cracking the Coding Interview Question 2.5 Sum Lists

You have two numbers represented by a linked list, where each
node contains a single digit. The digits are stored in reverse order, such that
the 1's digit is at the head of the list. Write a function that adds the two
numbers and returns the sum as a linked list.
"""

import unittest

NUM_A = 17
NUM_B = 177

class node:
    """
    TODO: Move node class to its own file and call it list_node for code reuse.
          Move print methode along with it

    A List structure will be represented using zero or more nodes. 

    A node is a structure with two members, data and next, which will be used
    to represent the 'data' stored in a node and the 'next' node in the list.

    We can iterate a list by starting at the head node, stepping through its
    next node and repeating this until the tail node is reached. The head 
    (or first) node of the list is the node that is not preceeded by any nodes.
    The tail (or last) node of a list will be the node that does not have a
    next node. 

    Note: The head node should always be tracked, and more often than not be
    used to pass around the list, so no information is lost.
    """
    
    def __init__(self, data=None):
        self.data = data
        self.next = None

    def get_data(self):
        return self.data

    def get_next(self):
        return self.next

    def set_data(self, new_data):
        self.data = new_data

    def set_next(self, new_next):
        self.next = new_next


def sum_lists(headA, headB):
    """
    Function to calculate summation of two lists
    Returns a single node which represents the head of the list 
    """ 

    headSum = node()
    itr = headSum
    remainder = 0

    while (headA is not None and headB is not None) or remainder > 0:
        summation = remainder
        
        if headA is not None:
            summation += headA.get_data()

        if headB is not None:
            summation += headB.get_data()

        remainder = 1 if summation >= 10 else 0

        if itr.get_data() == None:
            itr.set_data(summation % 10)
        else:
            new_node = node(summation % 10)
            itr.set_next(new_node)
            itr = itr.get_next()
        
        if headA is not None:
            headA = headA.get_next()
        
        if headB is not None:
            headB = headB.get_next()

    while headA is not None:
        if itr.get_data() == None:
            itr.set_data(headA.get_data())
        else:
            new_node = node(headA.get_data())
            itr.set_next(new_node)
            itr = itr.get_next()
        headA = headA.get_next()

    while headB is not None:
        if itr.get_data() == None:
            itr.set_data(headB.get_data())
        else:
            new_node = node(headB.get_data())
            itr.set_next(new_node)
            itr = itr.get_next()
        headB = headB.get_next()

    return headSum

def print_list(head):
    """
    TODO: Move this and node class to a separate file for code reuse
    
    Function that is used to print out a list (node list) from head to tail
    """

    itr = head
    l = []
    while itr is not None:
        l.append(itr.get_data())
        itr = itr.get_next()
    print(l)

def num_to_list(num):
    """
    Helper function that is used while testing to convert a number to a list
    """

    itr = node()

    for n in str(num):        
        if itr.get_data() == None:
            itr.set_data(int(n))
        else:
            new_node = node(int(n))
            new_node.set_next(itr)
            itr = new_node
    return itr


def list_to_num(head):
    """
    Helper function that is used while testing to convert a list to a number
    """

    num = []
    while head is not None:
        num .insert(0,(str(head.get_data())))
        head = head.get_next()
    
    return int(''.join(num))

class Test(unittest.TestCase):
    numA = NUM_A
    numB = NUM_B
    headA = num_to_list(numA)
    headB = num_to_list(numB)

    def test_sum_lists(self):
        expected = self.numA + self.numB
        sumL = sum_lists(self.headA, self.headB)
        actual = list_to_num(sumL)
        
        """
        # For Debugging purposes

        print_list(self.headA) 
        print_list(self.headB) 
        print_list(sumL)
        """

        self.assertEqual(expected, actual)

if __name__ == '__main__':
    unittest.main()