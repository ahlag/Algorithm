## Checking counts 
## odd length string can only have 1 odd count
## even length string can not havve any odd_count
## Time complexity O(n) and Sapce Complexity O(n)
def is_palindrome_permutation(string):
    table = [0 for _ in range(ord("z") - ord("a") + 1)]
    countodd = 0
    for c in string:
        x = char_number(c)
        if x != -1:
            table[x] += 1
            if table[x] % 2:
                countodd += 1
            else:
                countodd -= 1
                
    return countodd <= 1
    
def char_number(c):
    a = ord("a")
    z = ord("z")
    upper_a = ord("A")
    upper_z = ord("Z")
    val = ord(c)

    if a <= val <= z:
        return val - a

    if upper_a <= val <= upper_z:
        return val - upper_a
    return -1

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
        