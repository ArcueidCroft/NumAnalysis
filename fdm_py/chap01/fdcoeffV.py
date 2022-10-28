import numpy as np
import math
def fdcoeffV(k, xbar, x):
    n = len(x)
    if k >= n:
        print("! length of x must be larger than k")
    A = np.ones((n, n))
    xrow = x-xbar
    for i in range(1, n):
        A[i, :] = (xrow**i)/math.factorial(i)
    b = np.zeros(n)
    b[k] = 1
    c = np.linalg.solve(A, b)
    return c


###test
# xbar_t = 2
# x_t = np.array([1,2.1,2.9])
# k = 1
# print(fdcoeffV(2, xbar_t, x_t))