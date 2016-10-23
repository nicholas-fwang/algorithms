#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int oo = 0x3f3f3f3f;

// 인접 리스트 그래프
vector<int> adj[402];
// 그래프의 용량을 저장한다
// capacity[u][v] : u에서 v로 갈 수 있는 최대 유량
int capacity[410][410];
// flow[u][v] : 현재 u에서 v로 보낸 유량
int flow[410][410];

// n : 소의 수 , m : 축사의 수
int n,m;
// 네트워크 유량 최대 유량값을 반환한다.
int mcmf(int source, int sink);
int main()
{
    scanf("%d %d", &n, &m);
    
    // source(시작점)의 정점 번호는 0
    // sink(끝점)의 정점 번호는 1 로 설정 한다
    
    for(int i=0; i<n; i++) {
        // source에서 각 소에게 가는 간선을 그린다
        // source가 0, sink가 1이기 때문에 2부터 시작한다
        adj[0].push_back(i+2);
        adj[i+2].push_back(0);
        // 시작점에서 소까지 갈 수 있는 유량은 1이다.
        capacity[0][i+2] = 1;
    }
    
    // 소에서 축사까지 가는 그래프를 만든다
    for(int i=0; i<n; i++) {
        int t;
        scanf("%d", &t);
        for(int j=0; j<t; j++) {
            // i+2번째 소가 갈 수 있는 축사
            int place;
            scanf("%d", &place);
            // 2~n+1까지는 소의 정점번호다 그래서 축사는 n+2부터 시작한다.
            adj[i+2].push_back(place+n+1);
            adj[place+n+1].push_back(i+2);
            // i+2번째 소가 place+n+1 축사까지 가는 유량은 1이다.(사실 oo)
            capacity[i+2][place+n+1] = 1;
        }
    }
    
    // 축사에서 끝점으로 가는 그래프를 만든다
    for(int i=0; i<m; i++) {
        // 끝점 정점번호는 1이다.
        adj[i+n+2].push_back(1);
        adj[1].push_back(i+n+2);
        // i+n+2번째 축사에서 끝점으로 가는 유량은 1이다.(사실 oo)
        capacity[i+n+2][1] = 1;
    }
    // 포드-풀커슨 알고리즘
    int ret = mcmf(0,1);
    printf("%d\n", ret);
    
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
        vector<int> parent(n+m+2, -1);
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