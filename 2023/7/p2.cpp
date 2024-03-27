#include <cstdio>
#include <functional>
#include <iostream>
#include <vector>
#include <array>
#include <numeric>
#include <algorithm>

int ctoid(char c)
{
    int id = 0;
    switch (c) {
        case 'T':
            id = 8;
            break;
        case 'J':
            id = -1;
            break;
        case 'Q':
            id = 10;
            break;
        case 'K':
            id = 11;
            break;
        case 'A':
            id = 12;
            break;
        default:
            id = c - '2';
    }
    return id;
}

struct B
{
    char hand[6];
    int bid;
    std::array<int, 13> cnt;
    std::array<int, 13> ids;
    bool operator < (const B & other)
    {
        // this < other
        int i = 0;
        while (cnt[ids[i]] == other.cnt[other.ids[i]] && cnt[ids[i]] != 0 && other.cnt[other.ids[i]] !=0) {i++;}
        if (cnt[ids[i]] < other.cnt[other.ids[i]]) {
            return true;
        } else if (cnt[ids[i]] == other.cnt[other.ids[i]]) {
            int j = 0;
            while(ctoid(hand[j]) == ctoid(other.hand[j])) {j++;}
            return ctoid(hand[j]) < ctoid(other.hand[j]);
        } else {
            return false;
        }
    }
};

int main()
{
    std::vector<B> bids;
    B tmp;
    tmp.cnt.fill(0);
    std::iota(tmp.ids.begin(), tmp.ids.end(), 0);
    while(scanf("%s %d\n", tmp.hand, &tmp.bid) == 2) {
        bids.push_back(tmp);
    }
    for (auto & b: bids) {
        int js = 0;
        int maxid = 0;
        int max = 0;
        for (int i = 0; i < 5; i++) {
            int id = ctoid(b.hand[i]);
            if (id > -1) {
                b.cnt[id]++;
                if (b.cnt[id] > max) {
                    max = b.cnt[id];
                    maxid = id;
                }
            } else {
                js++;
            }
        }
        b.cnt[maxid] += js;
    }
    for (auto & bid: bids) {
        std::stable_sort(bid.ids.begin(), bid.ids.end(), [&bid](int a, int b){
            return bid.cnt[a] > bid.cnt[b];
        });
    }
    std::sort(bids.begin(), bids.end());
    uint64_t res = 0;
    for (int i = 0; i < bids.size(); i++) {
        res += bids[i].bid * (i+1);
        std::cout << bids[i].hand << std::endl;
    }
    std::cout << res << std::endl;
}
