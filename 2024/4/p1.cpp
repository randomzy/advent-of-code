#include <iostream>
#include <string>
#include <vector>

using mat = std::vector<std::string>;

int hp(const mat & m)
{
    int res = 0;
    for (int r = 0; r < m.size(); r++)
    {
        for (int c = 0; c < m[0].size() - 3; c++)
        {
            if (m[r][c] == 'X' && m[r][c+1] == 'M' && m[r][c+2] == 'A' && m[r][c+3] == 'S')
            {
                res++;
            } 
        }    
    }
    return res;
}

int hpb(const mat & m)
{
    int res = 0;
    for (int r = 0; r < m.size(); r++)
    {
        for (int c = m[0].size() - 1; c >= 3; c--)
        {
            if (m[r][c] == 'X' && m[r][c-1] == 'M' && m[r][c-2] == 'A' && m[r][c-3] == 'S')
            {
                res++;
            } 
        }    
    }
    return res;
}

int vp(const mat & m)
{
    int res = 0;
    for (int r = 0; r < m.size() - 3; r++)
    {
        for (int c = 0; c < m[0].size(); c++)
        {
            if (m[r][c] == 'X' && m[r+1][c] == 'M' && m[r+2][c] == 'A' && m[r+3][c] == 'S')
            {
                res++;
            } 
        }    
    }
    return res;
}

int vpb(const mat & m)
{
    int res = 0;
    for (int r = m.size() - 1; r >= 3; r--)
    {
        for (int c = 0; c < m[0].size(); c++)
        {
            if (m[r][c] == 'X' && m[r-1][c] == 'M' && m[r-2][c] == 'A' && m[r-3][c] == 'S')
            {
                res++;
            } 
        }    
    }
    return res;
}

int dp1(const mat & m)
{
    int res = 0;
    for (int r = 0; r < m.size() - 3; r++)
    {
        for (int c = 0; c < m[0].size() - 3; c++)
        {
            if (m[r][c] == 'X' && m[r+1][c+1] == 'M' && m[r+2][c+2] == 'A' && m[r+3][c+3] == 'S')
            {
                res++;
            } 
        }    
    }
    return res;
}

int dp2(const mat & m)
{
    int res = 0;
    for (int r = m.size() - 1; r >= 3; r--)
    {
        for (int c = m[0].size() - 1; c >= 3 ; c--)
        {
            if (m[r][c] == 'X' && m[r-1][c-1] == 'M' && m[r-2][c-2] == 'A' && m[r-3][c-3] == 'S')
            {
                res++;
            } 
        }    
    }
    return res;
}

int dp3(const mat & m)
{
    int res = 0;
    for (int r = 0; r < m.size() - 3; r++)
    {
        for (int c = m[0].size() - 1; c >= 3 ; c--)
        {
            if (m[r][c] == 'X' && m[r+1][c-1] == 'M' && m[r+2][c-2] == 'A' && m[r+3][c-3] == 'S')
            {
                res++;
            } 
        }    
    }
    return res;
}

int dp4(const mat & m)
{
    int res = 0;
    for (int r = m.size() - 1; r >= 3; r--)
    {
        for (int c = 0; c < m[0].size() - 3; c++)
        {
            if (m[r][c] == 'X' && m[r-1][c+1] == 'M' && m[r-2][c+2] == 'A' && m[r-3][c+3] == 'S')
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
    std::cout << hp(m) + hpb(m) + vp(m) + vpb(m) + dp1(m) + dp2(m) + dp3(m) + dp4(m) << std::endl;
}

