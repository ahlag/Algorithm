## Checking counts 
## odd length string can only have 1 odd count
## even length string can not havve any odd_count
## Time complexity O(n) and Sapce Complexity O(n)
def is_palindrome_permutation(string):
    string = string.replace(' ', '').lower()
    
    is_even_length, is_odd_length = False, False
    
    if len(string) % 2 == 0:
        is_even_length = True
    else:
        is_odd_length = True
        
    ascii_set = [0] * 128
        
    for chr in string:
        value = ord(chr) - ord('a')
        ascii_set[value] += 1

    even_cnt, odd_cnt = 0, 0
    for i in range(128):

        if ascii_set[i] % 2 == 0 and ascii_set[i] != 0:
            even_cnt += 1
        elif ascii_set[i] % 2 != 0 and ascii_set[i] != 0:
            odd_cnt += 1
            
    if (is_odd_length and odd_cnt > 1) or (is_even_length and odd_cnt >= 1):
        return False
    
    return True

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
        