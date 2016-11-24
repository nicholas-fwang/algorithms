#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int MOD = 10000000;

int N;
int cache[101][101];
int solve(int n, int first);
int main()
{
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        scanf("%d", &N);
        memset(cache, -1, sizeof(cache));
        int ret = 0;
        for(int i=1; i<=N; i++) {
            ret += solve(i,i)%MOD;
            ret = ret%MOD;
        }
        printf("%d\n", ret);
    }
    return 0;
}

int solve(int n, int first)
{
    if(n == N) {
        return 1;
    }
    
    int& ret = cache[n][first];
    if(ret != -1) return ret;
    ret = 0;
    for(int i=1; i<=N-n; i++) {
        ret += (first+i-1)*solve(n+i, i)%MOD;
        ret = ret%MOD;
    }
    return ret;
}