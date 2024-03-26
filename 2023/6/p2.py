import math

def solve(t,d):
    D = math.sqrt(t*t - 4*d)
    x1 = -(-t+D)*0.5
    x2 = -(-t-D)*0.5
    return math.ceil(x2) - math.floor(x1) - 1

print(solve(56977875, 546192711311139))
