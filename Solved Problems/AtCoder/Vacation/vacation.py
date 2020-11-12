n = int(input())

a, b, c = [], [], []
dpa, dpb, dpc = [0] * n, [0] * n, [0] * n

for i in range(n):
    x, y, z = list(map(int, input().split()))
    a.append(x)
    b.append(y)
    c.append(z)
    
dpa[0] = a[0]
dpb[0] = b[0]
dpc[0] = c[0]

for i in range(1,n):
    dpa[i] += max(dpb[i-1], dpc[i-1]) + a[i]
    dpb[i] += max(dpa[i-1], dpc[i-1]) + b[i]
    dpc[i] += max(dpa[i-1], dpb[i-1]) + c[i]
    
print(max(dpa[n-1],dpb[n-1],dpc[n-1]))