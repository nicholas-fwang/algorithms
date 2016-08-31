#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int oo = 0x3f3f3f3f;

int map[501][501];
int cache[501][501];
int n;

int solve(int line, int col);
int main()
{
    scanf("%d", &n);
    memset(cache, -1, sizeof(cache));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            int tmp;
            scanf("%d", &tmp);
            map[i][j] = tmp;
        }
    }
    int ret = solve(1, 1);
    printf("%d\n", ret);
    return 0;
}

int solve(int line, int col)
{
    if(line == n+1) {
        return 0;
    }
    
    int& ret = cache[line][col];
    if(ret != -1) return ret;
    ret = map[line][col];
    return ret += max(solve(line+1, col), solve(line+1, col+1));
}