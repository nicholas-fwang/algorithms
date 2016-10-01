#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int> > adj;
vector<int> discovered;
vector<bool> isCutVertex;
int counter = 0;

void dfsAll();
int findCutVertex(int here, bool isRoot);

int main()
{
    int v, e;
    scanf("%d %d", &v, &e);
    adj = vector<vector<int> >(v);
    discovered = vector<int>(v, -1);
    isCutVertex = vector<bool>(v, false);
    for(int i=0; i<e; i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    
    dfsAll();
    vector<int> ret;
    for(int i=0; i<v; i++) {
        if(isCutVertex[i]) ret.push_back(i);
    }
    printf("%lu\n", ret.size());
    for(int i=0; i<ret.size(); i++) {
        printf("%d ", ret[i]+1);
    }
    printf("\n");
    return 0;
}

void dfsAll()
{
    for(int i=0; i<adj.size(); i++) {
        if(discovered[i] == -1) {
            findCutVertex(i, true);
        }
    }
}

int findCutVertex(int here, bool isRoot)
{
    discovered[here] = counter++;
    int ret = discovered[here];
    int children = 0;
    for(int i=0; i<adj[here].size(); i++) {
        int there = adj[here][i];
        if(discovered[there] == -1) {
            ++children;
            int subtree = findCutVertex(there, false);
            if(!isRoot && subtree >= discovered[here]) {
                isCutVertex[here] = true;
            }
            ret = min(ret, subtree);
        }
        else {
            ret = min(ret, discovered[there]);
        }
    }
    if(isRoot) isCutVertex[here] = (children>=2);
    return ret;
}