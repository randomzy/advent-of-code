#include "../../utils.h"
#include <unordered_map>
#include <vector>

int main()
{
    Matrix m = readMatrix<char>(std::cin);
    std::unordered_map<char, std::vector<Index>> a; 
    for (int r = 0; r < m.r(); r++) {
        for (int c = 0; c < m.c(); c++) {
            char ch = m.at({r,c});
            if (ch!='.')
            {
                if (a.count(ch) == 0) {
                    a.insert({ch, std::vector<Index>{}});
                }
                a.at(ch).push_back({r,c});
            }
        }
    }
    Matrix<char> b = m;
    for (const auto & e: a)
    {
        const auto & v = e.second;
        for(int i = 0; i < v.size(); i++)
        {
            for (int j = i + 1; j < v.size(); j++)
            {
                auto d = v[j] - v[i];
                auto np = v[i] + d;
                if (!(np == v[j]) && (np.col >= 0 && np.row >= 0 && np.col < m.c() && np.row < m.r())) {
                    b.at(np) = '#';
                }
                np = v[i] - d;
                if (!(np == v[j])&& (np.col >= 0 && np.row >= 0 && np.col < m.c() && np.row < m.r())) {
                    b.at(np) = '#';
                }
                np = v[j] + d;
                if (!(np == v[i])&& (np.col >= 0 && np.row >= 0 && np.col < m.c() && np.row < m.r())) {
                    b.at(np) = '#';
                }
                np = v[j] - d;
                if (!(np == v[i])&& (np.col >= 0 && np.row >= 0 && np.col < m.c() && np.row < m.r())) {
                    b.at(np) = '#';
                }
            }
        }
    }
    int res = 0;
    for (int r = 0; r < m.r(); r++) {
        for (int c = 0; c < m.c(); c++) {
            if (b.at({r,c}) == '#') {
                res++;
            }
        }
    }
    std::cout << res << std::endl;
}
