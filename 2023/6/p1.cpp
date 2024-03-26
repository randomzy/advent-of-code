#include <cmath>
#include <iostream>

using u64 = uint64_t;
int solve(u64 t, u64 d)
{
    // x(t - x) - d = 0
    // -x^2 +tx -d = 0
    double D = std::sqrt(t*t - 4*d);   
    double x1 = -(-t + D)*0.5;
    double x2 = -(-t - D)*0.5;
    return std::ceil(x2) - std::floor(x1) - 1;
}

int main()
{
    std::cout << solve(56, 546) * solve(97, 1927) * solve(78,1131) * solve(75,1139) << std::endl;
}
