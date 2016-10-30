#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

vector<int> adj[1001];
int matched[1001];
vector<bool> visited;
int n,m;
    bool dfs(int here);
int main()
{
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++) {
        int tmp;
        scanf("%d", &tmp);
        for(int j=0; j<tmp; j++) {
            int t;
            scanf("%d", &t);
            adj[i].push_back(t);
        }
    }
    memset(matched, -1, sizeof(matched));
    int ret = 0;
    for(int i=1; i<=n; i++) {
        visited = vector<bool>(n+1, false);
        if(dfs(i)) ret++;
    }
    for(int i=1; i<=n; i++) {
        visited = vector<bool>(n+1, false);
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
        if(matched[there]==-1 || dfs(matched[there])) {
            matched[there] = here;
            return true;
        }
    }
    return false;
}