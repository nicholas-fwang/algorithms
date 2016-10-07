#include <vector>
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

/**
 * 우선순위 큐를 사용한 다익스트라 알고리즘
 * 우선순위 큐를 사용할 경우 방문하는 정점의 갯수에 비례하지 않고 간선의 수의 비례한다.
 * 즉, 방문했던 정점이라도 간선이 존재하면 큐에 집어넣기 때문에 이를 고려해야한다.
 * 시간 복잡도는 O(|E|lg|V|) 이 되는데 이를 우선순위 큐 추가, 읽는 복잡도 O(lg|E|)와
 * 간선을 모두 살펴보는 O(lg|E|)를 곱하면 된다. E < V^2인 그래프가 대부분이기 때문에 
 * lg|E|를 lg|V|로 대체했다.
 **/
int V;
// *일반 그래프 adj와 다르다*
// 그래프의 인접리스트, first는 index와 연결된 정점의 번호
// second는 그때 간선의 가중치
vector<pair<int, int> > adj[MAX_V];
vector<int> dijkstra(int src) {
    // src(시작 정점)부터 각 index 정점까지 최단거리를 저장하는 배열
    // 방문하지 않았으면 INF(oo)
    vector<int> dist(V, INF);
    // 시작 정점의 최단거리는 0
    dist[src] = 0;
    // 너비우선탐색에서의 queue가 우선순위큐로 대체된다.
    // first는 시작점부터 정점까지의 최단거리,
    // second는 그 정점의 번호
    // 우선순위 큐에서 가장 작은 값을 빼는 기준은 최단거리이기 때문에
    // 최단거리가 first가 된다.
    priority_queue<pair<int, int> > pq;
    // 시작 정점을 우선순위큐에 넣는다.
    pq.push(make_pair(0, src));
    while(!pq.empty()) {
        // 우선순위큐의 기본 설정은 maxHeap이다. 
        // 따라서 top()을 하면 최대 값을 가져오기 때문에 음수 연산을 해서 minHeap으로 바꿨다.
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        
        // 이게 좀 중요하다.
        // 우선순위 큐에는 같은 정점이 2번 들어갈 수도 있다.
        // 만약 나중에 top된 정점이 이미 이전 정점에 의해 계산된 거리보다 길면
        // 그 정점은 무시해버린다. 즉, 그 정점의 인접노드들도 방문하지 않는다가 *핵심*
        if(dist[here] < cost) continue;
        
        // 우선순위큐에서 최단 거리를 가지는 정점의 인접노드들을 방문한다.
        for(int i=0; i<adj[here].size(); i++) {
            // here의 인접노드다. 여기 first는 우선순위큐의 first가 아니다.
            // adj의 first다.
            int there = adj[here][i].first;
            // cost : here까지의 최단거리
            // adj[here][i].second : here, there을 잇는 간선의 가중치
            // 둘을 더하면 src부터 there까지의 거리를 구할 수 있다.
            int nextDist = cost + adj[here][i].second;
            
            // src, there 거리를 구한 결과가 이전에 구한 값보다 더 최단거리다.
            if(dist[there] > nextDist) {
                // dist 최신화
                dist[there] = nextDist;
                // minHeap을 위해 -연산을하고 푸쉬한다.
                // 이 연산을 하게 되면 there가 중복돼서 우선순위큐에 들어갈 수 있다.
                // 이걸 해결하는게 위에 continue다.
                pq.push(make_pair(-nextDist, there));
            }
        }
    }
    // src부터 각 index 정점까지의 최단거리를 반환한다.
    return dist;
}

