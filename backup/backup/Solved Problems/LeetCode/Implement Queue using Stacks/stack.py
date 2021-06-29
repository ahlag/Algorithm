class MyStack:
    
    def __init__(self, capacity):
        """
        Initialize stack
        """
        self.capacity = capacity
        self.stack = [None] * (self.capacity + 1)
        self.size = 0
        
    def peek(self):
        
        if self.size != 0:
            return self.stack[self.size]
    
    def getSize(self):
        return self.size

    def isEmpty(self):
        return self.getSize() == 0
    
    def pop(self):
        if self.getSize() != 0:
            self.size -= 1
            return self.stack[self.size + 1]
        else:
            print('Stack is empty.')
            return False
        
    def push(self, integer):
        if self.size < self.capacity:
            self.size += 1
            self.stack[self.size] = integer
            print(integer, ' is successfully added.')
            return True
        else:
            print('Stack is full.')
            return False

stack = MyStack(10)
print('Initial size of stack: ', stack.getSize())
print('Is the stack empty: ', stack.isEmpty())
print('Adding', 1, 'to stack')
stack.push(1)
print('Current size of stack: ',stack.getSize())
print('Is the stack empty: ', stack.isEmpty())
print('Top of stack: ', stack.peek())
print('Adding [2, 3, 4, 5, 6] to stack')
stack.push(2)
stack.push(3)
stack.push(4)
stack.push(5)
stack.push(6)
print('Current size of stack: ',stack.getSize())
print('Is the stack empty: ', stack.isEmpty())
print('Top of stack: ', stack.peek())
print('Removing 6 from the stack')
stack.pop()
print('Current size of stack: ',stack.getSize())
print('Is the stack empty: ', stack.isEmpty())
print('Top of stack: ', stack.peek())
stack.push(6)
stack.push(7)
stack.push(8)
stack.push(9)
print('Current size of stack: ',stack.getSize())
print('Is the stack empty: ', stack.isEmpty())
print('Top of stack: ', stack.peek())
print('Adding 10 to stack')
stack.push(10)
print('Current size of stack: ',stack.getSize())
print('Is the stack empty: ', stack.isEmpty())
print('Top of stack: ', stack.peek())
print('Adding 11 to stack')
stack.push(11)
print('Current size of stack: ',stack.getSize())
print('Is the stack empty: ', stack.isEmpty())
print('Top of stack: ', stack.peek())
stack.pop()
stack.pop()
stack.pop()
stack.pop()
stack.pop()
stack.pop()
stack.pop()
stack.pop()
stack.pop()
stack.pop()
print('Current size of stack: ',stack.getSize())
print('Is the stack empty: ', stack.isEmpty())
print('Top of stack: ', stack.peek())
stack.pop()