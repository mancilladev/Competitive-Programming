def isd(x):
    try: return int(x)
    except: return None

def order(arr):
    nums = [isd(x) for x in arr if isd(x) != None]
    words = [s for s in arr if isd(s) == None]
    nums.sort()
    words.sort(key=lambda s : s.lower())

    ni, nw = 0, 0
    res = []
    for s in arr:
        if isd(s) == None:
            res.append(words[nw])
            nw += 1
        else:
            res.append(str(nums[ni]))
            ni += 1
    return ', '.join(res)

while True:
    line = input()
    if line == '.':
        break
    print(order(line[:-1].split(', ')) + '.')
