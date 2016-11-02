#include <iostream>
#include <cstring>

using namespace std;

int dp[100][99][2];

int main()
{
    
    dp[1][0][0] = 1;
    dp[1][0][1] = 1;
    
    for(int i=2; i<=100; i++) {
        for(int k=0; k<i; k++) {
            dp[i][k][0] = dp[i-1][k][1] + dp[i-1][k][0];
            dp[i][k][1] = dp[i-1][k][0];
            if(k-1>=0) dp[i][k][1] += dp[i-1][k-1][1];
        }
    }
    
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        int a,b;
        scanf("%d %d", &a, &b);
        printf("%d\n", dp[a][b][0] + dp[a][b][1]);
    }
    return 0;
}