#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int map[10001];
int dp[10001];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        int tmp;
        scanf("%d", &tmp);
        map[i] = tmp;
    }
    
    dp[1] = map[1];
    for(int i=2; i<=n; i++) {
        int ret = 0;
        for(int j=1; j<=i; j++) {
            ret = max(ret, dp[i-j]+map[j]);
        }
        dp[i] = ret;
    }
    printf("%d\n", dp[n]);
    return 0;
}