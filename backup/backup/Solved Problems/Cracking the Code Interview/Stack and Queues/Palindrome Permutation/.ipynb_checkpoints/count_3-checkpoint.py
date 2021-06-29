## Checking counts 
## odd length string can only have 1 odd count
## even length string can not havve any odd_count
## Time complexity O(n) and Sapce Complexity O(n)
from collections import Counter
def is_palindrome_permutation(string):
    counter = Counter(string.replace(" ", "").lower())
    ## count number of odds
    return sum(val % 2 for val in counter.values()) <= 1

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

for string, matching in test_cases:
    if is_palindrome_permutation(string) == matching:
        print('Test passed')
    else:
        print('Test failed')
        