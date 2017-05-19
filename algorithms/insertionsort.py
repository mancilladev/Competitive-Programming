from random import randint


num = 10
A = [ randint(-num,num) for x in range(num) ]

print(A)

for i in range(1,len(A)):
    j = i
    while j != 0 and A[j-1] > A[j]:
        A[j-1], A[j] = A[j], A[j-1]
        j -= 1

print(A)
