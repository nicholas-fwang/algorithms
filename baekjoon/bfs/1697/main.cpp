#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;
int const oo = 0x3f3f3f3f;

vector<vector<int> > adj;

int main()
{
    int n,o;
    scanf("%d %d", &n, &o);
    
    adj = vector<vector<int> >((n>o?n+2:o+2));
    
    for(int i=0; i<adj.size(); i++) {
        if(i-1 >= 0) adj[i].push_back(i-1);
        if(i+1 < adj.size()) adj[i].push_back(i+1);
        if(i*2 < adj.size()) adj[i].push_back(i*2);
    }
    vector<int> dist(adj.size(), -1);
    queue<int> q;
    dist[n] = 0;
    q.push(n);
    while(!q.empty()) {
        int here = q.front();
        q.pop();
        
        for(int i=0; i<adj[here].size(); i++) {
            int there = adj[here][i];
            if(dist[there] == -1) {
                dist[there] = dist[here] + 1;
                q.push(there);
            }
        }   
    }
    printf("%d\n", dist[o]);
    
    return 0;
}