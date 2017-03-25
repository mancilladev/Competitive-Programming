week = ["monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"]
days = [31, 28, 31, 30, 31]

m1 = week.index(input())
m2 = week.index(input())

b = False
for i in days:
    if (m1+i)%7 == m2:
        b = True
        break

if b:
    print("YES")
else:
    print("NO")
