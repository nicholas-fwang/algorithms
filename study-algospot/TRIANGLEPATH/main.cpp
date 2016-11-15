#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int map[101][101];
int cache[101][101];
int N;
int solve(int row, int col);
int main()
{
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        memset(cache, -1, sizeof(cache));
        scanf("%d", &N);
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=i; j++) {
                scanf("%d", &map[i][j]);
            }
        }
        printf("%d\n", solve(1,1));
    }
    return 0;
}

int solve(int row, int col) {
    if(row == N+1) return 0;
    
    int& ret = cache[row][col];
    if(ret != -1) return ret;
    ret = 0;
    
    ret = max(ret, solve(row+1, col)+map[row][col]);
    ret = max(ret, solve(row+1, col+1)+map[row][col]);
    return ret;
}