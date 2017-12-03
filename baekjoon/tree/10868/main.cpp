#include <iostream>
#include <cstdio>
#include <vector>

const int oo =0x3f3f3f3f;

using namespace std;

vector<long long> a;
vector<long long> tree;

long long init(int node, int start, int end) {
  if(start == end) {
    return tree[node] = a[start];
  }
  else {
    int mid = (start+end)/2;
    long long l = init(node*2+1, start, mid);
    long long r = init(node*2+2, mid+1, end);
    return tree[node] = min(l, r);
  }
}

long long query(int node, int start, int end, int left, int right) {
  if (left > end || right < start) {
      return oo;
  }
  if (left <= start && end <= right) {
      return tree[node];
  }
  int mid = (start+end)/2;
  return min(query(node*2+1, start, mid, left, right), query(node*2+2, mid+1, end, left, right));
}

int main()
{
  int n,q;
  scanf("%d %d", &n, &q);
  a.resize(n);
  tree.resize(4*n);
  for(int i=0; i<n; i++) {
    scanf("%lld", &a[i]);
  }
  init(0, 0, n-1);
  for(int i=0; i<q; i++) {
    int t1,t2;
    scanf("%d %d", &t1, &t2);
    printf("%lld\n", query(0, 0, n-1, t1-1, t2-1));
  }
  return 0;
}
