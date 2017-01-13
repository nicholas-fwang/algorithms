#include <iostream>
#include <cstdio>

using namespace std;

int N;
int dp[1001];
int main()
{
    scanf("%d", &N);
    dp[0] = true;
    dp[1] = true;
    dp[3] = true;
    dp[4] = true;
    for(int i=5; i<=N; i++) {
        dp[i] = !dp[i-4] | !dp[i-3] | !dp[i-1];
    }
    if(dp[N]) printf("SK\n");
    else printf("CY\n");
    return 0;
}