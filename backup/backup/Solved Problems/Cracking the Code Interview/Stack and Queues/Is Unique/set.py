from collections import defaultdict
tests = ['aaa', 'abc', 'a']

def is_unique(string):
    
    return len(string) == len(set(string))

for test in tests:
    print(is_unique(test))
    
    
