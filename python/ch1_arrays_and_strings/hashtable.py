class KeyValuePair:
    def __init__(self, key, val):
        self.key = key
        self.val = val

class HashMap:
    def __init__(self, capacity=53):
        self.capacity = capacity
        self.table = [[]] * capacity
        self.keys = []

    def put(self, key, val):
        for pair in self.table[hash(key) % self.capacity]:
            if pair.key == key:
                pair.val = val
                return
        self.table[hash(key) % self.capacity].append(KeyValuePair(key, val))
        self.keys.append(key)

    def __setitem__(self, key, val):
        self.put(key, val)

    def remove(self, key):
        arr = self.table[hash(key) % self.capacity]
        for idx in range(len(arr)):
            if arr[idx].key == key:
                del arr[idx]
                self.keys.remove(key)
        raise IndexError('Key does not exist.')

    def __delitem__(self, key):
        self.remove(key)

    def __contains__(self, key):
        for pair in self.table[hash(key) % self.capacity]:
            if pair.key == key:
                return True
        return False

    def __getitem__(self, key):
        for pair in self.table[hash(key) % self.capacity]:
            if pair.key == key:
                return pair.val
        raise IndexError('Key does not exist.')

    def __repr__(self):
        return '{' + ', '.join([str(key) + ': ' + str(self[key]) for key in self.keys]) + '}'

class HashSet:
    def __init__(self, capacity=53):
        self.capacity = capacity
        self.table = [[]] * capacity

    def add(self, key):
        if key not in self.table[hash(key) % self.capacity]:
            self.table[hash(key) % self.capacity].append(key)

    def remove(self, key):
        ls = self.table[hash(key) % self.capacity]  # get current list
        for idx in range(len(ls)):
            if key == ls[idx]:
                del ls[idx]
        raise IndexError('Key does not exist.')

    def __contains__(self, key):
        if key in self.table[hash(key) % self.capacity]:
            return True
        else:
            return False

    def __repr__(self):
        return '{' + ', '.join([str(key) for ls in self.table for key in ls]) + '}'
