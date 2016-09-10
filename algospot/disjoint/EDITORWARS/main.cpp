#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct DISJOINT {
    int n;
    // dis : dis한 root의 번호가 저장된다.
    // siz : 집합의 root 인덱스에 집합의 크기가 저장된다
    vector<int> parent, rank, dis, siz;
    
    DISJOINT(int _n): n(_n), parent(_n), rank(_n,1), dis(_n, -1), siz(_n, 1) {
        for(int i=0; i<_n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int u) {
        if(parent[u] == u) {
            return u;
        }
        return parent[u] = find(parent[u]);
    }
    
    bool merge(int u, int v) {
        u = find(u), v = find(v);
        // 합치기하는데 모순일 경우
        if(dis[u] == v) {
            return false;
        }
        if(u == v) {
            return true;
        }
        if(rank[u] > rank[v]) {
            swap(u, v);
        }
        siz[v] += siz[u];
        parent[u] = v;
        if(rank[u] == rank[v]) {
            ++rank[v];
        }
        return true;
    }
    
    bool notmerge(int u, int v) {
        u = find(u), v = find(v);
        // dis가 모순일 경우
        if(u == v) {
            return false;
        }
        dis[u] = v;
        dis[v] = u;
        return true;
    }
    
    int getMax() {
        int root = find(0);
        if(siz[root] < siz[dis[root]]) {
            root = dis[root];
        }
        for(int i=1; i<n; i++) {
            int v = find(i);
            if(root != v && dis[root] != v) {
                int u;
                if(v > dis[v]) {
                    merge(v, root);
                    if(dis[v] >= 0) {
                        merge(dis[v], dis[root]);   
                    }
                } else {
                    merge(dis[v], root);
                    if(dis[root] >= 0) {
                        merge(v, dis[root]);   
                    }
                }
                root = find(root);
                if(dis[root] >= 0) {
                    u = find(dis[root]);    
                    notmerge(root, u);
                }
            }
        }
        // 최종 합친 root에 dis가 없다, 다 같은 집합이다
        if(dis[root] == -1) return n;
        // root 집합이 댓글 최대기 때문에 dis는 최소다
        else return n - siz[dis[root]];
    }
};

int main()
{
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        int n,m;
        bool flag = false;
        scanf("%d %d", &n, &m);
        DISJOINT disjoint(n);
        int i;
        for(i=0; i<m; i++) {
            string s;
            int a, b;
            cin >> s >> a >> b;
            if(s == "ACK") {
                // ACK은 합친다
                if(!disjoint.merge(a,b)) {
                    flag = true;
                    break;
                }
            } else {
                // DIS를 등록한다
                if(!disjoint.notmerge(a,b)) {
                    flag = true;
                    break;
                }
            }
        }
        if(flag) {
            printf("CONTRADICTION AT %d\n", i+1);
        } else {
            printf("MAX PARTY SIZE IS %d\n", disjoint.getMax());   
        }
    }
    return 0;
}