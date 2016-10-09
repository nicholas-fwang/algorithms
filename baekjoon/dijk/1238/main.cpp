#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

const int oo = 0x3f3f3f3f;

vector<vector<pair<int, int> > > adj;

vector<int> dijk(int src);

int main()
{
    int v,e,x;
    scanf("%d %d %d", &v, &e, &x);
    adj = vector<vector<pair<int, int> > >(v);
    for(int i=0; i<e; i++) {
        int u1,v1,w1;
        scanf("%d %d %d", &u1, &v1, &w1);
        adj[u1-1].push_back(make_pair(v1-1, w1));
    }
    vector<vector<int> > dists(v, vector<int>(v));
    for(int i=0; i<v; i++) {
        vector<int> dij = dijk(i);
        for(int j=0; j<dij.size(); j++) {
            dists[i][j] = dij[j];
        }
    }
    int ret = 0;
    for(int i=0; i<v; i++) {
        ret = max(ret, dists[x-1][i]+dists[i][x-1]);
    }
    printf("%d\n", ret);
    return 0;
}

vector<int> dijk(int src)
{
    int n = adj.size();
    vector<int> dist(n, oo);
    dist[src] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, src));
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        
        if(cost > dist[here]) continue;
        
        for(int i=0; i<adj[here].size(); i++) {
            int there = adj[here][i].first;
            int distNext = cost + adj[here][i].second;
            if(distNext < dist[there]) {
                dist[there] = distNext;
                pq.push(make_pair(-distNext, there));
            }
        }
    }
    return dist;
}