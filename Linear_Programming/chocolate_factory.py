# Solving a Linear programming problem in Python with Scipy kit

# Problem statement: profit maximization in chocolate factory

# A chocolate shop sells three products: x1 at a profit of $1 each,
# # x2 at 6$ a piece. Daily demand are 200 and 300 for x1
# and x2 respectively. Max production capability is 400 choc per day.
# find optimum number of chocolates to be sold for max profit.

# Equations to solve
# minimize (x1+6x2)
# x1 <= 200
# x2 <= 300
# x1 + x2 <= 400
# x1, x2 >= 0

from scipy.optimize import linprog
import numpy as np

if __name__ == "__main__":
    c = [-1, -6]
    A = [[1, 0], [0, 1], [1, 1]]
    b = [200, 300, 400]
    x1_bounds = (0, np.inf)
    x2_bounds = (0, np.inf)

    res = linprog(c, A_ub=A, b_ub=b, bounds=[x1_bounds, x2_bounds], method="simplex")
    print(res)
    print("Profit: ", (-1)*(c[0]*res.x[0] + c[1]*res.x[1]))

    print('\n\nExiting Program! \n')

# Scipy: Not useful for integer LP, constraints should be defined as <=, and solves only minimization problems.


