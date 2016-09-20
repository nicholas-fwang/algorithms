#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<int> visited;
vector<vector<int> > adj;

void dfs(int here, int init);

int main()
{
    int n;
    scanf("%d", &n);
    adj = vector<vector<int> >(n, vector<int>(n, 0));
    visited = vector<int>(n, 0);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    
    for(int i=0; i<n; i++) {
        dfs(i, 0);
        for(int j=0; j<n; j++) {
            printf("%d ", visited[j]);
        }
        for(int j=0; j<n; j++) {
            visited[j] = 0;
        }
        printf("\n");
    }
    
    return 0;
}

void dfs(int here, int init)
{
    if(init) visited[here] = 1;
    for(int i=0; i<adj.size(); i++) {
        if(!visited[i] && adj[here][i]) {
            dfs(i, 1);
        }
    }
}