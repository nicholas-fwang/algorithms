#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int adj[50][50];
int map[50][50];
bool visited[50][50];
int n,m;
int size=0;
int cnt=0;
int arr[2501];
int dfsAll();
int dfs(int row, int col);
int main()
{
    memset(arr, 0, sizeof(arr));
    scanf("%d %d", &m, &n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%d", &map[i][j]);
            visited[i][j] = false;
        }
    }
    int count = dfsAll();
    printf("%d\n", count);
    printf("%d\n", size);
    int ret = 0;

    for(int row=0; row<n; row++) {
        for(int col=0; col<m; col++) {
            if(col+1 < m && adj[row][col] != adj[row][col+1]) {
                ret = max(ret, arr[adj[row][col]]+arr[adj[row][col+1]]);
            }
            if(row+1 < n && adj[row][col] != adj[row+1][col]) {
                ret = max(ret, arr[adj[row][col]]+arr[adj[row+1][col]]);
            }
        }
    }
    printf("%d\n", ret);
}

int dfsAll()
{
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!visited[i][j]) {
                int s = dfs(i,j);
                arr[cnt] = s;
                size = max(size, s);
                cnt++;
            }
        }
    }
    return cnt;
}
int dfs(int row, int col)
{
    visited[row][col] = true;
    int ret = 1;
    if((map[row][col] & 1) == 0) if(!visited[row][col-1]) {
         ret += dfs(row,col-1);
    }
    if((map[row][col] & 2) == 0) if(!visited[row-1][col]) {
        ret += dfs(row-1,col);
    }
    if((map[row][col] & 4) == 0) if(!visited[row][col+1]) {
        ret += dfs(row,col+1);
    }
    if((map[row][col] & 8) == 0) if(!visited[row+1][col]) {
        ret += dfs(row+1,col);
    }
    adj[row][col] = cnt;
    return ret;   
}