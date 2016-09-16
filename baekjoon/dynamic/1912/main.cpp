#include <iostream>
#include <cstdio>

using namespace std;

const int oo = 0x3f3f3f3f;

int dp[100000];
int map[100000];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &map[i]);
    }
    dp[0] = map[0];
    for(int i=1; i<n; i++) {
        dp[i] = max(map[i], dp[i-1]+map[i]);
    }
    int ret = -oo;
    for(int i=0; i<n; i++) {
        ret = max(ret, dp[i]);
    }
    printf("%d\n", ret);
    return 0;
}