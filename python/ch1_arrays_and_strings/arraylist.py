class ArrayList:
    def __init__(self, capacity=23):
        self.arr = [[None] * 23]
        self.capacity = 23
        self.size = 0

    def __repr__(self):
        return self.__str__()

    def __str__(self):
        sb = []
        for idx in range(self.size):
            sb.append(str(self.arr[idx]))
        return '[' + ', '.join(sb) + ']'

    def resize(self, factor):
        newArr = [[None] * int(self.capacity * factor)]
        for idx in range(self.size):
            newArr[idx] = self.arr[idx]
        self.arr = newArr
        self.capacity = int(self.capacity * factor)

    def push(self, obj):
        if self.size == self.capacity:
            self.resize(2)
        self.arr.insert(self.size, obj)
        self.size += 1

    def pop(self):
        val = self.arr[self.size - 1]
        self.arr[self.size - 1]
        self.size -= 1

        if self.size <= self.capacity / 4:
            self.resize(1/2)
        return val
