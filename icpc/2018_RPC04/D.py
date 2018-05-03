while True:
    try:
        n = input()
    except Exception as e:
        break
    if int(n, 16) % 17 == 0:
        print('yes')
    else:
        print('no')
