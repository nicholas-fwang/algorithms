#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>
#include <string>

using namespace std;

// 정점의 방문 여부를 저장
vector<int> visited;
// DAG
vector<vector<int> > adj;
// 위상정렬 결과값을 저장
vector<int> order;
// 학생 키 순서 저장
vector<pair<int, int> > student;

vector<int> topologySort();
void dfs(int here);

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    // 인접 리스트를 이용한 그래프
    adj = vector<vector<int> >(n);
    for(int i=0; i<m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        // 학생 번호를 정점으로 하는 그래프를 만든다
        adj[a-1].push_back(b-1);
    }
    visited = vector<int>(n, 0);
    
    // 위상정렬
    vector<int> ret = topologySort();
    
    for(int i=0; i<n; i++) {
        printf("%d ", ret[i]+1);
    }
    printf("\n");
    return 0;
}
vector<int> topologySort()
{
    order.clear();
    // 전체 정점을 방문한다
    for(int i=0; i<adj.size(); i++) {
        if(!visited[i]) dfs(i);
    }
    // 위상정렬은 종료순 이기 때문에 뒤집는다
    reverse(order.begin(), order.end());
    return order;
}

void dfs(int here)
{
    visited[here] = 1;
    // 인접 리스트는 간선의 존재 여부를 살펴볼 필요가 없다
    for(int i=0; i<adj[here].size(); i++) {
        int there = adj[here][i];
        if(!visited[there]) {
            dfs(there);
        }
    }
    // 재귀식이 종료될 때 정점을 저장한다
    order.push_back(here);
}