#include <iostream>
#include <string>
#include <vector>

using mat = std::vector<std::string>;

int hp(const mat & m)
{
    int res = 0;
    for (int r = 0; r < m.size() - 2; r++)
    {
        for (int c = 0; c < m[0].size() - 2; c++)
        {
            if (
                (m[r][c] == 'M' && m[r+1][c+1] == 'A' && m[r+2][c+2] == 'S' && m[r][c+2] == 'M' && m[r+1][c+1] == 'A' && m[r+2][c] == 'S') || // MAS MAS
                (m[r][c] == 'M' && m[r+1][c+1] == 'A' && m[r+2][c+2] == 'S' && m[r][c+2] == 'S' && m[r+1][c+1] == 'A' && m[r+2][c] == 'M') || // MAS SAM
                (m[r][c] == 'S' && m[r+1][c+1] == 'A' && m[r+2][c+2] == 'M' && m[r][c+2] == 'M' && m[r+1][c+1] == 'A' && m[r+2][c] == 'S') || // SAM MAS
                (m[r][c] == 'S' && m[r+1][c+1] == 'A' && m[r+2][c+2] == 'M' && m[r][c+2] == 'S' && m[r+1][c+1] == 'A' && m[r+2][c] == 'M')    // SAM SAM
                )
            {
                res++;
            } 
        }    
    }
    return res;
}

int main()
{
    mat m;
    std::string l;
    while(std::getline(std::cin, l))
    {
       m.push_back(l); 
    }
    std::cout << hp(m) << std::endl;
}

