#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

// DAG
vector<vector<int> > adj;
vector<string> words;
// 정점 방문 여부
vector<int> visited;
// 위상정렬된 결과
vector<int> order;

void makeGraph();
vector<int> topologySort();
void dfs(int here);

int main()
{
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        int n;
        scanf("%d", &n);
        adj.clear();
        words.clear();
        for(int i=0; i<n; i++) {
            string str;
            cin >> str;
            words.push_back(str);
        }
        
        // adj에 DAG를 만든다
        makeGraph();
        // 위상정렬된 배열을 얻는다
        vector<int> v = topologySort();
        if(v.empty()) {
            printf("INVALID HYPOTHESIS\n");
        } else {
            for(int i=0; i < v.size(); i++) {
                printf("%c", v[i]+'a');
            }
            printf("\n");
        }
    }
    return 0;
}

// 주어지는 단어들을 이용해 의존성 그래프를 만든다.
void makeGraph()
{
    adj = vector<vector<int> >(26, vector<int>(26, 0));
    for(int i=1; i<words.size(); i++) {
        int j=i-1;
        int len = min(words[i].size(), words[j].size());
        for(int k=0; k<len; k++) {
            if(words[i][k] != words[j][k]) {
                int a = words[i][k] - 'a';
                int b = words[j][k] - 'a';
                adj[b][a] = 1;
                break;
            }
        }
    }
}

// dfs
void dfs(int here)
{
    visited[here] = 1;
    for(int i=0; i<adj.size(); i++) {
        if(!visited[i] && adj[here][i] == 1) dfs(i);
    }
    order.push_back(here);
}

// 위상정렬한다
vector<int> topologySort()
{
    int n = adj.size();
    visited = vector<int>(n, 0);
    order.clear();
    for(int i=0; i<n; i++) {
        if(!visited[i]) dfs(i);
    }
    // 알파벳을 dfs하면서 먼저 종료된 순서로 나온 order를 뒤집는다
    reverse(order.begin(), order.end());
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            // 위상정렬에 모순이 되는 간선이 존재한다(사이클을 만든다)
            if(adj[order[j]][order[i]]) return vector<int>();
        }
    }
    return order;
}