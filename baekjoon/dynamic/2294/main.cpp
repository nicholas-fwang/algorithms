#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int oo = 0x3f3f3f3f;

int cache[10001];
int map[10001];
int N, K;
int solve(int k);
int main()
{
    scanf("%d %d", &N, &K);
    for(int i=0; i<N; i++) {
        scanf("%d", &map[i]);
    }
    memset(cache, -1, sizeof(cache));
    int ret = solve(K);
    if(ret == oo) ret = -1;
    printf("%d\n", ret);
    return 0;
}

int solve(int k)
{
    if(k == 0) return 0;
    if(k < 0) return oo;
    
    int& ret = cache[k];
    if(ret != -1) return ret;
    ret = oo;
    for(int i=0; i<N; i++) {
        ret = min(ret, solve(k-map[i])+1);
    }
    return ret;
}