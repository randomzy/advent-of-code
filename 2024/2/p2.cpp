#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int solve(std::vector<int> const & v)
{
    const int s = (v[0] - v[1]) > 0;
    for (int i = 0; i < v.size() - 1; i++)
    {
        const int d = v[i] - v[i+1];
        const int ad = std::abs(d);
        const int sd = d > 0;
        if (!(ad >= 1 && ad <= 3 && sd == s)) {
            return 0;
        }
    }
    return 1;
}

int main()
{
    std::string l;
    int res = 0;
    while(std::getline(std::cin, l))
    {
        std::stringstream ss(l);
        int a;
        std::vector<int> v;
        while(ss >> a)
        {
           v.push_back(a); 
        }
        for (int i = 0; i < v.size(); i++) {
            auto v2 = v;
            v2.erase(v2.begin() + i);
            int r = solve(v2);
            res += r;
            if (r == 1)
                break;            
        }
    }
    std::cout << res << std::endl;
}
