class StringBuilder:
    def __init__(self):
        self.arr = []

    def append(self, val):
        if type(val) is str:
            self.arr.append(val)
        else:
            self.arr.append(str(val))

    def pop(self):
        return self.arr.pop()

    def to_string(self):
        return ''.join(self.arr)

    def __repr__(self):
        return self.arr.__repr__()
