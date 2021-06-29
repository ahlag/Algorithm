
def insertion_sort(nums):

    for i in range(len(nums)):

        j = i

        # we have to check all the previous items (not always all of them)
        # so in worst case we consider all the previous items (until j=0)
        while j > 0 and nums[j - 1] < nums[j]:
            # swap the items - shift operations
            # this is the main disadvantage of insertion sort O(NxN)
            nums[j-1], nums[j] = nums[j], nums[j-1]
            j = j - 1


if __name__ == '__main__':

    x = [1, -5, 10, 100, -4, 0, 3, 2, 1]
    insertion_sort(x)
    print(x)
