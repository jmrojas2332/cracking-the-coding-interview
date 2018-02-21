class ArrayList:
    def __init__(self, capacity=23):
        self.capacity = capacity
        self.size = 0
        self.arr = [None] * capacity

    def append(self, data):
        if self.size == self.capacity:
            self.resize(2)

        self.arr[self.size] = data
        self.size += 1

    def pop(self):
        data = self.arr[self.size - 1]
        self.size -= 1

        if self.size <= self.capacity / 4:
            self.resize(1/2)

        return data

    def resize(self, factor):
        new_arr = [None] * int(self.capacity * factor)

        for idx in range(self.size):
            new_arr[idx] = self.arr[idx]

        self.arr = new_arr
        self.capacity = int(self.capacity * factor)

    def __getitem__(self, idx):
        if idx < self.size:
            return self.arr[idx]
        raise IndexError('Index out of range.')

    def __repr__(self):
        return '[' + ', '.join(str(self.arr[idx]) for idx in range(self.size)) + ']'
