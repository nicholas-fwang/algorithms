#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> a;
vector<int> tree;

int sum(int i)
{
  int ret = 0;
  while(i > 0) {
    ret += tree[i];
    i -= (i & -i);
  }
  return ret;
}

void update(int i, int diff)
{
  while(i < tree.size()) {
    tree[i] += diff;
    i += (i & -i);
  }
}

int main()
{
  int testCase;
  scanf("%d", &testCase);
  for(int tc=1; tc<=testCase; tc++) {
    int n,m;
    scanf("%d %d", &n, &m);
    a.clear();
    a.resize(n+m+1, 0);
    tree.clear();
    tree.resize(n+m+1, 0);

    for(int i=m+1; i<=m+n; i++) {
      update(i, 1);
      a[i-m] = i;
    }
    int idx = m;
    for(int i=0; i<m; i++) {
      int v;
      scanf("%d", &v);
      printf("%d ", sum(a[v]-1));
      update(a[v], -1);
      a[v] = idx--;
      update(a[v], 1);
    }
    printf("\n");
  }
  return 0;
}
