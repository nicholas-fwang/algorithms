#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
const int oo = 0x3f3f3f3f;

vector<int> adj[120];
int capacity[120][120];
int flow[120][120];
int parent[120];
int wins[13];

int n,m;
int totalFlow;
int mcmf(int source, int sink);
int main()
{
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        int canWin=0;
        totalFlow = 0;
        memset(capacity, 0, sizeof(capacity));
        memset(flow, 0, sizeof(flow));
        for(int i=0; i<120; i++) {
            adj[i].clear();
        }
        scanf("%d %d", &n, &m);
        for(int i=0; i<n; i++) {
            scanf("%d", &wins[i]);
        }
        // source ~ 경기, 경기 ~ 선수 간선을 그린다
        for(int i=0; i<m; i++) {
            int a,b;
            adj[0].push_back(i+2);
            adj[i+2].push_back(0);
            capacity[0][i+2] = 1;
            scanf("%d %d", &a, &b);
            adj[m+2+a].push_back(i+2);
            adj[m+2+b].push_back(i+2);
            adj[i+2].push_back(m+2+a);
            adj[i+2].push_back(m+2+b);
            capacity[i+2][m+2+a] = 1;
            capacity[i+2][m+2+b] = 1;
            // 0번이 경기할 수 있는 횟수를 저장한다
            if(a==0 || b==0) canWin++;
        }
        
        // 선수 ~ sink 간선을 그린다(용량은 x)
        for(int i=0; i<n; i++) {
            adj[1].push_back(m+2+i);
            adj[m+2+i].push_back(1);
        }
        
        bool find = false;
        for(int i=wins[0]; i<=wins[0]+canWin; i++) {
            // 0번이 i승까지 해도 다른 애들의 기본 승수보다 작다면 무시
            if(*max_element(wins+1,wins+n) >= i) continue;
            // 0번 선수는 i승까지 나머지는 i-1승까지 용량 설정
            for(int j=0; j<n; j++) {
                int maxWin = (j==0 ? i : i-1);
                // 용량은 maxWin에서 각 선수의 기본 승수를 빼야한다.
                capacity[m+2+j][1] = maxWin-wins[j];
            }
            // 이 용량의 경우에 최대 유량 값이 경기 수와 같다면 조건이 만족됐다는 뜻
            // 0번이 쌓을 수 있는 승수는 i까지 무조건 가능하기 때문에 이 조건만
            // 만족하면 된다.
            if(mcmf(0,1) == m) {
                printf("%d\n", i);
                find = true;
                break;
            }
        }
        // 0번이 쌓을 수 있는 승을 다 해봐도 조건을 만족하지 못했다면 우승못한다
        if(!find) printf("-1\n");
    }
    return 0;    
}

int mcmf(int source, int sink)
{
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

