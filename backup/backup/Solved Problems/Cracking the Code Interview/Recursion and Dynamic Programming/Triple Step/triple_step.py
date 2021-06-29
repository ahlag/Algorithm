# Give the number of ways to climb n steps 1, 2, or 3 steps at a time.
import unittest

def triple_step(n):
    
    if n < 0:
        return 0
    elif n == 0:
        return 1
    else:
        return triple_step(n-1) + triple_step(n-2) + triple_step(n-3)
    
    
def triple_step_memo(n, memo):
    
    if memo[n] is not None:
        return memo[n]
    
    if n < 0:
        return 0
    elif n == 0:
        return 1
    else:
        memo[n] = triple_step_memo(n-1, memo) + triple_step_memo(n-2, memo) + triple_step_memo(n-3, memo)
    
    return memo[n]

def triple_step_dp(n):
    
    if n <= 1:
        return 1
    elif n == 2:
        return 2
    
    counts = [None] * (n + 3)
    counts[0] = 1
    counts[1] = 1
    counts[2] = 2
    for i in range(3,n+1):
        counts[i] = counts[i - 1] + counts[i - 2] + counts[i - 3]
        
    return counts[n]

def triple_step_dp_modulo(n):
    
    counts = [1, 1, 2]
    
    if n < 3:
        return counts[n]
    
    i = 2
    while i < n:
        i += 1
        counts[i % 3] = sum(counts)
    return counts[i % 3]

class Test(unittest.TestCase):
    def test_triple_step(self):
        self.assertEqual(triple_step(3), 4)
        self.assertEqual(triple_step(7), 44)
        self.assertEqual(triple_step_memo(3, 4 * [None]), 4)
        self.assertEqual(triple_step_memo(7, 8 * [None]), 44)
        self.assertEqual(triple_step_dp(3), 4)
        self.assertEqual(triple_step_dp(7), 44)
        self.assertEqual(triple_step_dp_modulo(3), 4)
        self.assertEqual(triple_step_dp_modulo(7), 44)

if __name__ == "__main__":
    unittest.main()