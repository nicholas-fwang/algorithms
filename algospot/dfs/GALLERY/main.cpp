#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int g,h;

vector<int> adj[1001];
vector<bool> visited;
int installed;

const int UNWATCHED = 0;
const int WATCHED = 1;
const int INSTALLED = 2;

int dfs(int here) {
    visited[here] = true;
    int children[3] = {0, 0, 0};
    for(int i=0; i<adj[here].size(); i++) {
        int there = adj[here][i];
        if(!visited[there]) {
            ++children[dfs(there)];
        }
    }
    if(children[UNWATCHED]) {
        ++installed;
        return INSTALLED;
    }
    if(children[INSTALLED]) {
        return WATCHED;
    }
    return UNWATCHED;
}

int installCamera() {
    installed = 0;
    visited = vector<bool>(g+1, false);
    for(int u=0; u<g; u++) {
        if(!visited[u] && dfs(u) == UNWATCHED) {
            ++installed;
        }
    }
    return installed;
}

int main()
{
    int testCase;
    scanf("%d", &testCase);
    for(int tc=1; tc<=testCase; tc++) {
        scanf("%d %d", &g, &h);
        for(int i=0; i<g; i++) {
            adj[i].clear();
        }
        for(int i=0; i<h; i++) {
            int t1,t2;
            scanf("%d %d", &t1, &t2);
            adj[t1].push_back(t2);
            adj[t2].push_back(t1);
        }
        printf("%d\n", installCamera());
    }
    return 0;
}