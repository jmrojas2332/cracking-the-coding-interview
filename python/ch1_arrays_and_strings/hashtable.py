class KeyValuePair:
    def __init__(self, key, val):
        self.key = key
        self.val = val

class HashMap:
    def __init__(self, capacity=53):
        self.table = []
        self.capacity = capacity
        for i in range(capacity):
            self.table.append([])

    def __repr__(self):
        return self.__str__()

    def __str__(self):
        sb = []
        for ls in self.table:
            for kv in ls:
                sb.append(str(kv.key) + ': ' + str(kv.val))
        return '{' + ', '.join(sb) + '}'

    def __contains__(self, key):
        for pair in self.table[hash(key) % self.capacity]:
            if key == pair.key:
                return True # todo: handle error
        return False

    def __getitem__(self, key):
        for pair in self.table[hash(key) % self.capacity]:
            if key == pair.key:
                return pair.val

    def __setitem__(self, key, val):
        pair = KeyValuePair(key, val)
        ls = self.table[hash(key) % self.capacity]  # get current list

        for idx in range(len(ls)):
            if key == ls[idx].key:  # if exists, then update
                ls[idx].val = val
                return
        ls.append(pair)  # append if not exists

    def __delitem__(self, key):
        ls = self.table[hash(key) % self.capacity]  # get current list
        for idx in range(len(ls)):
            if key == ls[idx].key:  # if exists, then delete
                del ls[idx]

class HashSet:
    def __init__(self, capacity=53):
        self.table = []
        self.capacity = capacity
        for i in range(capacity):
            self.table.append([])

    def __repr__(self):
        return self.__str__()
        
    def __str__(self):
        sb = []
        for ls in self.table:
            for val in ls:
                sb.append(str(val))
        return '{' + ', '.join(sb) + '}'

    def __contains__(self, val):
        if val in self.table[hash(val) % self.capacity]:
            return True
        else:
            return False

    def add(self, val):
        if val not in self.table[hash(val) % self.capacity]:
            self.table[hash(val) % self.capacity].append(val)

    def remove(self, val):
        ls = self.table[hash(val) % self.capacity]  # get current list
        for idx in range(len(ls)):
            if val == ls[idx]:
                del ls[idx]
