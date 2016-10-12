/*
 * 우선순위 큐를 사용하지 않는 다익스트라
 * 우선순위 큐를 사용하지 않고, visited 배열을 이용한다.
 * 방문하지 않고, 가장 짧은 인접 정점을 구하기 위해 정점의 수만큼 반복문을 돈다.(O(|V|))
 * 정점의 인접 정점을 구하기 위해 간선만큼 반복문을 돈다.(O|E|)
 * 전체 정점을 다 도는 while문을 돈다.(O|V|)
 * 시간 복잡도는 O(V^2+E)
 */
vector<int> dijkstra(int src) {
    // src부터 index 정점까지의 최단거리를 저장한 배열
    vector<int> dist(V, INF);
    // index 정점의 방문 여부를 저장하는 배열, 방문 true, 미방문 false
    vector<bool> visited(V, false);
    // src는 최단거리 0, 방문한거로 쳐서 true
    dist[src] = 0;
    while(true) {
        int closest = INF, here;
        // 모든 정점을 돈다.
        for(int i=0; i<V; i++) {
            // dist[i] < closest : 정점 i는 이전에 최단거리 계산이 된적 있다.
            // !visited[i] : 정점 i는 방문되지 않았다.
            // 예를들면 가장 처음에 src 정점은 거리가 0이기 때문에 < closest
            // src는 방문 되지 않기 때문에 visited[i] = false
            // here는 src가 되고 src의 인접노드를 검사한다.
            if(dist[i] < closest && !visited[i]) {
                here = i;
                closest = dist[i];
            }
        }
        // 모든 정점이 다 방문됐다면 무한루프를 끝낸다.
        if(closest == INF) break;
        // here 정점 방문을 체크한다.
        visited[here] = true;
        // here 정점의 인접 정점을 찾는다.
        for(int i=0; i<adj[here].size(); i++) {
            // here 정점의 인접 정점 there
            int there = adj[here][i].first;
            // there가 방문된적 있으면 무시
            if(visited[there]) continue;
            // src부터 here까지 최단거리에 here부터 there 거리를 더한다.
            int nextDist = dist[here] + adj[here][i].second;
            // 구한 거리와 이전에 구했던 거리중 최소값을 저장한다
            dist[there] = min(dist[there], nextDist);
        }
    }
    return dist;
}