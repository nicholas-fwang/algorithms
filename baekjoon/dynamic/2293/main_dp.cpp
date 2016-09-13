#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int map[100];
int dp[10001];

int main()
{
    int k, n;
    memset(dp, 0, sizeof(dp));
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++) {
        int tmp;
        scanf("%d", &tmp);
        map[i] = tmp;
    }
    dp[0] = 1;
    for(int i=0; i<n; i++) {
        for(int j=map[i]; j<=k; j++) {
            dp[j] += dp[j-map[i]];
        }
    }
    printf("%d\n", dp[k]);
    
    return 0;
}

