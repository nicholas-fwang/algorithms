#include <cstdio>
#include <cmath>
#include <vector>

const int oo = 0x3f3f3f3f;

using namespace std;

long long init(vector<long long> &a, vector<long long> &tree, int node, int start, int end) {
    if (start == end) {
        return tree[node] = a[start];
    } else {
        return tree[node] = min(init(a, tree, node*2, start, (start+end)/2), init(a, tree, node*2+1, (start+end)/2+1, end));
    }
}

long long query(vector<long long> &tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return oo;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    return min(query(tree, node*2, start, (start+end)/2, left, right), query(tree, node*2+1, (start+end)/2+1, end, left, right));
}

int main() {
    int testCase;
    scanf("%d", &testCase);
    for(int tc=1; tc<=testCase; tc++) {
      int n,q;
      scanf("%d %d", &n, &q);
      vector<long long> a(n);
      for(int i=0; i<n; i++) {
        scanf("%lld", &a[i]);
      }
      int h = (int)ceil(log2(n));
      int tree_size = (1 << (h+1));
      vector<long long> minTree(tree_size);
      vector<long long> maxTree(tree_size);

      init(a, minTree, 1, 0, n-1);

      vector<long long> b(n);
      for(int i=0; i<n; i++) {
        b[i] = -a[i];
      }
      init(b, maxTree, 1, 0, n-1);
      for(int i=0; i<q; i++) {
        int s,e;
        scanf("%d %d", &s, &e);
        long long min = query(minTree, 1, 0, n-1, s, e);
        long long max = -query(maxTree, 1, 0, n-1, s, e);
        printf("%lld\n", max-min);
      }
    }
    return 0;
}
