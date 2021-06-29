MAX_N = 100000

# 入力
N = int(input())
S = list(map(int,input().split()))
T = list(map(int,input().split()))

# 仕事をソートするための配列itv
itv = []

# 終了時間の早い順にしたいため、Tを配列の一つ目に、Sを二つ目に入れる
for i in range(N):
    itv.append([T[i], S[i]])
itv.sort()

# tは最後に選んだ仕事の終了時間
ans = 0
t = 0
for i in range(N):
    if t < itv[i][1]:
        ans += 1
        t = itv[i][0]
print(ans)