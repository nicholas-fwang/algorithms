#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int oo = 0x3f3f3f3f;

int cache[1001][1001][2];
int map[1001][1001];
int n,m;
int solve(int row, int col, int prev);
int main()
{
    memset(cache, -1, sizeof(cache));
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    printf("%d\n", max(solve(0,0,0),solve(0,0,1)));
    return 0;
}

int solve(int row, int col, int d)
{
    if(row == n-1 && col == m-1) {
        return map[row][col];
    }
    
    int& ret = cache[row][col][d];
    if(ret != -1) return ret;
    ret = -oo;
    
    if(d == 0 && col-1>=0) {
        ret = max(ret, solve(row, col-1, d)+map[row][col]);
    }
    else if(d == 1 && col+1 <m) {
        ret = max(ret, solve(row, col+1, d)+map[row][col]);
    }
    
    if(row+1<n) {
        ret = max(ret, solve(row+1, col, 0)+map[row][col]);
        ret = max(ret, solve(row+1, col, 1)+map[row][col]);
    }
    return ret;
}
