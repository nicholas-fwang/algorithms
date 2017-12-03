#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
long long init(vector<long long> &a, vector<long long> &tree, int node, int start, int end) {
    if (start == end) {
        return tree[node] = a[start];
    } else {
        return tree[node] = init(a, tree, node*2, start, (start+end)/2) + init(a, tree, node*2+1, (start+end)/2+1, end);
    }
}
void update(vector<long long> &tree, int node, int start, int end, int index, long long diff) {
    if (index < start || index > end) return;
    tree[node] = tree[node] + diff;
    if (start != end) {
        update(tree,node*2, start, (start+end)/2, index, diff);
        update(tree,node*2+1, (start+end)/2+1, end, index, diff);
    }
}
long long sum(vector<long long> &tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    return sum(tree, node*2, start, (start+end)/2, left, right) + sum(tree, node*2+1, (start+end)/2+1, end, left, right);
}
int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    vector<long long> a(n, 0);
    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h+1));
    vector<long long> tree(tree_size);

    init(a, tree, 1, 0, n-1);

    for(int i=0; i<q; i++) {
      int t;
      scanf("%d", &t);
      if(t == 1) {
        int t2, m;
        scanf("%d %d", &t2, &m);
        int diff = m - a[t2-1];
        update(tree, 1, 0, n-1, t2-1, diff);
      }
      else {
        int t2,t3;
        scanf("%d %d", &t2, &t3);
        printf("%lld\n", sum(tree, 1, 0, n-1, t2-1, t3-1));
      }
    }

    return 0;
}
