#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

const int oo = 0x3f3f3f3f;
const int START = 401;

vector<vector<pair<int, int> > > adj;

vector<int> dijk(int src);
int vertex(int delta);

int main()
{
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        int e;
        scanf("%d", &e);
        adj = vector<vector<pair<int, int> > >(402);
        vector<int> a(e), b(e);
        for(int i=0; i<e; i++) {
            int tmp1,tmp2;
            scanf("%d %d", &tmp1, &tmp2);
            int delta = tmp1 - tmp2;
            a[i] = tmp1;
            b[i] = tmp2;
            // 시작 정점과 연결되는 정점을 만들어준다. 정점 번호는 같은 종목 시간의 차 + 200,
            // 간선은 a가 i 종목에 걸린시간
            adj[START].push_back(make_pair(vertex(delta), tmp1));
        }
        for(int v=-200; v<=200; v++) {
            // 각 정점마다 올 수 있는 정점을 다 붙여준다.
            for(int i=0; i<e; i++) {
                int next = v + a[i] - b[i];
                // 절대값이 200이 넘는다는건 0으로 돌아올 수 없는 길을 걷넜다는것
                if(abs(next) > 200) continue;
                // 시작점을 제외한 나머지에 정점 붙여주기
                adj[vertex(v)].push_back(make_pair(vertex(next), a[i]));
            }
        }
        // 시작점으로 다익스트라
        vector<int> dists = dijk(START);
        // 0+200 이 종목 차가 0이 되는 정점이다.
        int ret = dists[vertex(0)];
        // 종점에 도달하지 못한다
        if(ret == oo) {
            printf("IMPOSSIBLE\n");
        } else {
            printf("%d\n", ret);   
        }
    }
    return 0;
}

vector<int> dijk(int src)
{
    int n = adj.size();
    vector<int> dists(n, oo);
    dists[src] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, src));
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if(cost > dists[here]) continue;
        
        for(int i=0; i<adj[here].size(); i++) {
            int there = adj[here][i].first;
            int distNext = cost + adj[here][i].second;
            if(dists[there] > distNext) {
                dists[there] = distNext;
                pq.push(make_pair(-distNext, there));
            }
        }
    }
    return dists;
}

int vertex(int delta)
{
    return delta+200;
}