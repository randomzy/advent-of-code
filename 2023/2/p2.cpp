#include <cstddef>
#include <cstdio>
#include <cstring>
#include <algorithm>

char buf[2*1024];

int main()
{
    int gid = 0;
    int res = 0;
    while(scanf("Game %d: %[^\n]\n", &gid, buf) == 2) {
        char * g = strtok(buf, ",;");
        int mr = 0;
        int mg = 0;
        int mb = 0;
        while (g != NULL) {
            char c[20];
            int d;
            sscanf(g, " %d %s", &d, c);
            if (strcmp(c, "red") == 0) {
                mr = std::max(mr, d);
            }
            if (strcmp(c, "green") == 0) {
                mg = std::max(mg, d);
            }
            if (strcmp(c, "blue") == 0) {
                mb = std::max(mb, d);
            }
            g = strtok(NULL, ",;");
        }
        res += mr * mg * mb;
        memset(buf, 0, 2*1024);
    }
    printf("%d\n", res);
}
