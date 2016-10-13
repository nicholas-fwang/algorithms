#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int dp[1001];
int map[1001];

int main()
{
    memset(dp, 0, sizeof(dp));
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &map[i]);
    }
    
    for(int i=1; i<=n; i++) {
        dp[i] = 1;
        for(int j=1; j<i; j++) {
            if(map[i] > map[j] && dp[j]+1 > dp[i]) {
                dp[i] = dp[j]+1;
            }
        }
    }
    int ret = 0;
    for(int i=1; i<=n; i++) {
        ret = max(ret, dp[i]);
    }
    printf("%d\n", ret);
    
    return 0;
}