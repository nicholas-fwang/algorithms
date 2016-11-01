#include <iostream>
#include <cstdio>

using namespace std;
const int D = 1000000000;

int dp[1000001];

int main()
{
    int n;
    scanf("%d", &n);
    dp[0] = 1;
    for(int i=1; i<=n; i*=2) {
        for(int j=i; j<=n; j++) {
            dp[j] += dp[j-i]%D;
            dp[j] %= D;
        }
    }
    printf("%d\n", dp[n]%D);
    return 0;
}