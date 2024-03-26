#include <cstdio>
#include <cstring>

char buf[256];

int readSpelled(const char * const buf)
{
    if(strncmp("zero", buf, 4) == 0) return 0;
    if(strncmp("one", buf, 3) == 0) return 1;
    if(strncmp("two", buf, 3) == 0) return 2;
    if(strncmp("three", buf, 5) == 0) return 3;
    if(strncmp("four", buf, 4) == 0) return 4;
    if(strncmp("five", buf, 4) == 0) return 5;
    if(strncmp("six", buf, 3) == 0) return 6;
    if(strncmp("seven", buf, 5) == 0) return 7;
    if(strncmp("eight", buf, 5) == 0) return 8;
    if(strncmp("nine", buf, 4) == 0) return 9;
    return -1;
}

int main()
{
    long long res = 0;
    while(scanf("%s\n", buf) == 1) {
        int first = -1;
        int last = -1;
        int rev = 256;
        while(buf[--rev] == 0);
        for (int i = 0; i <= rev; i++) {
            int read = readSpelled(buf + i);
            if (read != -1) {
                if (first == -1) {
                    first = read;
                }
                last = read;
            }
            if ('0' <= buf[i] && buf[i] <= '9') {
                if (first == -1) {
                    first = buf[i] - '0';
                }
                last = buf[i] - '0';
            }
        }
        printf("%d\n", 10*first + last);
        res+=10*first + last;
        memset(buf, 0, 256);
    }
    printf("%lld\n", res);
}
