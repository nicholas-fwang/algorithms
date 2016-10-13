#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int map[10001];
int dp[10001][3];

int main()
{
    int n;
    scanf("%d", &n);
    memset(dp, 0, sizeof(dp));
    for(int i=1; i<=n; i++) {
        scanf("%d", &map[i]);
    }
    dp[1][0] = 0;
    dp[1][1] = map[1];
    dp[1][2] = 0;
    
    for(int i=2; i<=n; i++) {
        for(int j=0; j<3; j++) {
            if(j==0) {
                dp[i][j] = max(dp[i-1][0], dp[i-1][1]);
                dp[i][j] = max(dp[i][j], dp[i-1][2]);
            }
            
            else {
                dp[i][j] = dp[i-1][j-1]+map[i];
            }
        }
    }
    int ret=0;
    for(int i=0; i<3; i++) {
        ret = max(ret, dp[n][i]);
    }
    printf("%d\n", ret);
    return 0;
}