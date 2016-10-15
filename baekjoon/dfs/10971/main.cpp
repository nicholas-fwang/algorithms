#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int oo = 0x3f3f3f3f;

vector<vector<pair<int, int> > > adj;
vector<bool> visited;

int dfs(int here, int end);
int main()
{
    int n;
    scanf("%d", &n);
    adj = vector<vector<pair<int, int> > >(n);
    visited = vector<bool>(n, false);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int a;
            scanf("%d", &a);
            if(a > 0) adj[i].push_back(make_pair(j,a));
        }
    }
    printf("%d\n", dfs(0, 0));
    return 0;
}

int dfs(int here, int end)
{
    if(here == end) {
        bool all = true;
        for(int i=0; i<adj.size(); i++) {
            if(!visited[i]) {
                all = false;
                break;
            }
        }
        if(all) return 0;
    }
    int ret = oo;
    for(int i=0; i<adj[here].size(); i++) {
        int there = adj[here][i].first;
        int cost = adj[here][i].second;
        if(!visited[there]) {
            visited[there] = true;
            ret = min(ret, dfs(there, end)+cost);
            visited[there] = false;
        }
    }
    return ret;
}