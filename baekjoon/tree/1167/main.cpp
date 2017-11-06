#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;

vector<pair<int, ll> > adj[100001];
int N;
vector<bool> visited;

pair<int,int> dfs(int here)
{
  visited[here] = true;
  pair<int, ll> ret(here, 0);
  for(int i=0; i<adj[here].size(); i++) {
    int next = adj[here][i].first;
    if(!visited[next]) {
      pair<int, ll> tmp = dfs(next);
      tmp.second += adj[here][i].second;
      if(tmp.second > ret.second) {
        ret = tmp;
      }
    }
  }
  return ret;
}

int main()
{
  scanf("%d", &N);
  for(int i=0; i<N; i++) {
    int n,v,w;
    scanf("%d", &n);
    while(true) {
      scanf("%d", &v);
      if(v == -1) break;
      scanf("%d", &w);
      adj[n].push_back(make_pair(v,w));
    }
  }
  visited.resize(N+1);
  fill(visited.begin(), visited.end(), false);
  pair<int, ll> t = dfs(1);
  fill(visited.begin(), visited.end(), false);
  pair<int, ll> u = dfs(t.first);
  printf("%lld\n", u.second);
  return 0;
}
