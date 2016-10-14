#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int oo = 0x3f3f3f3f;

int adj[5001][5001];

int main()
{
    int n,m;
    memset(adj, oo, sizeof(adj));
    scanf("%d %d", &n, &m);
    for(int i=1; i<=m; i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    
    for(int i=1; i<=n; i++) adj[i][i] = 0;
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
            }
        }
    }
    int min = oo;
    int ret = -1; 
    for(int i=1; i<=n; i++) {
        int m = 0;
        for(int j=1; j<=n; j++) {
            m += adj[i][j];
        }
        if(min > m) {
            ret = i;
            min = m;
        }
    }
    printf("%d\n", ret);
    return 0;
}