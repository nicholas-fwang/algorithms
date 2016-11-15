#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int cache[501][501];
int map[501];
int N;
int solve(int n, int l);
int main()
{
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        memset(cache, -1, sizeof(cache));
        scanf("%d", &N);
        for(int i=1; i<=N; i++) {
            scanf("%d", &map[i]);
        }
        printf("%d\n", solve(1,0));
    }
    return 0;
}

int solve(int n, int l)
{
    if(n == N+1) return 0;
    
    int& ret = cache[n][l];
    if(ret != -1) return ret;
    ret = 0;
    
    if(map[n] > map[l]) {
        ret = max(ret, solve(n+1, n)+1);
    }
    return ret = max(ret, solve(n+1, l));
}