#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;
const int oo = 0x3f3f3f3f;

vector<pair<int, int> > adj[1000];
int v,e;

vector<int> dijk(int src);
int main()
{
    scanf("%d %d", &v, &e);
    for(int i=0; i<e; i++) {
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        adj[a-1].push_back(make_pair(b-1,c));
    }
    int start,end;
    scanf("%d %d", &start, &end);
    vector<int> rets = dijk(start-1);
    printf("%d\n", rets[end-1]);
    return 0;
}

vector<int> dijk(int src)
{
    vector<int> dists(v, oo);
    dists[src] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0,src));
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        
        if(cost > dists[here]) continue;
        
        for(int i=0; i<adj[here].size(); i++) {
            int there = adj[here][i].first;
            int nextCost = cost + adj[here][i].second;
            if(dists[there] > nextCost) {
                dists[there] = nextCost;
                pq.push(make_pair(-nextCost, there));
            }
        }
    }
    return dists;
}