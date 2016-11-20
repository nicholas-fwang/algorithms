#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int oo = 0x3f3f3f3f;

int map[100];
int cache[101][51][2];
int N,M;
int solve(int n, int m, int selected);
int main()
{
    memset(cache, -1, sizeof(cache));
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++) {
        scanf("%d", &map[i]);
    }
    printf("%d\n", max(solve(1,0,0),solve(1,1,1)+map[0]));
    return 0;
}
           
int solve(int n, int m, int selected)
{
    if(n == N) {
        if(m == M) return 0;
        else return -oo;
    }
    if(m > M) return -oo;
    
    int& ret = cache[n][m][selected];
    if(ret != -1) return ret;
    ret = -oo;
    
    if(selected == 0) {
        ret = max(ret, solve(n+1, m+1, 1)+map[n]);
        ret = max(ret, solve(n+1, m, 0));
    } else {
        ret = max(ret, solve(n+1, m, 1)+map[n]);
        ret = max(ret, solve(n+1, m, 0));
    }
    
    return ret;
}