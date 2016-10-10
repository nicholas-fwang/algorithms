#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

const long long oo = 0x3f3f3f3f;
vector<vector<pair<int, int> > > adj;

vector<long long> dijk(int src);

int main()
{
    int v,e;
    scanf("%d %d", &v, &e);
    adj = vector<vector<pair<int, int > > >(v);
    for(int i=0; i<e; i++) {
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        adj[a-1].push_back(make_pair(b-1, c));
        adj[b-1].push_back(make_pair(a-1, c));
    }
    int v1,v2;
    scanf("%d %d", &v1, &v2);
    vector<long long> vv = dijk(0);
    vector<long long> vv1 = dijk(v1-1);
    vector<long long> vv2 = dijk(v2-1);
    long long ret1 = vv[v1-1]+vv1[v2-1]+vv2[v-1];
    long long ret2 = vv[v2-1]+vv2[v1-1]+vv1[v-1];
    long long ret = min(ret1, ret2);
    if(ret >= oo) {
        printf("-1\n");
        return 0;
    }
    printf("%lld\n", ret);
    return 0;
}

vector<long long> dijk(int src)
{
    int n = adj.size();
    vector<long long> dist(n, oo);
    dist[src] = 0;
    priority_queue<pair<long long, int> > pq;
    pq.push(make_pair(0, src));
    while(!pq.empty()) {
        long long cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        
        if(cost > dist[here]) continue;
        
        for(int i=0; i<adj[here].size(); i++) {
            int there = adj[here][i].first;
            long long distNext = cost + adj[here][i].second;
            if(distNext < dist[there]) {
                dist[there] = distNext;
                pq.push(make_pair(-distNext, there));
            }
        }
    }
    return dist;
}