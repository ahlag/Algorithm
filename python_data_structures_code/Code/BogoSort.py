import random

class BogoSort:

    def __init__(self, nums):
        self.nums = nums

    def sort(self):

        while not self.is_sorted():
            print('Shuffle again...')
            self.shuffle()

    # Fisher-Yates approach: we generate a new permutation in O(N)
    # it is in-place so does not need additional memory !!!
    def shuffle(self):
        for i in range(len(self.nums)-2, -1, -1):
            j = random.randint(0, i+1)
            self.nums[i], self.nums[j] = self.nums[j], self.nums[i]

    def is_sorted(self):
        for i in range(len(self.nums)-1):
            if self.nums[i] > self.nums[i+1]:
                return False

        return True


if __name__ == '__main__':

    # it has O(N!) running time
    algorithm = BogoSort([1, -4, 10, 5, 0, 1, 2, 3, 4, 5])
    algorithm.sort()
    print(algorithm.nums)
