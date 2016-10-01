#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int > > adj;
vector<int> discovered;
vector<pair<int, int> > isCutEdge;
vector<int> parent;
int counter =0;

void dfsAll();
int findCutEdge(int here);

int main()
{
    int v, e;
    scanf("%d %d", &v, &e);
    adj = vector<vector<int> >(v);
    discovered = vector<int>(v, -1);
    parent = vector<int>(v);
    for(int i=0; i<e; i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    dfsAll();
    
    printf("%lu\n", isCutEdge.size());
    sort(isCutEdge.begin(), isCutEdge.end());
    for(int i=0;i<isCutEdge.size();i++){
        printf("%d %d\n", isCutEdge[i].first+1, isCutEdge[i].second+1);
    }
    return 0;
}

void dfsAll()
{
    for(int i=0; i<adj.size(); i++) {
        if(discovered[i] == -1) findCutEdge(i);
    }
}

int findCutEdge(int here)
{
    discovered[here] = counter++;
    int ret = discovered[here];
    
    for(int i=0; i<adj[here].size(); i++) {
        int there = adj[here][i];
        if(discovered[there] == -1) {
            parent[there] = here;
            int subtree = findCutEdge(there);
            // vertex와는 다르게 무조건 더 작아야 한다. 간선이기 때문에
            if(subtree > discovered[here]) {
                if(here > there) isCutEdge.push_back(make_pair(there,here));
                else isCutEdge.push_back(make_pair(here,there));
            }
            ret = min(ret, subtree);
        }
        // 무향 그래프이기 때문에 부모 정점을 here 서브트리의 최소 발견 지점으로 하면 안된다.
        else if(there == parent[here]) {
            continue;
        }
        // there가 이미 발견된 상태라면 here의 서브트리 중 한 정점이 방문했다.
        else {
            ret = min(ret, discovered[there]);
        }
    }
    
    return ret;
}