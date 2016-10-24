#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;
const int oo = 0x3f3f3f3f;

int n,m;

vector<int> adj[2010];
int capacity[2010][2010];
int flow[2010][2010];
int parent[2010];
int mcmf(int source, int sink);
int main()
{
    scanf("%d %d", &n, &m);
    for(int i=0; i<n ;i++) {
        adj[0].push_back(i+2);
        adj[i+2].push_back(0);
        capacity[0][i+2] = 2;
    }
    
    int tmp, a;
    for(int i=0; i<n; i++) {
        scanf("%d", &tmp);
        for(int j=0; j<tmp; j++) {
            scanf("%d", &a);
            adj[i+2].push_back(n+1+a);
            adj[n+1+a].push_back(i+2);
            capacity[i+2][n+1+a] = 1;
        }
    }
    
    for(int i=0; i<m; i++) {
        adj[1].push_back(n+2+i);
        adj[n+2+i].push_back(1);
        capacity[n+2+i][1] = 1;
    }
    
    int ret = mcmf(0,1);
    printf("%d\n", ret);
    return 0;
}

int mcmf(int source, int sink)
{
    int totalFlow = 0;
    while(1) {
        memset(parent, -1, sizeof(parent));
        parent[source] = source;
        queue<int> q;
        q.push(source);
        while(!q.empty() && parent[sink] == -1) {
            int here = q.front();
            q.pop();
            for(int i=0; i<adj[here].size(); i++) {
                int there = adj[here][i];
                if(parent[there] == -1 && capacity[here][there]-flow[here][there] > 0) {
                    parent[there] = here;
                    q.push(there);
                }
            }
        }
        
        if(parent[sink] == -1) break;
        
        int amount = oo;
        for(int here=sink; here!=source; here=parent[here]) {
            amount = min(amount, capacity[parent[here]][here]-flow[parent[here]][here]);
        }
        for(int p=sink; p!=source; p=parent[p]) {
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }
        totalFlow += amount;
    }
    return totalFlow;
}