#include <iostream>
#include <cstdio>

using namespace std;
const int DI = 1000000007;

int main()
{
    int testCase;
    scanf("%d", &testCase);
    int dp[101];
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2; i<=100; i++) {
        dp[i] = dp[i-1]%DI + dp[i-2]%DI;
        dp[i] = dp[i]%DI;
    }
    while(testCase--) {
        int n;
        scanf("%d", &n);
        int ret = 0;
        if(n%2 == 1) {
            ret = (dp[n] - dp[n/2] + DI)%DI;
        } else {
            ret = (dp[n] - dp[n/2] + DI)%DI;
            ret = (ret - dp[n/2-1] + DI) %DI;
        }
        printf("%d\n", ret);
    }
    return 0;
}