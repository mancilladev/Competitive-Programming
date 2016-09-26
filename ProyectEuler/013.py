with open("file_013.txt", 'r') as fopen:
    print(sum([int(x) for x in fopen.readlines()]))
