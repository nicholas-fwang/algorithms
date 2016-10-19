#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int oo = 0x3f3f3f3f;

int adj[100][100];
int main()
{
    int v,e;
    scanf("%d %d", &v, &e);
    memset(adj, oo, sizeof(adj));
    for(int i=0; i<e; i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        adj[a-1][b-1] = 1;
        adj[b-1][a-1] = 1;
    }
    for(int i=0; i<v; i++) adj[i][i] = 0;
    for(int k=0; k<v; k++) {
        for(int i=0; i<v; i++) {
            for(int j=0; j<v; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
            }
        }
    }
    int ret=0;
    for(int i=0; i<v; i++) {
        if(adj[0][i] < oo && adj[0][i] > 0) ret++;
    }
    printf("%d\n", ret);
    return 0;
}