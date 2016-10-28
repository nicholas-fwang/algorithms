#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int d[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

int board[100][100];
bool visited[100][100];
int n,m;

bool inRange(int row, int col);
int dfs(int row, int col);
int main()
{
    int k;
    scanf("%d %d %d", &n, &m, &k);
    memset(board, 0, sizeof(board));
    
    for(int i=0; i<k; i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        board[a-1][b-1] = 1;
    }
    int ret = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!visited[i][j] && board[i][j] == 1) {
                ret = max(ret, dfs(i,j));
            }
        }
    }
    printf("%d\n", ret);
    
    return 0;
}

int dfs(int row, int col)
{
    visited[row][col] = true;
    int ret=1;
    for(int i=0; i<4; i++) {
        int nextRow = row+d[i][0];
        int nextCol = col+d[i][1];
        if(inRange(nextRow, nextCol) && !visited[nextRow][nextCol] && board[nextRow][nextCol] == 1) {
            ret += dfs(nextRow, nextCol);
        }
    }
    return ret;
}

bool inRange(int row, int col)
{
    if(row >= 0 && col >= 0 && row < n && col < m) return true;
    return false;
}