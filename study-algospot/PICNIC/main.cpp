#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int friends[10][10];
int n,m;
int taken[10];
int solve();
int main()
{
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        memset(taken, -1, sizeof(taken));
        memset(friends, -1, sizeof(friends));
        scanf("%d %d", &n, &m);
        for(int i=0; i<m; i++) {
            int a,b;
            scanf("%d %d", &a, &b);
            friends[a][b] = 1;
            friends[b][a] = 1;
        }
        printf("%d\n", solve());
    }
    return 0;
}

int solve()
{
    int f = -1;
    for(int i=0; i<n; i++) {
        if(taken[i] == -1) {
            f = i;
            break;
        }
    }
    
    if(f == -1) return 1;
    
    int ret = 0;
    for(int i=f+1; i<n; i++) {
        if(taken[i] == -1 && friends[f][i] == 1) {
            taken[f] = taken[i] = 1;
            ret += solve();
            taken[f] = taken[i] = -1;
        }
    }
    return ret;
}