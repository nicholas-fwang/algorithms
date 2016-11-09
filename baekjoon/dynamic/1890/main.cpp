#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int board[100][100];
long long cache[100][100];
int n;
long long solve(int row, int col);
int main()
{
    memset(cache, -1, sizeof(cache));
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    printf("%lld\n", solve(0,0));
    return 0;
}

long long solve(int row, int col)
{
    if(row == n-1 && col == n-1) return 1;
    else if(row >= n && col >= n) return 0;
    
    long long& ret = cache[row][col];
    if(ret != -1) return ret;
    ret = 0;
    
    ret += solve(row+board[row][col], col);
    ret += solve(row, col+board[row][col]);
    return ret;
}