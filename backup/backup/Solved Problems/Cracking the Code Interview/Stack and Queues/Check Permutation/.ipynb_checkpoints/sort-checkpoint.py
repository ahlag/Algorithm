## Sort Time complexity: O( n logn ) Space complexity: O(n)
def is_permutation(string1, string2):
    return sorted(list(string1)) == sorted(list(string2))

test_cases = (
    ("dog", "god", True),
    ("abcd", "bacd", True),
    ("3563476", "7334566", True),
    ("wef34f", "wffe34", True),
    ("dogx", "godz", False),
    ("abcd", "d2cba", False),
    ("2354", "1234", False),
    ("dcw4f", "dcw5f", False),
    ("DOG", "dog", False),
    ("dog ", "dog", False),
    ("aaab", "bbba", False),
)

for string1, string2, matching in test_cases:
    if is_permutation(string1, string2) == matching:
        print('Test passed')
    else:
        print('Test failed')