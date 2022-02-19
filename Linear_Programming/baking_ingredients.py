# Solving a Linear programming problem in Python: Scipy kit

# Problem statement: find optimal ingredient for baking cake

# I need to bake a cake with four ingredients: flour, eggs, butter and sugar. However, I remember only bits and parts of the recipe as stated below.
# total weight of all ingredients was exactly 700 grams
# amount of butter was half that of sugar
# weight of flour and eggs together was at most 450 grams
# weight of eggs and butter combined was at most 300 grams
# the weight of eggs plus butter was at most that of flour plus sugar

# Equations to solve
# minimize (b+s)
# f + e + b + s = 700
# b -0.5s = 0
# f + e <= 450
# e + b <= 300
# -f + e + b -s <= 0

from scipy.optimize import linprog

if __name__ == "__main__":
    # decision variables
    var_list = ['Flour', 'Eggs', 'Butter', 'Sugar']

    # inequality constraints
    A_ineq = [[1, 1, 0, 0], [0, 1, 1, 0], [-1, 1, -1, 1]]
    B_ineq = [450, 300, 0]

    # equality constraints
    A_eq = [[1, 1, 1, 1], [0, 0, 1, -0.5]]
    B_eq = [700, 0]

    # objective function
    c = [0, 0, 1, 1]

    # invoke LP solver from scipy
    print('WITHOUT BOUNDS')
    res_no_bounds = linprog(c, A_ub=A_ineq, b_ub=B_ineq,
                            A_eq=A_eq, b_eq=B_eq, method='simplex')
    print(res_no_bounds)

    # explicitly stipulated bounds to accelerate the solving process
    f_bound = [0, 300]  # limits for flour
    e_bound = [0, 200]  # limits for eggs
    b_bound = [0, 100]  # limits for butter
    s_bound = [0, 200]  # limits for sugar

    res_bounds = linprog(c, A_ub=A_ineq, b_ub=B_ineq, A_eq=A_eq, b_eq=B_eq,
                         bounds=(f_bound, e_bound, b_bound, s_bound),
                         method='simplex')
    print('\nWITH BOUNDS')
    print(res_bounds)

    print('\n\nExiting Program! \n')







