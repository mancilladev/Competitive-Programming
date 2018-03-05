import random

class Pos:
    def __init__(self, x, y, z):
        self.f = [x, y, z]

    def __str__(self):
        return '(' + ' '.join(str(x) for x in self.f) + ')'

    def __eq__(self, other):
        return self.f == other.f

    def __setitem__(self, i, val):
        self.f[i] = val

    def __getitem__(self, i):
        return self.f[i]

    def randomMove(self, foe):
        i = random.choice([0,1,2])
        v = random.choice([-1,1])
        self[i] += v
        if self == foe:
            self[i] -= v
            self.randomMove(foe)

    def move(self, target, foe):
        if self == target:
            return
        positions = list(range(3))
        random.shuffle(positions)
        for i in positions:
            if not self[i] == target[i]:
                d = target[i] - self[i]
                self[i] += (d > 0) - (d < 0)
                if (self == foe):
                    print('collision: ', self, foe)
                    self[i] -= (d > 0) - (d < 0)
                    self.randomMove(foe)
                else:
                    break


in1 = list(map(int, input().split(' ')))
in2 = list(map(int, input().split(' ')))

a, at = Pos(*in1[:3]), Pos(*in1[3:])
b, bt = Pos(*in2[:3]), Pos(*in2[3:])

print(a, b)
#for i in range(2000):
    #a.randomMove(b)
    #b.randomMove(a)
    #print(a, b)
while not (a == at and b == bt):
    a.move(at, b)
    b.move(bt, a)
    print(a, b)
