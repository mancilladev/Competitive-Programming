from datetime import datetime, timedelta

t1 = datetime.strptime(input(), '%H:%M:%S')
t2 = datetime.strptime(input(), '%H:%M:%S')

if t2 < t1:
    t2 += timedelta(days=1)
t2 -= t1
s = str(t2)
if s == '0:00:00':
    print('24:00:00')
else:
    print("{:0>8}".format(s))
