#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int oo = 0x3f3f3f3f;
const int d[6][3] = {{0,0,1}, {0,0,-1}, {0,1,0}, {0,-1,0}, {1,0,0}, {-1,0,0}};

int adj[102][102][102];
int main()
{
    int M,N,H;
    memset(adj, oo, sizeof(adj));
    queue<pair<int, pair<int, int> > > q;
    scanf("%d %d %d", &M, &N, &H);
    for(int h=1; h<=H; h++) {
        for(int n=1; n<=N; n++) {
            for(int m=1; m<=M; m++) {
                scanf("%d", &adj[n][m][h]);
                if(adj[n][m][h] == 1) q.push(make_pair(n,make_pair(m,h)));
            }
        }
    }
    while(!q.empty()) {
        int row = q.front().first;
        int col = q.front().second.first;
        int hei = q.front().second.second;
        q.pop();
        
        for(int i=0; i<6; i++) {
            int nextRow = row + d[i][0];
            int nextCol = col + d[i][1];
            int nextHei = hei + d[i][2];
            if(adj[nextRow][nextCol][nextHei] == 0) {
                adj[nextRow][nextCol][nextHei] = adj[row][col][hei] + 1;
                q.push(make_pair(nextRow, make_pair(nextCol, nextHei)));
            }
        }
    }
    
    int ret = 0;
    for(int h=1; h<=H; h++) {
        for(int n=1; n<=N; n++) {
            for(int m=1; m<=M; m++) {
                if(adj[n][m][h] == 0) {
                    printf("-1\n");
                    return 0;
                }
                ret = max(ret, adj[n][m][h]);
            }
        }
    }
    printf("%d\n", ret-1);
    
    return 0;
}