#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int dp[1002][1002];
int map[1002][1002];
int main()
{
    int n,m;
    memset(dp, 0, sizeof(dp));
    memset(map, 0, sizeof(map));
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    
    dp[1][1] = map[1][1];
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1])+map[i][j];
        }
    }
    
    printf("%d\n", dp[n][m]);
    
    return 0;
}