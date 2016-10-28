#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;
const int d[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

int n,m;
int map[100][100];
int visited[100][100];

void bfs(int r, int c);
bool inRange(int r, int c);
int main()
{
    scanf("%d %d", &n, &m);
    memset(map, -1, sizeof(map));
    memset(visited, -1, sizeof(visited));
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        for(int j=0; j<s.size(); j++) {
            map[i][j] = s[j]-'0';
        }
    }
    
    bfs(0,0);
    printf("%d\n", visited[n-1][m-1]);
    return 0;
}

void bfs(int r, int c)
{
    int ret = 1;
    visited[r][c] = 1;
    queue<pair<pair<int, int>, int> > q;
    q.push(make_pair(make_pair(0,0),1));
    while(!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int cost = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int nextRow = row+d[i][0];
            int nextCol = col+d[i][1];
            int nextCost = cost+1;
            if(inRange(nextRow,nextCol) && map[nextRow][nextCol] == 1 && visited[nextRow][nextCol] == -1) {
                visited[nextRow][nextCol] = nextCost;
                q.push(make_pair(make_pair(nextRow,nextCol),nextCost));
            }
        }
    }
}

bool inRange(int r, int c)
{
    if(r >=0 && c >= 0 && r < n && c < m) return true;
    return false;
}