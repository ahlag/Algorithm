n, m = list(map(int, input().split()))

nums = [-1] * n

for i in range(m):
    s, c = list(map(int, input().split()))
    
    ## Check if the number contradicts - an index has two or more numbers suggested
    if nums[s-1] != -1 and nums[s-1] != c:
        print(-1)
        exit()
    nums[s-1] = c
    
## If the size of integer is 1, then print out the number
if n == 1:
    print(max(nums[0],0))
    exit()
    
## If the first integer is set specifically to zero, then print -1. There shouldn't be  trailing zero
if nums[0] == 0:
    print(-1)
    exit()
    
guess = 0

## If the first integer is not set, set the first integer to 1
if nums[0] == -1:
    nums[0] = 1

exponent = 1
while nums:
    num = nums.pop()
    if num != -1:
        guess += num * exponent
    exponent *= 10
    
print(guess)