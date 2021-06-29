# Remove the duplicate values from a linked list.

import unittest
from collections import defaultdict

class Node():
    def __init__(self, data, next):
        self.data = data
        self.next = next
        
def remove_duplicates(node):
    
    curr = node
    dupVals = set()
    
    if curr:
        dupVals.add(curr.data)
        while curr.next:
            
            if curr.next.data in dupVals:
                curr.next = curr.next.next
            else:
                dupVals.add(curr.next.data)
                curr = curr.next
    
    return curr

def remove_duplicates_v2(node):
    
    curr = node
    dupVals = set()
    prev = None

    while curr:
        
        if curr.data in dupVals:
            prev.next = curr.next
        else:
            dupVals.add(curr.data)
            prev = curr
        curr = curr.next
    
    return prev

def remove_duplicates_followup(node):
    
    curr = node
    
    while curr:
        
        runner = curr
        
        while runner.next:
            if runner.next.data == curr.data:
                runner.next = runner.next.next
            else:
                runner = runner.next
                
        curr = curr.next
        
    return curr

class Test(unittest.TestCase):
    def test_remove_duplicates(self):
        head = Node(1,Node(3,Node(3,Node(1,Node(5,None)))))
        remove_duplicates(head)
        self.assertEqual(head.data, 1)
        self.assertEqual(head.next.data, 3)
        self.assertEqual(head.next.next.data, 5)
        self.assertEqual(head.next.next.next, None)
        
    def test_remove_duplicates_v2(self):
        head = Node(1,Node(3,Node(3,Node(1,Node(5,None)))))
        remove_duplicates_v2(head)
        self.assertEqual(head.data, 1)
        self.assertEqual(head.next.data, 3)
        self.assertEqual(head.next.next.data, 5)
        self.assertEqual(head.next.next.next, None)
        
    def test_remove_duplicates_followup(self):
        head = Node(1,Node(3,Node(3,Node(1,Node(5,None)))))
        remove_duplicates_followup(head)
        self.assertEqual(head.data, 1)
        self.assertEqual(head.next.data, 3)
        self.assertEqual(head.next.next.data, 5)
        self.assertEqual(head.next.next.next, None)

if __name__ == "__main__":
    unittest.main()