#include <iostream>
#include <cstdio>

using namespace std;

int dp[11];
int main()
{
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i=4; i<11; i++) {
        dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
    }
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", dp[n]);
    }
    return 0;
}