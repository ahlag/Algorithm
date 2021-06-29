## Check how many times a character appears Time complexity: O( 3n ) Space complexity: O(1)
def is_permutation(string1, string2):
    
    ascii_set = [0] * 128
    
    for i in range(len(string1)):
        value = ord(string1[i]) - ord('a')
        ascii_set[value] += 1

    for j in range(len(string2)):
        value = ord(string2[j]) - ord('a')
        ascii_set[value] -= 1
        if ascii_set[value] < 0:
            return False
        
    if sum(ascii_set) > 0:
        return False
    
    return True

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