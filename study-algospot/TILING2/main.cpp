#include <iostream>
#include <cstdio>

using namespace std;
const int DI = 1000000007;

int main()
{
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        int n;
        int dp[101];
        scanf("%d", &n);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<=n; i++) {
            dp[i] = dp[i-1]%DI + dp[i-2]%DI;
            dp[i] = dp[i]%DI;
        }
        printf("%d\n", dp[n]%DI);
    }
    return 0;
}