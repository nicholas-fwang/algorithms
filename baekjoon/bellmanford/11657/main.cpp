#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int oo = 0x3f3f3f3f;

vector<vector<pair<int, int> > > adj;

vector<int> bellmanFord(int src);

int main()
{
    int v,e;
    scanf("%d %d", &v, &e);
    adj = vector<vector<pair<int, int> > >(v);
    for(int i=0; i<e; i++) {
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        adj[a-1].push_back(make_pair(b-1,c));
    }
    vector<int> dists = bellmanFord(0);
    if(dists.size() == 0) {
        printf("-1\n");
        return 0;
    }
    for(int i=1; i<dists.size(); i++) {
        if(dists[i] >= oo) dists[i] = -1;
        printf("%d\n", dists[i]);
    }    
    return 0;
}

vector<int> bellmanFord(int src)
{
    int n = adj.size();
    vector<int> upper(adj.size(), oo);
    upper[src] = 0;
    bool updated;
    for(int iter=0; iter<n; iter++) {
        updated = false;
        for(int here=0; here<n; here++) {
            for(int i=0; i<adj[here].size(); i++) {
                int there = adj[here][i].first;
                int cost = adj[here][i].second;
                if(upper[there] > upper[here] + cost) {
                    updated = true;
                    upper[there] = upper[here]+cost;
                }
            }
        }
        if(!updated) break;
    }
    if(updated) upper.clear();
    return upper;
}