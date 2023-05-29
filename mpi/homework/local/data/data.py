import numpy as np

low = 1000
high = 1200000000
# high = 1200000
n = 12

pointers = np.geomspace(low, high, num=n, dtype=int)

for i in pointers:
    print(i, end=" ")

print()
