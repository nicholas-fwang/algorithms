#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

const int oo = 0x3f3f3f3f;

int main()
{
    int v,e;

    scanf("%d %d", &v, &e);
    vector<vector<pair<int, int> > > adj(v);
    priority_queue<pair<int, int> > pq;
    vector<int> dist(v, oo);
    int src;
    scanf("%d", &src);
    for(int i=0; i<e; i++) {
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        adj[a-1].push_back(make_pair(b-1, c));
    }
    pq.push(make_pair(0, src-1));
    dist[src-1] = 0;
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if(cost > dist[here]) continue;
        
        for(int i=0; i<adj[here].size(); i++) {
            int there = adj[here][i].first;
            int distNext = cost + adj[here][i].second;
            if(dist[there] > distNext) {
                dist[there] = distNext;
                pq.push(make_pair(-distNext, there));
            }
        }
    }
    for(int i=0; i<v; i++) {
        if(dist[i] == oo) {
            printf("INF\n");
            continue;
        }
        printf("%d\n", dist[i]);
    }
    return 0;
}