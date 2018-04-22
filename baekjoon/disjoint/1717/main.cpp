#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct DisjoinSet {
    vector<int> parent, rank;

    DisjoinSet(int n) : parent(n+1), rank(n+1, 1) {
        for(int i=1; i<=n; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    void merge(int u, int v) {
        u = find(u), v = find(v);
        if(u == v) return ;
        if(rank[u] > rank[v]) swap(u, v);
        parent[u] = v;
        if(rank[u] == rank[v]) ++rank[v];
    }
};

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    DisjoinSet set(n);
    for(int i=0; i<m; i++) {
        int a1, a2, a3;
        scanf("%d %d %d", &a1, &a2, &a3);
        if(a1 == 0) {
            set.merge(a2, a3);
        }
        else {
            int f1 = set.find(a2);
            int f2 = set.find(a3);
            if(f1 == f2) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
