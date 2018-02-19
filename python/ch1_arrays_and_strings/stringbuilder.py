class StringBuilder:
    '''
    StringBuilder Implementation as described in Cracking the Coding interview
    StringBuilder allows efficient concatenation of strings

    Note: Redundant, as Python's list type can be used as a 'StringBuilder'
    '''
    def __init__(self):
        self.arr = []

    def __repr__(self):
        return self.__str__()
        
    def __str__(self):
        return self.to_string()

    def append(self, val):
        self.arr.append(str(val))

    def to_string(self):
        return ''.join(self.arr)
