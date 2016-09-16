#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int map[10001];
int cache[10001][4];

int solve(int n, int prev);
int main()
{
    int n;
    scanf("%d", &n);
    memset(cache, -1, sizeof(cache));
    for(int i=1; i<=n; i++) {
        int tmp;
        scanf("%d", &tmp);
        map[i] = tmp;
    }
    int ret = solve(n, 0x0);
    printf("%d\n", ret);
    return 0;
}

int solve(int n, int prev)
{
    if(n == 0) {
        return 0;
    }
    int& ret = cache[n][prev];
    if(ret != -1) {
        return ret;
    }
    ret = 0;
    if(prev == 0x3) {
        ret = solve(n-1, ((prev << 1)&0x3));
    } else {
        ret = max(solve(n-1, ((prev << 1)&0x3)+0x1) + map[n],
                 solve(n-1, ((prev << 1)&0x3)));
    }
    return ret;
}