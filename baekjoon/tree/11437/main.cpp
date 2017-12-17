#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> tree[50001];
int parent[500001];
int depth[500001];
bool visited[500001];

void dfs(int here, int dep)
{
  visited[here] = true;
  depth[here] = dep;

  for(int i=0; i<tree[here].size(); i++) {
    int there = tree[here][i];
    if(!visited[there]) {
      parent[there] = here;
      dfs(there, dep+1);
    }
  }
}

int main()
{
  int n,m;
  scanf("%d", &n);
  for(int i=0; i<n-1; i++) {
    int u,v;
    scanf("%d %d", &u, &v);
    tree[u].push_back(v);
    tree[v].push_back(u);
  }
  for(int i=1; i<=n; i++) {
    parent[i] = i;
  }
  dfs(1, 1);
  scanf("%d", &m);
  for(int i=0; i<m; i++) {
    int u,v;
    scanf("%d %d", &u, &v);
    if(depth[u] > depth[v]) swap(u,v);

    while(depth[u] != depth[v]) {
      v = parent[v];
    }
    while(u != v) {
      u = parent[u];
      v = parent[v];
    }
    printf("%d\n", u);
  }
  return 0;
}
