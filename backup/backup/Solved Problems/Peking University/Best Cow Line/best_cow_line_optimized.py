def best_cow_line(string, n):

    i, j = 0, n - 1
    T = ''
    
    while i <= j:
                
        a = 0
        left = False
        while i + a <= j:
            if string[i + a] < string[j - a]:
                left = True
                break
            elif string[i + a] > string[j - a]:
                left = False
                break
            a += 1
            
        if left:
            T += string[i]
            i += 1
        else:
            T += string[j]
            j -= 1
    
    return T

N = int(input())
string = ''
for _ in range(N):
    string += input()
    
print(best_cow_line(string, N))