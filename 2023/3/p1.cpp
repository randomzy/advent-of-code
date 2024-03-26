#include <cstdio>
#include <cstdlib>
#include <cstring>

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

int main()
{
    long long res = 0;

    int rows = 0;
    while(scanf("%s\n", buf[rows]) == 1) { rows++; };
    int cols = DIM-1;
    while(buf[0][cols] == 0) { cols--; }; cols++;

    for (int r = 0; r < rows; r++) {
        int s = 0;
        int inc = 0;
        for (int c = 0; c < cols; c++) {
            if ('0' <= buf[r][c] && buf[r][c] <= '9') {
                for (int n = 0; n < 8; n++) {
                    int nr = nei[n][0] + r;
                    int nc = nei[n][1] + c;
                    if(0 <= nr && nr < rows && 0 <= nc && nc < cols) {
                        if(buf[nr][nc] != '.' && !('0' <= buf[nr][nc] && buf[nr][nc] <= '9')) {
                           inc = 1; 
                        }
                    } 
                }
                s++;
            } else {
                if (inc) {
                    char num[20];
                    memcpy(num, &buf[r][c-s], s); 
                    num[s] = 0;
                    res += atoi(num);
                }
                inc = 0;
                s = 0;
            }
        }
        if (inc) {
            char num[20];
            memcpy(num, &buf[r][cols-s], s); 
            num[s] = 0;
            printf("%s\n", num);
            res += atoi(num);
        }
    }
    printf("%lld\n", res);
}
