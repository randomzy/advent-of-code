#include <cassert>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>
#include <algorithm>

using u64 = uint64_t;

struct M{
    u64 f,t,c;
};

struct R{
    // [s,e]
    u64 s,e;
    bool contains(u64 p) const
    {
        return s <= p && p <= e;
    }
};

struct P{
    u64 value;
    int bracket; // 0 left, 1 right
};

char buf[1024];

u64 at(u64 v, std::vector<M> f) {
    for (const auto & m: f) {
        if (m.f <= v && v < m.f + m.c) {
            return v - m.f + m.t;
        }
    }
    return v;
}

std::vector<R> rangeToRanges(const R & range, std::vector<M> f)
{
    int bracketType = 0; // 0 opening, 1 closing
    std::vector<P> p;
    std::vector<R> res;
    p.push_back({range.s, 0});
    for (const auto & m: f) {
        u64 start = m.f;
        u64 end = m.f + m.c - 1;
        if (range.contains(start) && start != range.s){
            p.push_back({start, 0});
        }
        if (range.contains(end) && end != range.e) {
            p.push_back({end, 1});
        }
    }
    p.push_back({range.e, 1});
    // TODO: this can be inlined in upper loop to save allocs/deallocs of vectors
    std::vector<u64> intervals;
    intervals.push_back(p[0].value);
    for (int i = 1; i < p.size(); i++) {
        // [  [ -> [  ][
        if (p[i-1].bracket == 0 && p[i].bracket == 0) {
            intervals.push_back(p[i].value-1);
            intervals.push_back(p[i].value);
        }
        // [  ] -> do nothing
        if (p[i-1].bracket == 0 && p[i].bracket == 1) {
            intervals.push_back(p[i].value);
        }
        // ]  [ -> ][ ][
        if (p[i-1].bracket == 1 && p[i].bracket == 0) {
            if(p[i].value - p[i-1].value > 1) {
                intervals.push_back(p[i-1].value+1);
                intervals.push_back(p[i].value-1);
                intervals.push_back(p[i].value);
            } else {
                intervals.push_back(p[i].value);
            }
        }
        // ]  ] -> ][  ]
        if (p[i-1].bracket == 1 && p[i].bracket == 1) {
            intervals.push_back(p[i-1].value+1);
            intervals.push_back(p[i].value);
        }
    }
    // sanity check
    assert(intervals.size()%2==0);
    for (int i = 0; i < intervals.size()-1; i+=2) {
        assert(intervals[i] <= intervals[i+1]);
        u64 fl = at(intervals[i], f);
        u64 fr = at(intervals[i+1], f);
        res.push_back(R{fl, fr});
        assert(res.back().s <= res.back().e);
    }
    return res;
}

std::vector<R> rangesToRanges(std::vector<R> ranges, std::vector<M> f)
{
    std::vector<R> res;
    for (const auto & r: ranges) {
        const auto ra = rangeToRanges(r, f);
        res.insert(res.end(), ra.begin(), ra.end());
    }
    return res;
}

int main()
{
    scanf("seeds: %[^\n]\n", buf);
    std::stringstream ss(buf);
    u64 v1, v2;
    std::vector<R> s;
    while(ss >> v1 >> v2) { s.push_back({v1, v1 + v2 - 1}); }
    scanf("\n");
    u64 f,t,c;
    std::vector<std::vector<M>> m;
    int i = 0;
    while(scanf("%s\n", buf) == 1) {
        m.push_back(std::vector<M>());
        while(scanf("%lu %lu %lu\n", &t, &f, &c) == 3) {
            m[i].push_back({f,t,c});
        }
        i++;
    }
    for (int i = 0; i < m.size(); i++) {
        if(m[i].empty()) continue;
        std::sort(std::begin(m[i]), std::end(m[i]), [](const M & a, const M & b){
            return a.f < b.f;
        });
        s = rangesToRanges(s, m[i]);
    }
    std::cout << std::min_element(s.begin(), s.end(), [](R a, R b){return a.s < b.s;})->s << std::endl;
}
