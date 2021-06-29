n = int(input())
people = list(map(int, input().split()))
total_people = sum(people)

if total_people % n != 0:
    print(-1)
    exit()

avg = total_people / n

subtotal = 0
islands = 0
res = 0
for i in range(n):

    subtotal += people[i] 
    islands += 1
    moving_avg = subtotal / islands 
    if moving_avg == avg:
        res += islands - 1
        subtotal = 0
        islands = 0
        
print(res)

    



    
