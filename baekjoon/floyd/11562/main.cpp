#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;
const int oo = 0x3f3f3f3f;

int adj[250][250];
int main()
{
    int v,e;
    memset(adj, oo, sizeof(adj));
    scanf("%d %d", &v, &e);
    for(int i=0; i<e; i++) {
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        if(c==0) {
            adj[a-1][b-1] = 0;
            adj[b-1][a-1] = 1;
        } else {
            adj[a-1][b-1] = 0;
            adj[b-1][a-1] = 0;
        }
    }
    for(int i=0; i<v; i++) adj[i][i] = 0;
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
        int a,b;
        scanf("%d %d", &a, &b);
        printf("%d\n", adj[a-1][b-1]);
    }
    return 0;
}