#include <cstdio>
#include <cstring>
#include <sstream>
#include <string>
#include <vector>

char buf[1024];
int winning[1000];

int main()
{
    int res = 0;
    int c = 0;
    int cnt = 0;
    while(scanf("Card %d: %[^\n]\n", &c, buf) == 2) {
        std::string s = buf; 
        auto a = s.find('|');
        std::stringstream ss1(s.substr(0,a));
        int v;
        std::vector<int> w;
        std::vector<int> p;
        while(ss1 >> v) {
            w.push_back(v);
        }
        std::stringstream ss2(s.substr(a + 1,s.size()));
        while(ss2 >> v) {
            p.push_back(v);
        }
        int po = 0;
        for (auto s: p) {
            for (auto k: w) {
                if (s == k) {
                    po++;
                }
            }
        }
        winning[cnt]++;
        for (int i = 1; i <= po; i++) {
            winning[cnt+i]+=winning[cnt];
        }
        cnt++;
    }
    for (int i = 0; i < cnt; i++) {
        res+=winning[i];
    }
    printf("%d\n", res);
}
