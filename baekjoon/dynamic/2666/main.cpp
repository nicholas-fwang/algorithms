#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int oo = 0x3f3f3f3f;

int N;
int len;
int map[21];
int cache[21][21][21];
int solve(int n, int d1, int d2);
int main()
{
    memset(cache, -1, sizeof(cache));
    scanf("%d", &N);
    int d1,d2;
    scanf("%d %d", &d1, &d2);
    scanf("%d", &len);
    for(int i=1; i<=len; i++) {
        scanf("%d", &map[i]);
    }
    printf("%d\n", solve(1, d1, d2));
    return 0;
}

int solve(int n, int d1, int d2)
{
    if(n == len+1) return 0;
    
    int& ret = cache[n][d1][d2];
    if(ret != -1) return ret;
    
    return ret = min(solve(n+1,map[n],d2)+abs(d1-map[n]),
                    solve(n+1,d1,map[n])+abs(d2-map[n]));
}