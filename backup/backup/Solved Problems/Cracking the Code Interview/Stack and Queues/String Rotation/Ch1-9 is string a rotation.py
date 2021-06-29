# O(N)
import unittest

def string_rotation(s1, s2):
    if len(s1) == len(s2) != 0:
        return is_substring(s1*2, s2)
    return False

def is_substring(s1, s2):
    
    len1 = len(s1)
    len2 = len(s2)
    
    for i in range(len1 - len2 + 1):
        if s1[i:i+len2] == s2:
            return True
    return False

class Test(unittest.TestCase):

    test_cases = [
        ("waterbottle", "erbottlewat", True),
        ("foo", "bar", False),
        ("foo", "foofoo", False),
    ]

    def test_string_rotation(self):
        for [s1, s2, expected] in self.test_cases:
            actual = string_rotation(s1, s2)
            assert actual == expected

if __name__ == "__main__":
    unittest.main()
