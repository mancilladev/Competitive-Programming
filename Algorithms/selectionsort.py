from random import randint


num = 10
A = [ randint(-num,num) for x in range(num) ]
print(A)

for i in range(len(A)):
    min_index = i + A[i:].index(min(A[i:]))
    A[i], A[min_index] = A[min_index], A[i]

print(A)
