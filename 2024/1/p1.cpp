#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

int main()
{
    int a,b;
    std::vector<int> va, vb;
    while(scanf("%d %d", &a, &b) == 2) {
        va.push_back(a);
        vb.push_back(b);
    }
    std::sort(std::begin(va), std::end(va));
    std::sort(std::begin(vb), std::end(vb)); 
    int res = 0;
    for (int i = 0; i < va.size(); ++i) {
       res += std::abs(va[i] - vb[i]); 
    }
    std::cout << res << std::endl;
}
