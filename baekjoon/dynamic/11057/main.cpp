#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int dp[1001][10];
int main()
{
    int n;
    scanf("%d", &n);
    memset(dp, 0, sizeof(dp));
    for(int i=0; i<10; i++) {
        dp[1][i] = 1;
    }
    
    for(int i=2; i<=n; i++) {
        for(int j=0; j<10; j++) {
            for(int k=0; k<=j; k++) {
                dp[i][j] += dp[i-1][k]%10007;
            }    
        }
    }
    long long ret = 0;
    for(int i=0; i<10; i++) {
        ret += dp[n][i]%10007;
    }
    printf("%lld\n", ret%10007);
    return 0;
}