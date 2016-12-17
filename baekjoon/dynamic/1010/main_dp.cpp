#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int dp[31][31];
int main()
{
    for(int i=0; i<=30; i++) {
        dp[i][i] = 1;
        dp[i][0] = 1;
    }
    
    for(int i=1; i<=30; i++) {
        for(int j=1; j<=i; j++) {
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
    
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        int N,K;
        scanf("%d %d", &K, &N);
        printf("%d\n", dp[N][K]);
    }
    return 0;
}