#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int m[100][100];

int check(std::vector<int> & v)
{
    int s = 1;
    for (int i = 0; i < v.size()-1; i++)
    {
        for (int j = i; j < v.size(); j++)
        {
            if (m[v[j]][v[i]])
            {
                std::swap(v[i], v[j]);
                s = 0;
            }
        }
    }
    return s;
}

int main() 
{
    int a,b;
    std::string l;
    while(std::getline(std::cin, l))
    {
        std::stringstream ss(l);
        std::string si;
        int v[2];
        int i = 0;
        while(std::getline(ss, si, '|'))
        {
            v[i++] = std::stoi(si);
        }
        if(si=="")
            break;
        m[v[0]][v[1]] = 1; 
    }
    int res = 0;
    while(std::getline(std::cin, l))
    {
        std::vector<int> v;
        std::stringstream ss(l);
        std::string si;
        while(std::getline(ss, si, ','))
        {
            v.push_back(std::stoi(si));
        }
        if(!check(v))
        {
            res+=v[v.size()/2];
        }
    }
    std::cout << res << std::endl;
}
