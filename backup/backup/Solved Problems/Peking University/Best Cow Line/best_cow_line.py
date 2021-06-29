# O(N)
import time
import unittest

def best_cow_line(string):
    
    n = len(string)
    i, j = 0, n - 1
    T = ''
    
    while i <= j:
        if string[i] < string[j]:
            T += string[i]
            i += 1
        elif string[i] > string[j]:
            T += string[j]
            j -= 1
        else:
            S  = string[i:j+1]
            SR = string[::-1]
            if S < SR:
                T += string[i]
                i += 1
            else:
                T += string[j]
                j -= 1
    
    return T


class Test(unittest.TestCase):
    test_cases = [
        # no changes
        ("aaa", "aaa"),
        ("abc", "abc"),
        # with changes
        ("cba", "abc"),
        ("ACDBCB", "ABCBCD"),
    ]

    testable_functions = [best_cow_line]

    def test_one_away(self):

        for f in self.testable_functions:
            start = time.perf_counter()
            for [text, expected] in self.test_cases:
                assert f(text) == expected
            duration = time.perf_counter() - start
            print(f"{f.__name__} {duration * 1000:.1f}ms")


if __name__ == "__main__":
    unittest.main()