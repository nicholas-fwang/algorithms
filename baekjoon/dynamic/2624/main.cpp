#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

// K번째 동전까지로 T원을 만들 수 있는 경우의 수
int dp[101][10001];
vector<pair<int, int> > coins;
int main()
{
    int T,k;
    scanf("%d", &T);
    scanf("%d", &k);
    coins = vector<pair<int, int> >(k+1);
    for(int i=1; i<=k; i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        coins[i] = make_pair(a,b);
    }
    sort(coins.begin(), coins.end());
    dp[0][0] = 1;
    // i 번째 동전
    for(int i=1; i<=k; i++) {
        // i 번째 동전의 갯수
        for(int j=0; j<=coins[i].second; j++) {
            // i번째 동전까지 사용해 z+(i번째 동전을 j개 사용)을 만드는 경우의 수
            // == i-1번째 동전을 0~j개 사용해 z를 만든 경우의 수들의 합
            for(int z=0; z<=T; z++) {
                if(z+coins[i].first*j > T) break;
                dp[i][z+coins[i].first*j] += dp[i-1][z];
            }
        }
    }
    
    printf("%d\n", dp[k][T]);
    return 0;
}