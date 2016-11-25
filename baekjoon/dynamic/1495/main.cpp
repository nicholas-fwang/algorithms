#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int oo = 0x3f3f3f3f;

int map[101];
int cache[101][1001];
int N, M;
bool inRange(int n);
int solve(int n, int c);
int main()
{ 
    int s;
    scanf("%d %d %d", &N, &s, &M);
    memset(cache, -1, sizeof(cache));
    for(int i=0; i<N; i++) {
        scanf("%d", &map[i]);
    }
    
    int ret = solve(0,s);
    if(ret < 0) printf("-1\n");
    else printf("%d\n", ret);
    return 0;
}

int solve(int n, int c)
{
    if(!inRange(c)) return -oo;
    if(n == N) return c;
    
    int& ret = cache[n][c];
    if(ret != -1) return ret;
    ret = -oo;

    ret = max(ret, solve(n+1,c+map[n]));
    ret = max(ret, solve(n+1,c-map[n]));
    return ret;
}

bool inRange(int n) {
    return n>=0 && n<=M;
}