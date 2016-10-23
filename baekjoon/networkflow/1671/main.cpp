#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
const int oo = 0x3f3f3f3f;

struct shark{
    int index,a,b,c;
    // index가 핵심! 같은 능력치 상어라면 인덱스가 더 큰애가 잡아먹는다.
    shark(int index_, int a_, int b_, int c_) : index(index_), a(a_), b(b_), c(c_) {
        
    }
    
    bool isEatable(shark* rhs) {
        if(a == rhs->a && b == rhs->b && c == rhs->c){
            return index>rhs->index;
        }
        else if(a >= rhs->a && b >= rhs->b && c >= rhs->c){
            return true;   
        }
        return false;
    }
};

vector<int> adj[2010];
shark* s[1000];
int capacity[2010][2010];
int flow[2010][2010];
int n;
int mcmf(int source, int sink);
int main()
{
    memset(flow, 0, sizeof(flow));
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        s[i] = new shark(i,a,b,c);
    }
    for(int i=0; i<n; i++) {
        adj[0].push_back(i+2);
        adj[i+2].push_back(0);
        capacity[0][i+2] = 2;
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i==j) continue;
            if(s[i]->isEatable(s[j])) {
                adj[i+2].push_back(n+j+2);
                adj[n+j+2].push_back(i+2);
                capacity[i+2][n+j+2] = 1;
            }
        }
    }
    for(int i=0; i<n; i++) {
        adj[1].push_back(i+n+2);
        adj[i+n+2].push_back(1);
        capacity[i+n+2][1] = 1;
    }
    int ret = mcmf(0,1);
    printf("%d\n", n-ret);
    return 0;
}


int mcmf(int source, int sink)
{
    int totalFlow = 0;
    // 무한루프가 한번 돌때마다 bfs를 통해 source에서 sink까지의 경로를 구한다
    while(1) {
        int amount = oo;
        // bfs
        queue<int> q;
        vector<int> parent(n+n+2, -1);
        // source의 부모는 자신이다.
        parent[source] = source;
        q.push(source);
        // queue가 비었고 bfs를 통해 누군가 끝점에 도달했으면 그만 돈다
        while(!q.empty() && parent[sink] == -1) {
            int here = q.front();
            q.pop();
            // 인접 리스트
            for(int i=0; i<adj[here].size(); i++) {
                int there = adj[here][i];
                // 찾은 길을 통해 유량을 흘려 보낼 수 있으면 길이 있다.
                if(capacity[here][there] - flow[here][there]>0 &&
                  parent[there] == -1) {
                    parent[there] = here;
                    q.push(there);
                }
            }
        }
        
        // 더 이상 끝으로 가는 길을 찾지 못했으면 무한루프를 끝낸다.
        if(parent[sink] == -1) break;
        
        // 찾은 길에서 각 구간에서 보낼 수 있는 유량 중 최소값을 찾는다
        for(int p=sink; p!=source; p=parent[p]) {
            amount = min(amount, capacity[parent[p]][p] - flow[parent[p]][p]);    
        }
        
        // 찾은 최소값만큼 현재 흘려보낼 수 있는 유량 flow에 더해준다.
        // 그 반대는 빼준다.
        for(int p=sink; p!=source; p=parent[p]) {
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }
        // 최대 유량값을 더해준다
        totalFlow += amount;
    }
    return totalFlow;
}