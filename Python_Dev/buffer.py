# buffer code for any application that requires use of stored data


import numpy as np
import math as mt
from collections import deque

# first buffer will append to the beginning of the buffer
buf_size = raw_input("Please specify the size of the buffer:" + "\t" "\n")

# initializing the buffer
# for x in range(buf_size):
buffer = [0 for i in range(int(buf_size))]

# summary of buffer generation
print("The size of the buffer generated is:" + str(buf_size) + "\n")
print("The buffer generated:" + str(buffer))


# notes: (Array and List Management)
# arr_example = array([values in the array])
