#include <iostream>
#include <cstdio>
#include <cstring>

const int oo = 0x3f3f3f3f;

using namespace std;

int map[301];
int dp[301][3];
int main()
{
    int n;
    scanf("%d", &n);
    memset(dp, 0, sizeof(dp));
    for(int i=1; i<=n; i++) {
        int tmp;
        scanf("%d", &tmp);
        map[i] = tmp;
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=2; j++) {
            dp[i][j] = dp[i-2][2] + map[i];
            if(j != 1 || i == 1) {
                dp[i][j] = max(dp[i][j], dp[i-1][1] + map[i]);
            }
        }
    }
    int ret = max(dp[n][1], dp[n][2]);
    printf("%d\n", ret);
    return 0;
}