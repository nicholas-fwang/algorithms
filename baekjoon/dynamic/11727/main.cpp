#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int DIVIDE = 10007;

int dp[1001];
int main()
{
    int n;
    scanf("%d", &n);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 3;
    for(int i=3; i<=n; i++) {
        dp[i] = (dp[i-1]%DIVIDE) + ((dp[i-2]*2)%DIVIDE);
        dp[i] = dp[i]%DIVIDE;
    }
    printf("%d\n", dp[n]);
    return 0;
}