#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int oo = 0x3f3f3f3f;

vector<vector<pair<int, int> > > adj;

int main()
{
    int testCase;
    scanf("%d", &testCase);
    for(int tc=0; tc<testCase; tc++) {
        int n,m,w;
        scanf("%d %d %d", &n, &m, &w);
        adj = vector<vector<pair<int, int> > >(n+1);
        for(int i=0; i<m; i++) {
            int s,e,t;
            scanf("%d %d %d", &s, &e, &t);
            adj[s-1].push_back(make_pair(e-1, t));
            adj[e-1].push_back(make_pair(s-1, t));
        }
        for(int i=0; i<w; i++) {
            int s,e,t;
            scanf("%d %d %d", &s, &e, &t);
            adj[s-1].push_back(make_pair(e-1, -t));
        }
        vector<int> upper(n+1, oo);
        upper[0] = 0;
        bool updated;

        for(int iter=0; iter<n; iter++) {
            updated = false;
            for(int here=0; here<n; here++) {
                for(int i=0; i<adj[here].size(); i++) {
                    int there = adj[here][i].first;
                    int cost = adj[here][i].second;
                    if(upper[there] > upper[here] + cost) {
                        upper[there] = upper[here] + cost;
                        updated = true;
                    }
                }
            }
            if(!updated) break;
        }

        if(updated) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}