#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <float.h>
#include <cmath>

using namespace std;

const double oo = DBL_MAX;

int main()
{
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        int n, m;
        scanf("%d %d", &n, &m);
        vector<vector<pair<int, double> > > adj(n);
        vector<double> dist(n, oo);
        for(int i=0; i<m; i++) {
            int a,b;
            double c;
            scanf("%d %d %lf", &a, &b, &c);
            // 가중치에 log를 씌워 곱을 합으로 바꾼다.
            adj[a].push_back(make_pair(b, log2(c)));
            adj[b].push_back(make_pair(a, log2(c)));
        }
        // 너비우선탐색에서의 queue가 우선순위큐로 대체된다.
        // first는 시작점부터 정점까지의 최단거리,
        // second는 그 정점의 번호
        // 우선순위 큐에서 가장 작은 값을 빼는 기준은 최단거리이기 때문에
        // 최단거리가 first가 된다.
        priority_queue<pair<double, int> > pq;
        dist[0] = 0.0;
        pq.push(make_pair(0.0, 0));
        while(!pq.empty()) {
            // 우선순위큐의 기본 설정은 maxHeap이다. 
            // 따라서 top()을 하면 최대 값을 가져오기 때문에 음수 연산을 해서 minHeap으로 바꿨다.
            int here = pq.top().second;
            double cost = -(pq.top().first);
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
                    dist[there] = nextDist;
                    // minHeap을 위해 -연산을하고 푸쉬한다.
                    // 이 연산을 하게 되면 there가 중복돼서 우선순위큐에 들어갈 수 있다.
                    // 이걸 해결하는게 위에 continue다.
                    pq.push(make_pair(-(nextDist), there));
                }
            }
        }       
        // log는 밑이 2이기 때문에 2의 dist[n-1] 제곱을 한다.
        printf("%.10lf\n", pow(2, dist[n-1]));
    }
    return 0;
}