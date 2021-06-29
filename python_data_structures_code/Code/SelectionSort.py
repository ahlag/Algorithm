
def selection_sort(nums):

    # we make N-1 iterations
    # N-1 x O(N) = O(NxN)
    for i in range(len(nums)-1):

        # linear search and the index stores the index
        # of the min item
        index = i

        # THIS IS THE LINEAR SEARCH - O(N)
        for j in range(i, len(nums)):
            if nums[index] < nums[j]:
                index = j

        # we have to swap the min item with the left-most item
        # we do not swap the item with itself
        if index != i:
            nums[index], nums[i] = nums[i], nums[index]


if __name__ == '__main__':

    n = [45, 100, 0, 1, -5, -10, 4, 5, 6, 13]
    selection_sort(n)
    print(n)
