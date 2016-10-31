#include <iostream>
#include <cstdio>

using namespace std;

int dp[41][41];
int vip[41];
int main()
{
    int n;
    scanf("%d", &n);
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++) {
        int tmp;
        scanf("%d", &tmp);
        vip[tmp] = 1;
    }
    dp[0][0] = 0;
    dp[1][0] = 0;
    dp[1][1] = 1;
    
    for(int i=2; i<=n; i++) {
        if(vip[i] == 1 || vip[i-1] == 1) dp[i][i-1] = 0;
        else dp[i][i-1] = dp[i-1][i-1];
        
        dp[i][i] = dp[i-1][i-1] + dp[i-1][i-2];
    }
    printf("%d\n", dp[n][n]+dp[n][n-1]);
    return 0;
}