#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<vector<int> > adj;
double cache[51][101];
bool memo[51][101];
int N,D;
int T;
double solve(int n, int d);
int main()
{
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        int p;
        scanf("%d %d %d", &N, &D, &p);
        adj = vector<vector<int> >(N+1);
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                int n;
                scanf("%d", &n);
                if(n == 1) adj[i].push_back(j);
            }
        }
        
        int t;
        scanf("%d", &t);
        for(int i=0; i<t; i++) {
            scanf("%d", &T);
            memset(memo, false, sizeof(memo));
            printf("%.8f ", solve(p,0));
        }
        printf("\n");
    }
    return 0;
}

double solve(int n, int d)
{
    if(d == D) {
        return n == T ? 1 : 0;
    }
    
    if(memo[n][d]) return cache[n][d];
    
    memo[n][d] = true;
    cache[n][d] = 0;
    
    int p = adj[n].size();
    for(int i=0; i<p; i++) {
        int there = adj[n][i];
        cache[n][d] += (double)1/p*(solve(there, d+1));
    }
    return cache[n][d];
}