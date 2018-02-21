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

    def pop(self, idx=None):
        if idx is None:
            data = self.arr[self.size - 1]
        elif idx >= self.size:
            raise IndexError('Index out of range.')
        else:
            data = self.arr[idx]
            self.arr[idx:] = self.arr[idx+1:self.size]

        self.size -= 1

        if self.size <= self.capacity / 4:
            self.resize(1/2)

        return data

    def insert(self, idx, data):
        if self.size == self.capacity:
            self.resize(2)

        if idx > self.size:
            raise IndexError('Index out of range.')
        elif idx == self.size:
            self.append(data)
        else:
            to_shift = self.arr[idx:self.size]
            self.arr[idx] = data
            self.arr[idx+1:] = to_shift
            self.size += 1

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
