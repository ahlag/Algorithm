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
            return True
        else:
            print('Stack is full.')
            return False
        
class MyQueue:
    
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.capacity = 10
        self.primaryStack   = MyStack(self.capacity)
        self.secondaryStack = MyStack(self.capacity)

    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        if self.primaryStack.getSize() + self.secondaryStack.getSize() < self.capacity:
            self.primaryStack.push(x)
        else:
            print('Queue is full!')
            return False
            

    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        if self.empty():
            print('Queue is empty!!')
            return
        
        if not self.secondaryStack.isEmpty():
            return self.secondaryStack.pop()
        
        if not self.primaryStack.isEmpty() and self.secondaryStack.isEmpty():
            while not self.primaryStack.isEmpty():
                self.secondaryStack.push(self.primaryStack.pop())
            return self.secondaryStack.pop()
        
    def peek(self) -> int:
        """
        Get the front element.
        """
        if self.empty():
            print('Queue is empty!!')
            return
            
        if not self.secondaryStack.isEmpty():
            return self.secondaryStack.peek()
        
        if not self.primaryStack.isEmpty() and self.secondaryStack.isEmpty():
            while not self.primaryStack.isEmpty():
                self.secondaryStack.push(self.primaryStack.pop())
            return self.secondaryStack.peek()
            
        

    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        return self.primaryStack.isEmpty() and self.secondaryStack.isEmpty()
    
queue = MyQueue()
print('Is the queue empty: ', queue.empty())
print('Adding', 1, 'to queue')
queue.push(1)
print('Adding', 2, 'to queue')
queue.push(2)
print('Top of queue: ', queue.peek())
print('Adding', 3, 'to queue')
queue.push(3)
print('Adding', 4, 'to queue')
queue.push(4)
print('Top of queue: ', queue.peek())
queue.pop()
print('Remove top of queue: ', queue.peek())
queue.pop()
print('Remove top of queue: ', queue.peek())
queue.push(5)
queue.push(6)
queue.push(7)
queue.push(8)
queue.push(9)
queue.push(10)
queue.push(11)
queue.push(12)
queue.push(13)
queue.push(14)
print('Top of queue: ', queue.peek())