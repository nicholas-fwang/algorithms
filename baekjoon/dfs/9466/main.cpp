#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int adj[100001];
int n;
int discovered[100001];
int finished[100001];
int cnt;

void dfsAll();
void dfs(int here);
int main()
{
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        scanf("%d", &n);
        cnt=0;
        memset(discovered, -1, sizeof(discovered));
        memset(finished, -1, sizeof(finished));
        for(int i=1; i<=n; i++) {
            scanf("%d", &adj[i]);
        }
        dfsAll();
    
        printf("%d\n", n-cnt);    
        
    }
    return 0;
}

void dfsAll()
{
    for(int i=1; i<=n; i++) {
        if(discovered[i] == -1) {
            dfs(i);
        }
    }
}

void dfs(int here)
{
    discovered[here] = 1;
    int there = adj[here];
    
    if(discovered[there] == -1) dfs(there);
    else {
        if(finished[there] == -1) {
            for(int i=there; i!=here; i=adj[i]) {
                cnt++;
            }
            cnt++;
        }
    }
    finished[here] = 1;
}