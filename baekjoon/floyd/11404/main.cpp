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
    scanf("%d", &v);
    scanf("%d", &e);
    memset(adj, oo, sizeof(adj));
    
    for(int i=0; i<e; i++) {
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        adj[a-1][b-1] = min(adj[a-1][b-1], c);
    }
    
    for(int i=0; i<v; i++) adj[i][i] = 0;
    for(int k=0; k<v; k++) {
        for(int i=0; i<v; i++) {
            for(int j=0; j<v; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
            }
        }
    }
    for(int i=0; i<v; i++) {
        for(int j=0; j<v; j++) {
            if(adj[i][j] == oo) printf("0 ");
            else printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}