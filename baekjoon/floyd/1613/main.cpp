#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;
const int oo = 0x3f3f3f3f;

int adj[400][400];

int main()
{
    int v,e;
    scanf("%d %d", &v, &e);
    memset(adj, oo, sizeof(adj));
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
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        int s,e;
        scanf("%d %d", &s, &e);
        if(adj[s-1][e-1] < oo) {
            printf("-1\n");
        } else {
            if(adj[e-1][s-1] < oo) {
                printf("1\n");
            } else {
                printf("0\n");
            }
        }
    }
    return 0;
}