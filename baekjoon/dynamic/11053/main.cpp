#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int map[1001];
int cache[1001][1001];
int N;

int solve(int n, int prev);
int main()
{
    scanf("%d", &N);
    memset(cache, -1, sizeof(cache));
    map[0] = 0;
    for(int i=1; i<=N; i++) {
        scanf("%d", &map[i]);
    }
    int ret = solve(1, 0);
    printf("%d\n", ret);
    return 0;
}

int solve(int n, int prev)
{
    if(n > N) {
        return 0;
    }
    
    int& ret = cache[n][prev];
    if(ret != -1) return ret;
    ret = 0;
    if(map[n] <= map[prev]) ret = solve(n+1, prev);
    else ret = max(solve(n+1, prev), solve(n+1, n)+1);
    return ret;
}