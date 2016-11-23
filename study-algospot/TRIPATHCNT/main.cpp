#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int map[101][101];
int N;
int cache[101][101];
int c[101][101];

int solve(int row, int col);
int cnt(int row, int col);
int main()
{
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        memset(cache, -1, sizeof(cache));
        memset(c, -1, sizeof(c));
        scanf("%d", &N);
        for(int i=0; i<N; i++) {
            for(int j=0; j<=i; j++) {
                scanf("%d", &map[i][j]);
            }
        }
        printf("%d\n", cnt(0,0));
    }
    return 0;
}

int solve(int row, int col)
{
    if(row == N) {
        return 0;
    }
    
    int& ret = cache[row][col];
    if(ret != -1) return ret;
    ret = 0;
    ret = max(ret, solve(row+1,col)+map[row][col]);
    ret = max(ret, solve(row+1,col+1)+map[row][col]);
    return ret;
}

int cnt(int row, int col)
{
    if(row == N-1) return 1;
    
    int& ret = c[row][col];
    if(ret != -1) return ret;
    ret = 0;
    
    if(solve(row+1,col+1) >= solve(row+1,col)) ret += cnt(row+1,col+1);
    if(solve(row+1,col+1) <= solve(row+1,col)) ret += cnt(row+1,col);
    return ret;
}