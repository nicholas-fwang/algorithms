#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int oo = 0x3f3f3f3f;

int N;
bool visited[100001];
vector<int> adj[100001], tree[100001];
int cache[100001][11];

int solve(int n, int c)
{
  int& ret = cache[n][c];
  if(ret != -1) return ret;
  ret = oo;

  for(int color=1; color<=10; color++) {
    if(c == color) continue;
    int result = color;
    for(int i=0; i<tree[n].size(); i++) {
      int child = tree[n][i];
      result += solve(child, color);
    }
    ret = min(ret, result);
  }
  return ret;
}

void dfs(int src)
{
  visited[src] = true;
  for(int i=0; i<adj[src].size(); i++) {
    int child = adj[src][i];
    if(!visited[child]) {
      tree[src].push_back(child);
      dfs(child);
    }
  }
}

int main()
{
  scanf("%d", &N);
  memset(cache, -1, sizeof(cache));

  for(int i=0; i<N-1; i++) {
    int p, c;
    scanf("%d %d", &p, &c);
    adj[p].push_back(c);
    adj[c].push_back(p);
  }
  dfs(1);
  int ret = oo;
  ret = min(ret, solve(1,0));

  printf("%d\n", ret);
  return 0;
}
