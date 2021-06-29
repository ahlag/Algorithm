import string
n = int(input())

alphabets = []
alpha_dict = {n: ch for n, ch in enumerate(string.ascii_lowercase)}

while n:
    n -= 1
    num = n % 26
    alphabets.append(alpha_dict[num])
    n = n // 26

alphabets.reverse()

print(''.join(alphabets))