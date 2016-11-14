#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;
const int dx[4] = {0,0,1,-1};
const int dy[4] = {1,-1,0,0};

int n,m;
string map[50];
int dist[50][50];
int bfs(int row, int col);
bool inRange(int row, int col);
int main()
{
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++) {
        cin >> map[i];
    }
    
    int ret = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(map[i][j] == 'L') ret = max(ret, bfs(i,j));
        }
    }
    printf("%d\n", ret);
    return 0;
}

int bfs(int row, int col)
{
    memset(dist, -1, sizeof(dist));
    queue<pair<int, int> > q;
    q.push(make_pair(row, col));
    dist[row][col] = 0;
    int ret = 0;
    while(!q.empty()) {
        int hereRow = q.front().first;
        int hereCol = q.front().second;
        q.pop();
        
        ret = max(ret, dist[hereRow][hereCol]);
        for(int i=0; i<4; i++) {
            int nextRow = hereRow + dy[i];
            int nextCol = hereCol + dx[i];
            if(inRange(nextRow, nextCol) && map[nextRow][nextCol] == 'L' && dist[nextRow][nextCol] == -1) {
                dist[nextRow][nextCol] = dist[hereRow][hereCol] + 1;
                q.push(make_pair(nextRow, nextCol));
            }
        }
    }
    
    return ret;
}

bool inRange(int row, int col)
{
    return row >= 0 && row < n && col >=0 && col < m;
}