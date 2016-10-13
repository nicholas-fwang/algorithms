#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int oo = 0x3f3f3f3f;
const int d[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};

int adj[1002][1002];

int main()
{
    int m,n;
    scanf("%d %d", &n, &m);
    memset(adj, oo, sizeof(adj));
    queue<pair<int, int> > q;
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            scanf("%d", &adj[i][j]);
            if(adj[i][j] == 1) {
                q.push(make_pair(i,j));
            }
        }
    }
    while(!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++) {
            int nextRow = row+d[i][0];
            int nextCol = col+d[i][1];
            if(adj[nextRow][nextCol] == 0) {
                adj[nextRow][nextCol] = adj[row][col] + 1;
                q.push(make_pair(nextRow, nextCol));
            } 
        }
    }
    
    int ret = -1;
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(adj[i][j] == 0) {
                printf("-1\n");
                return 0;
            }
            ret = max(ret, adj[i][j]);
        }
    }
    printf("%d\n", ret-1);
       
    
    return 0;
}