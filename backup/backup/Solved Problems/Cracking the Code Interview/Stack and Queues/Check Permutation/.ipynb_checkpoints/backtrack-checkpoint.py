## Backtrack  Time complexity: O(n!) Space complexity: O(n)
def permute(string, l, r, patterns=[]):
    if l == r:
        patterns.append(''.join(string))
    else:
        for i in range(l,r):
            string[l], string[i] = string[i], string[l]
            permute(string, l+1, r, patterns)
            string[l], string[i] = string[i], string[l]

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
    patterns = []
    permute(list(string1), 0, len(string1), patterns)
    for pattern in patterns:
        if pattern == string2:
            flg = True
            break
        else:
            flg = False
    if flg == matching:
        print('Test passed')
    else:
        print('Test failed')