# S = input()
# T = input()

# S = list('?tc????')
# T = 'coder'

# S = list('?tc???r')
# T = 'code'

# S = list('??p??d??')
# T = 'abc'

S = list(input())
T = input()

n, m = len(S), len(T)

is_found = False

for i in range(n-m,-1,-1):
    for j in range(m):
        if S[i + j] == '?' or S[i + j] == T[j]:
            if j == m - 1:
                is_found = True
                final = i + j
                initial = final - m + 1
                S[initial:final+1] = T
        else:
            break
    
    if is_found:
        break

if is_found:
    print(''.join(S).replace('?', 'a'))
else:
    print('UNRESTORABLE')