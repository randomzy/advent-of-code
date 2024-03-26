#include <cstdint>
#include <cstdio>
#include <sstream>
#include <vector>
#include <algorithm>

char buf[1024];

struct M{
    unsigned long long f,t,c;
};

int main()
{
    unsigned long long res = UINT64_MAX;
    scanf("seeds: %[^\n]\n", buf);
    std::stringstream ss(buf);
    unsigned long long v;
    std::vector<unsigned long long> s;
    while(ss >> v) { s.push_back(v); }
    scanf("\n");
    unsigned long long f,t,c;
    std::vector<std::vector<M>> m;
    int i = 0;
    while(scanf("%s\n", buf) == 1) {
        m.push_back(std::vector<M>());
        while(scanf("%llu %llu %llu\n", &f, &t, &c) == 3) {
            m[i].push_back({f,t,c});
        }
        i++;
    }
    for (auto se: s) {
        unsigned long long st = se;
        for (const auto & ma: m) {
            if(ma.empty()) continue;
            for (const auto & f: ma) {
                if (f.t <= st && st <= f.t + f.c) {
                    st = (st - f.t) + f.f;
                    break;
                }
            }
        }
        res = std::min(st, res);
    }
    printf("%llu\n", res);
}
