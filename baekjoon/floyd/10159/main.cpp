#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;
const int oo = 0x3f3f3f3f;

int adj[100][100];

int main()
{
    memset(adj, oo, sizeof(adj));
    int v,e;
    scanf("%d %d", &v, &e);
    for(int i=0; i<e; i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        adj[a-1][b-1] = 1;
    }
    
    for(int k=0; k<v; k++) {
        for(int i=0; i<v; i++) {
            for(int j=0; j<v; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
            }
        }
    }
    for(int i=0; i<v; i++) {
        int ret=0;
        for(int j=0; j<v; j++) {
            if(min(adj[i][j],adj[j][i]) < oo) ret++;
        }
        printf("%d\n", v-ret-1);
    }
    return 0;
}