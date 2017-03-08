def isPalindrome(n):
    r = str(n)[::-1]
    return str(n) == r, int(r)

lychrel_count = 10000
for i in range(10000):
    n = i + int(str(i)[::-1])
    for j in range(48):
        isp, r = isPalindrome(n)
        if isp:
            lychrel_count -= 1
            break
        n += r
print(lychrel_count)
