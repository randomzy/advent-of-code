#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

#define DIM 2048
char buf[DIM][DIM];

int nei[8][2] = {
    {-1, 0},
    {-1, 1},
    { 0, 1},
    { 1, 1},
    { 1, 0},
    { 1,-1},
    { 0,-1},
    {-1,-1}
};

std::vector<int> st[DIM][DIM];

int main()
{
    unsigned long long res = 0;

    int rows = 0;
    while(scanf("%s\n", buf[rows]) == 1) { rows++; };
    int cols = DIM-1;
    while(buf[0][cols] == 0) { cols--; }; cols++;

    for (int r = 0; r < rows; r++) {
        int s = 0;
        int inc = 0;
        int sr = 0;
        int sc = 0;
        for (int c = 0; c < cols; c++) {
            if ('0' <= buf[r][c] && buf[r][c] <= '9') {
                for (int n = 0; n < 8; n++) {
                    int nr = nei[n][0] + r;
                    int nc = nei[n][1] + c;
                    if(0 <= nr && nr < rows && 0 <= nc && nc < cols) {
                        if(buf[nr][nc] == '*') {
                           inc = 1; 
                           sr = nr;
                           sc = nc;
                        }
                    } 
                }
                s++;
            } else {
                if (inc) {
                    char num[20];
                    memcpy(num, &buf[r][c-s], s); 
                    num[s] = 0;
                    st[sr][sc].push_back(atoi(num));
                }
                inc = 0;
                s = 0;
            }
        }
        if (inc) {
            char num[20];
            memcpy(num, &buf[r][cols-s], s); 
            num[s] = 0;
            st[sr][sc].push_back(atoi(num));
        }
    }
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (st[r][c].size() == 2) {
                res += st[r][c][0] * st[r][c][1];
            }
        }
    }
    printf("%llu\n", res);
}
