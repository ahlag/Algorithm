# O(N)
import unittest
from collections import Counter


def is_palindrome_permutation(string):
    """checks if a string is a permutation of a palindrome"""
    string = string.replace(' ', '').lower()
    
    bit_vector = 0
    for chr in string:
        value = ord(chr)
        bit_vector ^= (1 << value)
        
    return bit_vector == 0 or ( (bit_vector - 1) & bit_vector == 0 )

class Test(unittest.TestCase):
    test_cases = [
        ("aba", True),
        ("aab", True),
        ("abba", True),
        ("aabb", True),
        ("a-bba", True),
        ("Tact Coa", True),
        ("jhsabckuj ahjsbckj", True),
        ("Able was I ere I saw Elba", True),
        ("So patient a nurse to nurse a patient so", False),
        ("Random Words", False),
        ("Not a Palindrome", False),
        ("no x in nixon", True),
        ("azAZ", True),
    ]
    testable_functions = [is_palindrome_permutation]

    def test_pal_perm(self):
        for f in self.testable_functions:
            for [test_string, expected] in self.test_cases:
                assert f(test_string) == expected


if __name__ == "__main__":
    unittest.main()