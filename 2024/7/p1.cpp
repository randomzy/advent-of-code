#include <cstdint>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using u64 = uint64_t;

bool check_sum(u64 sum, const std::vector<u64> & v, const std::vector<int> & ops)
{
    u64 res = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        if (ops[i-1] == 0)
            res = res + v[i]; 
        if (ops[i-1] == 1)
            res = res * v[i];
    } 
    return res == sum;
}

bool check(u64 sum, const std::vector<u64> & v, std::vector<int> ops)
{
    bool res = false;
    if (ops.size() == v.size()-1)
    {
        return check_sum(sum, v, ops);
    }
    ops.push_back(0);
    res |= check(sum, v, ops);

    ops.pop_back();
    ops.push_back(1);
    res |= check(sum, v, ops);

    return res;
}

int main()
{
    std::string s;
    u64 res = 0;
    std::vector<int> hv;
    while(std::getline(std::cin, s))
    {
        auto d = s.find(':');
        u64 sum = std::stoull(s.substr(0,d));
        std::stringstream ss(s.substr(d+1));
        int a;
        std::vector<u64> v;
        while(ss >> a) {
            v.push_back(a);
        }
        if (check(sum, v, hv))
            res += sum; 
    }
    std::cout << res << std::endl;
}
