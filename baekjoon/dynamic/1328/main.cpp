#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int MOD = 1000000007;

int N,L,R;
long long solve(int n, int l, int r);
long long cache[101][101][101];
int main()
{
    scanf("%d %d %d", &N, &L, &R);
    memset(cache, -1, sizeof(cache));
    printf("%lld\n", solve(N-1,1,1));
    return 0;
}

long long solve(int n, int l, int r)
{
    if(n == 0) {
        if(l == L && r == R) return 1;
        return 0;
    }
    
    long long& ret = cache[n][l][r];
    if(ret != -1) return ret;
    ret = 0;
    
    ret = solve(n-1, l+1, r)%MOD;
    ret += solve(n-1, l, r+1)%MOD;
    ret += (N-1-n)*solve(n-1, l, r)%MOD;
    return ret%MOD;
}