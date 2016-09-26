def score(word):
    char_position = [ord(c)-64 for c in word[1:-1]]
    return sum(char_position)

with open('file_022.txt', 'r') as fopen:
    content = fopen.readlines()[0]
    words = sorted(content.split(','))
    total = 0
    for i in range(len(words)):
        total += ((i+1) * score(words[i]))
    print(total)

