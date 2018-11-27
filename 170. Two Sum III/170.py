class TwoSum(object):
    def __init__(self):
        self.table = {}         #key为数字 value为出现次数

    def add(self,num):
        if num in self.table:
            self.table[num] += 1
        else:
            self.table[num] = 1

    def find(self,target):
        for key in self.table:
            num = target - key
            if num == key and self.table[num] > 1:
                return True
            elif num != key and num in self.table:
                return True
        return False

s = TwoSum()
s.add(3)
s.add(2)
s.add(3)
print(s.find(4))
print(s.find(5))
print(s.find(6))

