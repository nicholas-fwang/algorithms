#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

vector<int> adj[101];
int matched[5001];
vector<bool> visited;
bool dfs(int here);
int main()
{
    int n,m;
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        adj[a-1].push_back(b-1);
    }
    memset(matched, -1, sizeof(matched));
    int ret = 0;
    for(int i=0; i<n; i++) {
        visited = vector<bool>(n, false);
        if(dfs(i)) ret++;
    }
    printf("%d\n", ret);
    return 0;
}

bool dfs(int here)
{
    if(visited[here]) return false;
    visited[here] = true;
    for(int i=0; i<adj[here].size(); i++) {
        int there = adj[here][i];
        if(matched[there] == -1 || dfs(matched[there])) {
            matched[there] = here;
            return true;
        }
    }
    return false;
}