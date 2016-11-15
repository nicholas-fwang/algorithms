#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int oo = 0x3f3f3f3f;

int map[1001];
int cache[2][31][1001];
int W,T;
int solve(int n, int t, int w);
int main()
{
    memset(cache, -1, sizeof(cache));
    scanf("%d %d", &T, &W);
    for(int i=0; i<T; i++) {
        int tmp;
        scanf("%d", &tmp);
        map[i] = tmp-1;
    }
    printf("%d\n", max(solve(0,0,0), solve(1,0,0)));
    return 0;
}

int solve(int n, int t, int w)
{
    if(w > W) return -oo;
    if(t == T) return 0;
    
    int& ret = cache[n][w][t];
    if(ret != -1) return ret;
    ret = 0;
    int tmp = 0;
    if(map[t] == n) tmp++;
    ret = max(ret, solve(1-n,t+1,w+1)+tmp);
    ret = max(ret, solve(n,t+1,w)+tmp);
    return ret;
}