#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > adj;
int main()
{
    int n,k;
    scanf("%d %d", &n, &k);
    adj = vector<vector<int> >((n>k?n+2:k+2));
    
    for(int i=0; i<adj.size(); i++) {
        if(i-1 >= 0) adj[i].push_back(i-1);
        if(i+1 < adj.size()) adj[i].push_back(i+1);
        if(i*2 < adj.size()) adj[i].push_back(i*2);
    }
    
    queue<int> q;
    q.push(n);
    vector<pair<int, int> > dist(adj.size(), make_pair(-1,0));
    dist[n].first = 0;
    dist[n].second = 1;
    while(!q.empty()) {
        int here = q.front();
        q.pop();
        
        for(int i=0; i<adj[here].size(); i++) {
            int there = adj[here][i];
            if(dist[there].first == -1) {
                dist[there].first = dist[here].first+1;
                dist[there].second++;
                q.push(there);
            } else if(dist[there].first == dist[here].first+1) {
                dist[there].second++;
                q.push(there);
            }
        }
    }
    
    printf("%d\n%d\n", dist[k].first, dist[k].second);
    return 0;
}