#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int oo = 0x3f3f3f3f;
const int d[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int n,m;
int cache[502][502];
int map[502][502];

int solve(int row, int col);

int main()
{   
    memset(cache, -1, sizeof(cache));
    memset(map, oo, sizeof(map));
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    printf("%d\n", solve(n,m));
    return 0;
}

int solve(int row, int col)
{
    if(row == 1 && col == 1) {
        return 1;
    }
    if(row > n || row < 1 || col > m || col < 1) {
        return 0;
    }
    
    int& ret = cache[row][col];
    if(ret != -1) return ret;
    ret = 0;
    for(int i=0; i<4; i++) {
        int dx = d[i][0];
        int dy = d[i][1];
        if(map[row+dy][col+dx] > map[row][col]) {
            ret += solve(row+dy, col+dx);
        }
    }
    return ret;
}