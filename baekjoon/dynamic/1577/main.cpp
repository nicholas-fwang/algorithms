#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

long long dp[101][101];
bool ri[101][101];
bool to[101][101];

int main()
{
    int n,m;
    scanf("%d %d", &n, &m);
    int t;
    scanf("%d", &t);
    while(t--) {
        int a,b,c,d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        if(a==c) {
            to[a][max(b,d)] = true;
        } else if(b==d) {
            ri[max(a,c)][b] = true;
        }
    }
    dp[0][0] = 1;
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=m; j++) {
            if(i==0&&j==0) continue;
            if(i-1>=0 && !ri[i][j]) {
                dp[i][j] = dp[i-1][j];    
            }
            if(j-1>=0 && !to[i][j]) {
                dp[i][j] += dp[i][j-1];    
            }
        }
    }
    
    printf("%lld\n", dp[n][m]);
    return 0;
}