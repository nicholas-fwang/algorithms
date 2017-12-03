#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<long long> a;
vector<long long> tree;

long long init(int node, int start, int end) {
  if(start == end) {
    return tree[node] = a[start];
  }
  else {
    int mid = (start+end)/2;
    return tree[node] = init(node*2, start, mid) + init(node*2+1, mid+1, end);
  }
}

void update(int node, int start, int end, int index, long long diff) {
  if(index < start || index > end) return ;
  tree[node] = tree[node] + diff;
  if(start != end) {
    int mid = (start+end)/2;
    update(node*2, start, mid, index, diff);
    update(node*2+1, mid+1, end, index, diff);
  }
}

long long sum(int node, int start, int end, int left, int right) {
  if(left > end || right < start) {
    return 0;
  }
  if(left <= start && end <= right) {
    return tree[node];
  }
  int mid = (start+end)/2;
  return sum(node*2, start, mid, left, right) + sum(node*2+1, mid+1, end, left, right);
}

int main()
{
  int n,m,k;
  scanf("%d %d %d", &n, &m, &k);
  a = vector<long long>(n);
  int tree_size = 4*n;
  tree = vector<long long>(tree_size);
  for(int i=0; i<n; i++) {
    scanf("%lld", &a[i]);
  }
  init(1, 0, n-1);
  for(int i=0; i<m+k; i++) {
    int t1;
    scanf("%d", &t1);
    if(t1 == 1) {
      int t2;
      long long t3;
      scanf("%d %lld", &t2, &t3);
      long long diff = t3-a[t2-1];
      a[t2-1] = t3;
      update(1, 0, n-1, t2-1, diff);
    }
    else if(t1 == 2) {
      int t2,t3;
      scanf("%d %d", &t2, &t3);
      printf("%lld\n", sum(1, 0, n-1, t2-1, t3-1));
    }
  }
  return 0;
}
