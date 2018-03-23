from datetime import timedelta as TD
import math

def discount(h, c):
    if 20 <= h:
        return c * 0.8
    return c

h, m = map(int, input().split(' '))
H, D, C, N = map(int, input().split(' '))

now = discount(h, C) * math.ceil(H / N)
later = now
if h < 20:
    sec_until_8 = TD(hours=20) - TD(hours=h, minutes=m)
    hunger = H + D * math.ceil(sec_until_8.seconds / 60)
    later = discount(20, C) * math.ceil(hunger / N)

print('{:.4f}'.format(min(now, later)))

