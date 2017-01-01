#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int map[40001], dp[40001];
int solve(int n);
int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        scanf("%d", &map[i]);
    }
    int size=1, it;
    dp[1] = map[1];
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
    
    return 0;
}