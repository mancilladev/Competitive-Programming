fibonacci_numbers = [1,1]

while len(str(fibonacci_numbers[-1])) < 1000:
    fibonacci_numbers.append(fibonacci_numbers[-1] + fibonacci_numbers[-2])

print(len(fibonacci_numbers))
