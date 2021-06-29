import numpy as np
N = int(input())
L = list(map(int,input().split()))

cost = 0
while(1):
    argindex = np.argsort(L)
    l1 = L[argindex[0]]
    l2 = L[argindex[1]]

    L = np.delete(L, argindex[0])
    L = np.delete(L,argindex[1]-1)

    cost += l1 + l2

    L = np.append(L, l1  + l2)

    if len(L) ==1:
        break
    
print(cost)