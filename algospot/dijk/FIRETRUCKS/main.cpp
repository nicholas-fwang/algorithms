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
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        int v,e,n,m;
        scanf("%d %d %d %d", &v, &e, &n, &m);
        adj = vector<vector<pair<int, int> > >(v+1);
        for(int i=0; i<e; i++) {
            int a,b,c;
            scanf("%d %d %d", &a, &b, &c);
            adj[a].push_back(make_pair(b,c));
            adj[b].push_back(make_pair(a,c));
        }
        vector<int> fire;
        for(int i=0;i<n;i++) {
            int tmp;
            scanf("%d", &tmp);
            fire.push_back(tmp);
        }
        for(int i=0;i<m;i++) {
            int tmp;
            scanf("%d", &tmp);
            adj[0].push_back(make_pair(tmp,0));
            adj[tmp].push_back(make_pair(0,0));
        }
        vector<int> dists = dijk(0);
        int ret=0;
        for(int i=0;i<fire.size();i++) {
            ret += dists[fire[i]];
        }
        printf("%d\n", ret);
    }
    return 0;
}

vector<int> dijk(int src)
{
    vector<int> dists(adj.size(), oo);
    dists[src] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, src));
    
    while(!pq.empty()) {
        int cost = -pq.top().first;    
        int here = pq.top().second;
        pq.pop();
        
        if(cost > dists[here]) continue;
        
        for(int i=0; i<adj[here].size(); i++) {
            int there = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;
            if(dists[there] > nextDist) {
                dists[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }
    
    return dists;
}