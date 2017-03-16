num, den = 3, 2
cnt = 0
for i in range(999):
    num, den = num+2*den, num+den
    if len(str(num)) > len(str(den)):
        cnt += 1
print(cnt)
