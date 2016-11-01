#include <iostream>
#include <cstring>

using namespace std;
const int D = 1000000000;

long long dp[1000001];
int main()
{
    int n;
    scanf("%d", &n);
    dp[1] = 0;
    dp[2] = 1;
    for(int i=3;i<=n; i++) {
        dp[i] = ((i-1)*(dp[i-1]%D+dp[i-2]%D))%D;
        dp[i] %= D;
    }
    printf("%lld\n", dp[n]);
    return 0;
}