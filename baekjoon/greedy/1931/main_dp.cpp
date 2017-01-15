#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int cache[100001];
vector<pair<int, int> > adj;
int N;
int solve(int n);
int main()
{
    memset(cache, -1, sizeof(cache));
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        int begin, end;
        scanf("%d%d", &begin, &end);
        adj.push_back(make_pair(end,begin));
    }
    sort(adj.begin(), adj.end());
    printf("%d\n", solve(0));
    return 0;
}

int solve(int n)
{
    int& ret = cache[n];
    if(ret != -1) return ret;
    ret = 1;
    
    for(int i=n+1; i<N; i++) {
        if(adj[n].first <= adj[i].second) {
            return ret = solve(i)+1;
        }
    }
    return ret;
}