
def find_duplicates(nums):

    # we can achieve O(N) linear running time where N=len(nums)
    for num in nums:
        if nums[abs(num)] >= 0:
            nums[abs(num)] = -nums[abs(num)]
        else:
            print('Repetition found: %s' % str(abs(num)))


if __name__ == '__main__':

    # THIS METHOD CANNOT HANDLE VALUES < 0 !!!
    # the maximum item is smaller than the size of the list
    n = [2, 6, 5, 1, 4, 3, 2]
    find_duplicates(n)
