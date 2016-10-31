#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int visited[20000];
vector<vector<int > > adj;

bool bfs(int start);
int main()
{
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        memset(visited, -1, sizeof(visited));
        adj.clear();
        int v,e;
        scanf("%d %d", &v, &e);
        adj = vector<vector<int> >(v);
        for(int i=0; i<e; i++) {
            int a,b;
            scanf("%d %d", &a, &b);
            adj[a-1].push_back(b-1);
            adj[b-1].push_back(a-1);
        }
        bool bip = true;
        for(int i=0; i<v; i++) {
            if(visited[i] == -1) {
                if(!bfs(i)) {
                    bip = false;
                    break;
                }
            }
        }
        
       
        
        if(bip) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
bool bfs(int start)
{
    visited[start] = 0;
    queue<int> q;
    q.push(start);
    while(!q.empty()) {
        int here = q.front();
        q.pop();
        for(int i=0; i<adj[here].size(); i++) {
            int there = adj[here][i];
            if(visited[there] == -1) {
                q.push(there);  
                visited[there] = 1-visited[here];
            } else if(visited[there] == visited[here]) {
                return false;
                break;
            }
        }
    }
    return true;
}