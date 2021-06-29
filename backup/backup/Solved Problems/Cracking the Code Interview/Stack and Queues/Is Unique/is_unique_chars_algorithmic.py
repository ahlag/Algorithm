from collections import defaultdict
tests = ['aaa', 'abc', 'a', 'AaBB']

ascii_size = 128

def is_unique(string):
    
    if len(string) > ascii_size:
        return False
    
    bit_vector = [False] * ascii_size
    for char in string:
        val = ord(char)
        if bit_vector[val]:
            return False
        bit_vector[val] = True
        
    return True

for test in tests:
    print(is_unique(test))
    
    
