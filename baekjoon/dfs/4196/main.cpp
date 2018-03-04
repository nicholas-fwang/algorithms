#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
#include <cstring>

using namespace std;

vector<vector<int> > adj;
int scc[100001];
int disc[100001];
int in[100001];
stack<int> st;
int ret;
int connect = 0;
int sccNum;
int N,M;

int dfs(int here) {
    disc[here] = ++connect;
    st.push(here);
    int ret = disc[here];
    for(int i=0; i<adj[here].size(); i++) {
        int there = adj[here][i];
        if(!disc[there]) {
            ret = min(ret, dfs(there));
        }
        else if(!scc[there]) {
            ret = min(ret, disc[there]);
        }
    }
    if(ret == disc[here]) {
        sccNum++;
        while(1) {
            int v = st.top();
            st.pop();
            scc[v] = sccNum;
            if(v == here) break;
        }
    }
    return ret;
}

int main()
{
    int testCase;
    scanf("%d", &testCase);
    for(int tc=1 ;tc<=testCase; tc++) {
        scanf("%d %d", &N, &M);
        memset(disc, 0, sizeof(disc));
        memset(scc, 0, sizeof(scc));
        memset(in, 0, sizeof(in));
        adj.clear();
        adj.resize(N+1);
        ret = 0;
        connect = 0;
        sccNum = 0;
        for(int i=0; i<M; i++) {
            int t1,t2;
            scanf("%d %d", &t1, &t2);
            adj[t1].push_back(t2);
        }
        for(int i=1; i<=N; i++) {
            if(!disc[i]) {
                dfs(i);
            }
        }
        for(int here=1; here<=N; here++) {
            for(int j=0; j<adj[here].size(); j++) {
                int there = adj[here][j];
                if(scc[here] == scc[there]) continue;
                in[scc[there]]++;
            }
        }
        for(int i=1; i<=sccNum; i++) {
            if(in[i] == 0) {
                ret++;
            }
        }
        printf("%d\n", ret);
    }
    return 0;
}