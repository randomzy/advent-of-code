#include <cstdint>
#include <cstdio>
#include <iostream>
#include <vector>

int h[100'000];

int main()
{
    int a,b;
    std::vector<int> va, vb;
    while(scanf("%d %d", &a, &b) == 2) {
        va.push_back(a);
        vb.push_back(b);
    }
    for (const auto & e: vb) {
        h[e]++;
    }
    uint64_t res = 0;
    for (const auto e: va) {
        res += e * h[e];
    }
    std::cout << res << std::endl;
}
