#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int dp[1001];
int map[1001];
int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        scanf("%d", &map[i]);   
    }
    dp[1] = map[1];
    int size = 1;
    int it;
    for(int i=2; i<=N; i++) {
        if(dp[size] < map[i]) {
            size++;
            dp[size] = map[i];
            continue;
        }
        it = lower_bound(dp+1, dp+size+1, map[i])-dp;
        dp[it] = map[i];
    }
    printf("%d\n", size);
}
