#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

long dp[101][11];
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
            long add = 0;
            if(j-1 >=0) {
                add += dp[i-1][j-1];
            }
            if(j+1 <= 9) {
                add += dp[i-1][j+1];
            }
            dp[i][j] = add%1000000000;
        }
    }
    long ret = 0;
    for(int i=1; i<10; i++) {
        ret += dp[n][i];
        ret %= 1000000000;
    }
    printf("%ld\n", ret);
    return 0;
}