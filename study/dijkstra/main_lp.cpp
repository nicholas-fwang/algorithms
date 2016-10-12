#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int oo = 0x3f3f3f3f;

vector<vector<pair<int, int> > > adj;

vector<int> dijkLP(int src);

int main()
{
    int v,e;
    scanf("%d %d", &v, &e);
    adj = vector<vector<pair<int, int> > >(v);
    for(int i=0; i<e; i++) {
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        adj[a].push_back(make_pair(b,c));
    }
    vector<int> ret = dijkLP(0);
    for(int i=0; i<ret.size(); i++) {
        printf("%d ", ret[i]);
    }
    printf("\n");
    return 0;
}

vector<int> dijkLP(int src)
{
    int n = adj.size();
    vector<int> dists(n, -oo);
    dists[src] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, src));
    while(!pq.empty()) {
        int cost = pq.top().first;
        int here = pq.top().second;
        pq.pop();
        
        if(cost < dists[here]) continue;
        
        for(int i=0; i<adj[here].size(); i++) {
            int there = adj[here][i].first;
            int distNext = cost + adj[here][i].second;
            if(distNext > dists[there]) {
                dists[there] = distNext;
                pq.push(make_pair(distNext, there));
            }
        }
    }
    
    return dists;
}