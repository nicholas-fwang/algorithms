#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int map[20];
int dp[10001];
int main()
{
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        int n;
        memset(dp, 0, sizeof(dp));
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d", &map[i]);
        }
        int k;
        scanf("%d", &k);
        dp[0] = 1;
        for(int i=0; i<n; i++) {
            for(int j=map[i]; j<=k; j++) {
                dp[j] += dp[j-map[i]];
            }
        }
        printf("%d\n", dp[k]);
    }
    return 0;
}