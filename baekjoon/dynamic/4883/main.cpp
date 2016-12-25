#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
const int oo = 0x3f3f3f3f;

int cache[100001][3];
int N;
int map[100000][3];
int solve(int row, int col);
int main()
{
    int tc=0;
    while(1) {
        scanf("%d", &N);
        if(N == 0) break;
        memset(cache, -1, sizeof(cache));
        for(int i=0; i<N; i++) {
            for(int j=0; j<3; j++) {
                scanf("%d", &map[i][j]);
            }
        }
        printf("%d. %d\n", ++tc, solve(0,1));
    }
    return 0;
}

int solve(int row, int col)
{
    if(row == N-1) {
        if(col == 0) return map[row][col]+map[row][col+1];
        else if(col == 1) return map[row][col];
        else return oo;
    }
    
    int& ret = cache[row][col];
    if(ret != -1) return ret;
    ret = oo;
    
    if(row+1 < N) {
        ret = min(ret, solve(row+1, col)+map[row][col]);
    }
    if(row+1 < N && col+1 < 3) {
        ret = min(ret ,solve(row+1, col+1)+map[row][col]);
    }
    if(row+1 < N && col-1 > -1) {
        ret = min(ret ,solve(row+1, col-1)+map[row][col]);
    }
    
    if(col+1 < 3) {
        ret = min(ret, solve(row, col+1)+map[row][col]);
    } 
    
    return ret;
}