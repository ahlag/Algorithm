from collections import defaultdict
tests = ['aaa', 'abc', 'a']

def is_unique(string):
    
    hash_table = defaultdict(str)
    
    for char in string:
        if char not in hash_table:
            hash_table[char] = 1
        else:
            hash_table[char] += 1
            
    for k, v in hash_table.items():
        if v != 1:
            return False
        
    return True

for test in tests:
    print(is_unique(test))
    
    
