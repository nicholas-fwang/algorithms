#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
const int oo = 0x3f3f3f3f;

int adj[2500][2500];
bool board[2500];
int n,m;
int main()
{
    scanf("%d %d", &n, &m);
    memset(adj, oo, sizeof(adj));
    int d[4] = {1,-1,m,-m};
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        for(int j=0; j<s.size(); j++) {
            if(s[j] == 'L') board[i*m+j] = true;
            else board[i*m+j] = false;
        }
    }
    
    for(int i=0; i<n*m; i++) {
        for(int k=0; k<4; k++) {
            int next = i+d[k];
            if(next < 0 || next >= n*m) continue;
            if(i%m == 0 && next == i-1) continue;
            if(i%m == m-1 && next == i+1) continue;
            if(board[i] && board[next]) adj[i][next] = 1;
        }
    }
    
    for(int k=0; k<n*m; k++) {
        for(int i=0; i<n*m; i++) {
            for(int j=0; j<n*m; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    int ret = 0;
    for(int i=0; i<n*m; i++) {
        for(int j=0; j<n*m; j++) {
            if(i==j) continue;
            if(adj[i][j] < oo) {
                ret = max(ret, adj[i][j]);
            }
        }
    }
    printf("%d\n", ret);
    
    return 0;
}
