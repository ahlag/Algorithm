from collections import defaultdict
tests = ['aaa', 'abc', 'a', 'AaBB']

ascii_size = 128

def is_unique(string):

    if len(string) > ascii_size:
        return False

    checker = 0
    for char in string:
        val = ord(char)
        if (checker & (1 << val)) > 0:
            return False
        checker |= 1 << val

    return True

for test in tests:
    print(is_unique(test))
