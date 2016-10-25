#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int cache[1001][1002];
int map[1001];

int solve(int n, int prev);

int main()
{
    int n;
    scanf("%d", &n);
    memset(cache, -1, sizeof(cache));
    for(int i=1; i<=n; i++) {
        scanf("%d", &map[i]);
    }
    int ret = solve(n, 1001);
    printf("%d\n", ret);
    return 0;
}

int solve(int n, int prev)
{
    if(n == 0) return 0;
    
    int& ret = cache[n][prev];
    if(ret != -1) return ret;
    ret = 0;
    
    if(map[n] < prev) {
        ret = max(ret, solve(n-1,map[n])+map[n]);
    }
    ret = max(ret, solve(n-1,prev));
    return ret;
}