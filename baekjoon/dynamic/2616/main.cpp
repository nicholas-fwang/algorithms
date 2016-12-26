#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int oo = 0x3f3f3f3f;

int N;
int map[50000];
int psum[50001];
int cache[3][50000];
int k;
int solve(int n, int s);
int main()
{
    scanf("%d", &N);
    memset(cache, -1, sizeof(cache));
    for(int i=0; i<N; i++) scanf("%d", &map[i]);
    psum[0] = 0;
    for(int i=1; i<=N; i++) psum[i] = psum[i-1]+map[i-1];
    scanf("%d", &k);
    printf("%d\n", solve(0,0));
    return 0;
}

int solve(int n, int s)
{
    if(n == 3) return 0;
    if(s >= N) return -oo;
    
    int& ret = cache[n][s];
    if(ret != -1) return ret;
    ret = 0;
    
    ret = max(ret, solve(n, s+1));
    ret = max(ret, solve(n+1, s+k)+psum[s+k]-psum[s]);
    
    return ret;
}