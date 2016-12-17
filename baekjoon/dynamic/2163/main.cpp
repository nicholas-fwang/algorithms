#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int oo = 0x3f3f3f3f;

int N,M;
int cache[301][301];
int solve(int n, int m);
int main()
{
    scanf("%d %d", &N, &M);
    memset(cache, -1, sizeof(cache));
    printf("%d\n", solve(N,M));
    return 0;
}

int solve(int n, int m)
{
    if(n==1 && m==1) return 0;
    
    int& ret = cache[n][m];
    if(ret != -1) return ret;
    ret = oo;
    
    for(int i=1; i<n; i++) {
        ret = min(ret, solve(i,m)+solve(n-i,m)+1);
    }
    for(int i=1; i<m; i++) {
        ret = min(ret, solve(n,i)+solve(n,m-i)+1);
    }
    
    return ret;
}