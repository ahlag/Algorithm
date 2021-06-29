import time
import unittest


def compress_string(string):
    compressed = []
    
    n = len(string)
    i, j = 0, 1
    
    while i < n:
        
        if j >= n:
            compressed.append(string[i] + str(j - i))
            break
        
        if string[i] == string[j]:
            j += 1
        else:
            compressed.append(string[i] + str(j - i))
            i = j
            j = i + 1
            
    compressed = ''.join(compressed)

    return string if len(compressed) >= len(string) else compressed


class Test(unittest.TestCase):
    test_cases = [
        ("aabcccccaaa", "a2b1c5a3"),
        ("abcdef", "abcdef"),
        ("aabb", "aabb"),
        ("aaa", "a3"),
        ("a", "a"),
        ("", ""),
    ]
    testable_functions = [
        compress_string,
    ]

    def test_string_compression(self):
        for f in self.testable_functions:
            start = time.perf_counter()
            for _ in range(1000):
                for test_string, expected in self.test_cases:
                    assert f(test_string) == expected
            duration = time.perf_counter() - start
            print(f"{f.__name__} {duration * 1000:.1f}ms")


if __name__ == "__main__":
    unittest.main()