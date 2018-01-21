// TIMEOUT

#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

priority_queue<pair<int, int> > pq;
vector<int> vec;

int main()
{
  int n,k,m,v,c;
  scanf("%d %d", &n, &k);
  for(int i=0; i<n; i++) {
    scanf("%d %d", &m, &v);
    pq.push(make_pair(v, m));
  }
  for(int i=0; i<k; i++) {
    scanf("%d", &c);
    vec.push_back(c);
  }
  int ret = 0;
  while(pq.size()) {
    int cost = pq.top().first;
    int pay = pq.top().second;
    pq.pop();
    auto it = lower_bound(vec.begin(), vec.end(), pay);
    if(it == vec.end()) continue;
    vec.erase(it);
    ret += cost;
  }
  printf("%d\n", ret);
  return 0;
}
