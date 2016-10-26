#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <numeric>

using namespace std;
const int oo = 0x3f3f3f3f;

vector<int> adj[210];
int parent[210];
int capacity[210][210];
int flow[210][210];
int profit[100];
int cost[100];
int n,m;
int mcmf(int source, int sink);
int main()
{
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        memset(capacity, 0, sizeof(capacity));
        memset(flow, 0, sizeof(flow));
        scanf("%d %d", &n, &m);
        for(int i=0; i<n; i++) {
            scanf("%d", &profit[i]);
        }
        for(int i=0; i<m; i++) {
            scanf("%d", &cost[i]);
        }
        
        // source ~ 국책사업
        for(int i=0; i<n; i++) {
            adj[0].push_back(i+2);
            adj[i+2].push_back(0);
            capacity[0][i+2] = profit[i];
        }
        
        // 국책사업 ~ 장비
        int a;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                scanf("%d", &a);
                if(a==1) {
                    adj[i+2].push_back(j+n+2);
                    adj[j+n+2].push_back(i+2);
                    capacity[i+2][j+n+2] = oo;
                }
            }
        }
        
        // 장비 ~ sink
        for(int i=0; i<m; i++) {
            adj[i+n+2].push_back(1);
            adj[1].push_back(i+n+2);
            capacity[i+n+2][1] = cost[i];
        }
        
        // 최소 컷은 최대유량과 용량이 같을 때 S,T 집합이다.
        // 따라서 최대유량을 구한 값은 용량의 최소컷이고 식에 의해 이 둘을 빼면 답이다.
        int M = accumulate(profit, profit+n, 0);
        int C = mcmf(0,1);
        printf("%d\n", M-C);
    }
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
        for(int i=sink; i!=source; i=parent[i]) {
            amount = min(amount, capacity[parent[i]][i]-flow[parent[i]][i]);
        }
        for(int i=sink; i!=source; i=parent[i]) {
            flow[parent[i]][i] += amount;
            flow[i][parent[i]] -= amount;
        }
        totalFlow += amount;
    }
    return totalFlow;
}