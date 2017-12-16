#include <cstdio>
#include <iostream>
#include <vector>

const long long oo = 1000000001;

using namespace std;

long long initMin(vector<long long>& a, vector<long long>& tree, int node, int start, int end) {
  if(start == end) {
    return tree[node] = a[start];
  }
  int mid = (start+end)/2;
  return tree[node] = min(initMin(a, tree, node*2, start, mid), initMin(a, tree, node*2+1, mid+1, end));
}

long long queryMin(vector<long long>& tree, int node, int start, int end, int left, int right) {
  if(left > end || right < start) {
    return oo;
  }
  if(left <= start && end <= right) {
    return tree[node];
  }
  int mid = (start+end)/2;
  return min(queryMin(tree, node*2, start, mid, left, right), queryMin(tree, node*2+1, mid+1, end, left, right));
}

long long initMax(vector<long long>& a, vector<long long>& tree, int node, int start, int end) {
  if(start == end) {
    return tree[node] = a[start];
  }
  int mid = (start+end)/2;
  return tree[node] = max(initMax(a, tree, node*2, start, mid), initMax(a, tree, node*2+1, mid+1, end));
}

long long queryMax(vector<long long>& tree, int node, int start, int end, int left, int right) {
  if(left > end || right < start) {
    return 0;
  }
  if(left <= start && end <= right) {
    return tree[node];
  }
  int mid = (start+end)/2;
  return max(queryMax(tree, node*2, start, mid, left, right), queryMax(tree, node*2+1, mid+1, end, left, right));
}

int main()
{
  int n,m;
  scanf("%d %d", &n, &m);
  vector<long long> a(n);
  vector<long long> minTree(4*n);
  vector<long long> maxTree(4*n);
  for(int i=0; i<n; i++) {
    scanf("%lld", &a[i]);
  }
  initMin(a, minTree, 1, 0, n-1);
  initMax(a, maxTree, 1, 0, n-1);
  for(int i=0; i<m; i++) {
    int start, end;
    scanf("%d %d", &start, &end);
    printf("%lld %lld\n", queryMin(minTree, 1, 0, n-1, start-1 ,end-1),
      queryMax(maxTree, 1, 0, n-1, start-1, end-1));
  }
  return 0;
}
