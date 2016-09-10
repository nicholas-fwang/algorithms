#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int> > adj;
vector<bool> visited;

void dfs(int here)
{
    cout << "DFS visits " << here << endl;
    visited[here] = true;
    for(int i=0; i<adj[here].size(); i++) {
        int there = adj[here][i];
        printf("%d %d %d\n",here, i, there);
        if(!visited[i]) {
            dfs(there);
        }
    }
}

void dfsAll()
{
    visited = vector<bool>(adj.size(), false);
    for(int i=0; i< adj.size(); i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }
}

int main()
{
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    adj.push_back(a);
    
    vector<int> b;
    b.push_back(0);
    b.push_back(2);
    b.push_back(3);
    adj.push_back(b);
    
    vector<int> c;
    c.push_back(0);
    c.push_back(1);
    c.push_back(3);
    adj.push_back(c);
    
    vector<int> d;
    adj.push_back(d);
    
    dfsAll();
    
    return 0;
}