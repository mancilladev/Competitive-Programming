import re


class Coord:
    x, y = None, None
    def __init__(self, x, y):
        self.x = int(x)
        self.y = int(y)
    def __str__(self):
        return f'({self.x}, {self.y})'


def inTriangle(p0, p1, p2):
    p = Coord(0,0)
    A = 1/2 * (-p1.y * p2.x + p0.y * (-p1.x + p2.x) + p0.x * (p1.y - p2.y) + p1.x * p2.y)
    sign = -1 if A < 0 else 1
    s = (p0.y * p2.x - p0.x * p2.y + (p2.y - p0.y) * p.x + (p0.x - p2.x) * p.y) * sign
    t = (p0.x * p1.y - p0.y * p1.x + (p0.y - p1.y) * p.x + (p1.x - p0.x) * p.y) * sign
    return s > 0 and t > 0 and (s + t) < 2 * A * sign


res = 0

with open('file_102.txt', 'r') as fin:
    for line in fin:
        text_pairs = re.findall('-?\d+,-?\d+',line)
        coords = list(map(lambda p: Coord(*p.split(',')), text_pairs))
        res += inTriangle(*coords)

print(res)

