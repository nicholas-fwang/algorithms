#include <iostream>
#include <cstdio>

using namespace std;

long long dp[70];

int main()
{
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i=4; i<=69; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4];
    }
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        int d;
        scanf("%d", &d);
        printf("%lld\n", dp[d]);
    }
    return 0;
}