#include <cstddef>
#include <cstdio>
#include <cstring>

char buf[2*1024];

int main()
{
    int gid = 0;
    int res = 0;
    while(scanf("Game %d: %[^\n]\n", &gid, buf) == 2) {
        char * g = strtok(buf, ",;");
        int cnt = 0;
        res+=gid;
        while (g != NULL) {
            char c[20];
            int d;
            sscanf(g, " %d %s", &d, c);
            if (strcmp(c, "red") == 0 && d > 12) {
                res-=gid;
                break;
            }
            if (strcmp(c, "green") == 0 && d > 13) {
                res-=gid;
                break;
            }
            if (strcmp(c, "blue") == 0 && d > 14) {
                res-=gid;
                break;
            }
            g = strtok(NULL, ",;");
        }
        memset(buf, 0, 2*1024);
    }
    printf("%d\n", res);
}
