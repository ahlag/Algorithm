# O(N)
import time
import unittest


def are_one_edit_different(s1, s2):
    
    n, m = len(s1), len(s2)
    
    if abs(n - m) > 1:
        return False
    
    if n > m:
        s1, s2 = s2, s1
        n, m = m, n
        
    i, j = 0, 0
    
    found_difference = False

    while i < n and j < m:
        
        if s1[i] != s2[j]:
            
            if found_difference is True:
                return False
            found_difference = True
            
            if n == m:
                i += 1

        else:
            i += 1
        j += 1
        
    return True


class Test(unittest.TestCase):
    test_cases = [
        # no changes
        ("pale", "pale", True),
        ("", "", True),
        # # one insert
        ("pale", "ple", True),
        ("ple", "pale", True),
        ("pales", "pale", True),
        ("ples", "pales", True),
        ("pale", "pkle", True),
        ("paleabc", "pleabc", True),
        ("", "d", True),
        ("d", "de", True),
        # # one replace
        ("pale", "bale", True),
        ("a", "b", True),
        ("pale", "ble", False),
        # multiple replace
        ("pale", "bake", False),
        # insert and replace
        ("pale", "pse", False),
        ("pale", "pas", False),
        ("pas", "pale", False),
        ("pkle", "pable", False),
        ("pal", "palks", False),
        ("palks", "pal", False),
        # # permutation with insert shouldn't match
        ("ale", "elas", False),
    ]

    testable_functions = [are_one_edit_different]

    def test_one_away(self):

        for f in self.testable_functions:
            start = time.perf_counter()
            for _ in range(100):
                for [text_a, text_b, expected] in self.test_cases:
                    assert f(text_a, text_b) == expected
            duration = time.perf_counter() - start
            print(f"{f.__name__} {duration * 1000:.1f}ms")


if __name__ == "__main__":
    unittest.main()