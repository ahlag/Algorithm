import random
import QuickSort as q
import RadixSort as c
import time

n = [n for n in range(10000)]
random.shuffle(n)

sort1 = q.QuickSort(n)

t = time.time()
sort1.sort()
print('Quicksort time taken: %s' % str(time.time()-t))

random.shuffle(n)
sort2 = c.RadixSort(n)

t = time.time()
sort2.sort()
print('Radix sort time taken: %s' % str(time.time()-t))
