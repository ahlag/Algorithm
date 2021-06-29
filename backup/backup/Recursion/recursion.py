def recursion(n):
    val = 0
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        val = recursion(n-1) + recursion(n-2)

    return val

print(recursion(0))
print(recursion(1))
print(recursion(5))
print(recursion(12))
