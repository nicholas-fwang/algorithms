#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int oo = 0x3f3f3f3f;

vector<vector<int> > adj;
int main()
{
    int f,s,g,u,d;
    scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
    adj = vector<vector<int> >(f+1);
    for(int i=1; i<=f; i++) {
        if(i+u <= f) adj[i].push_back(i+u);
        if(i-d >= 1) adj[i].push_back(i-d);
    }
    vector<int> dists(f+1, -1);
    
    queue<int> q;
    dists[s] = 0;
    q.push(s);
    while(!q.empty()) {
        int here = q.front();
        q.pop();
        
        for(int i=0; i<adj[here].size(); i++) {
            int there = adj[here][i];
            if(dists[there] == -1) {
                dists[there] = dists[here]+1;
                q.push(there);
            }
        }
    }
    if(dists[g] == -1) {
        printf("use the stairs\n");
    } else {
        printf("%d\n", dists[g]);   
    }
    return 0;
}