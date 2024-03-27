from scipy.optimize import fsolve
import numpy as np, random as rr
expo = np.e
# Define the system of equations
def equations(vars):
    x, y, z = vars
    eq1 = np.sin(x) + y**2 + np.log(z) - 3
    eq2 = 3*x + 2*y - z**3
    eq3 = x*x + y*y + z**3 - 6
    return [eq1, eq2, eq3]

# Initial guesses for the solutions
initial_guesses = [
    (1, 1, 1),
    (0, -2, 1),
    (1, -2, 2),
    (0, 0, 1),
    (rr.random(),rr.random(),rr.random())
]
# initial_guesses = [[rr.random() for j in range(3)] for i in range(10)]
# initial_guesses = 3 + 2.5 * np.random.randn(5, 3)
print(initial_guesses)
# Attempt to solve the system with each initial guess
solutions = []
for guess in initial_guesses:
    solution, info, ier, mesg = fsolve(equations, guess, full_output=True)
    # Check if the solution is valid and not already in the list
    if ier == 1:  # ier=1 indicates a successful solution
        is_unique = not any(np.allclose(solution, sol) for sol in solutions)
        if is_unique:
            solutions.append(solution)

# Print the solutions
for index, sol in enumerate(solutions):
    print(f"Solution {index+1}: x = {sol[0]}, y = {sol[1]}, z = {sol[2]}")
    
def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
    q = [root, None]
    ln = []
    while q:
        n = q.pop(0)
        # if n:
        if n:
            # print (n.val)
            ln.append(n.val)
        # q.update([n.left, n.right])
            if n.left:q.append(n.left)
            if n.right:q.append(n.right)
        elif q:
            q.append(None)
            # print('.')
            # print(ln)
            ln = []