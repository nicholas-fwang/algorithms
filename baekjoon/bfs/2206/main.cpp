#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;
const int oo = 0x3f3f3f3f;
const int d[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};

int adj[1000][1000];
int dist[1000][1000][2];
int n,m;
bool inRange(int row, int col);
int main()
{
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        for(int j=0; j<s.size(); j++) {
            adj[i][j] = s[j]-'0';    
        }
    }
    memset(dist, oo, sizeof(dist));
    
    dist[0][0][0] = 1;
    // 백 깨부순 여부, 정점 인덱스(row,col)
    queue<pair<int, pair<int, int> > > q;
    q.push(make_pair(0,make_pair(0,0)));
    while(!q.empty()) {
        int isBreak = q.front().first;
        int row = q.front().second.first;
        int col = q.front().second.second;
        q.pop();
        
        for(int i=0; i<4; i++) {
            int nextRow = row+d[i][0];
            int nextCol = col+d[i][1];
            if(!inRange(nextRow,nextCol) || dist[nextRow][nextCol][isBreak] < oo) continue;
            if(adj[nextRow][nextCol] == 0) {
                dist[nextRow][nextCol][isBreak] = dist[row][col][isBreak]+1;
                q.push(make_pair(isBreak,make_pair(nextRow,nextCol)));
            } else {
                if(isBreak == 0) {
                    dist[nextRow][nextCol][1] = 
                        min(dist[nextRow][nextCol][1],dist[row][col][0]+1);
                    q.push(make_pair(1,make_pair(nextRow,nextCol)));
                }
            }
        }
    }
    int ret = min(dist[n-1][m-1][0], dist[n-1][m-1][1]);
    if(ret == oo) printf("-1\n");
    else printf("%d\n", ret);
    
    return 0;
}

bool inRange(int row, int col)
{
    if(row >= 0 && row < n && col >= 0 && col < m) return true;
    return false;
}