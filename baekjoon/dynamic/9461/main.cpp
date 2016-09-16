#include <iostream>
#include <cstdio>

using namespace std;

long long dp[101];
int main()
{
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    for(int i=6; i<=100; i++) {
        dp[i] = dp[i-1] + dp[i-5];
    }
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int p;
        scanf("%d", &p);
        printf("%lld\n", dp[p]);
    }
    return 0;
}