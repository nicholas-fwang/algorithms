const int oo = 0x3f3f3f3f;
int V;

// capacity[u][v] : u에서 v로 보낼 수 있는 용량
// flow[u][v] : u에서 v로 흘러가는 유량(반대 방향인 경우 음수)
int capacity[MAX_V][MAX_V], flow[MAX_V][MAX_V];

// flow[][]를 계산하고 총 유량을 반환한다.
int networkFlow(int source, int sink) {
    // flow를 0으로 초기화한다.
    memset(flow, 0, sizeof(flow));
    int totalFlow = 0;
    while(true) {
        // 너비 우선 탐색으로 증가 경로를 찾는다.
        vector<int> parent(MAX_V, -1);
        queue<int> q;
        parent[source] = source;
        q.push(source);
        while(!q.empty() && parent[sink] == -1) {
            int here = q.front(); q.pop();
            for(int there = 0; there < V; ++there) {
                // 이 부분으로 보면 here와 there가 서로 연결되있지 않다면 -1이어야한다.
                if(capacity[here][there] - flow[here][there]>0 &&
                  parent[there] == -1) {
                    q.push(there);
                    parent[there] = here;
                }
            }
        }
    
        // 증가 경로가 없으면 종료한다.
        if(parent[sink] == -1) break;

        // 증가 경로를 통해 유량을 얼마나 보낼지 결정한다.
        int amount = oo;
        for(int p=sink; p!=source; p=parent[p]) {
            // 증가 경로에서 남아 있는 용량 중 가장 작은 용량의 간선을 찾는다.
            amount = min(capacity[parent[p]][p]-flow[parent[p]][p], amount);
        }
        // 증가 경로를 통해 유량을 보낸다.
        for(int p=sink; p!=source; p=parent[p]) {
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }
        totalFlow += amount;
    }
    return totalFlow;
}