#include <iostream>
#include <cstdio>
#include <cstring>

int dp[10001];

int self(int n)
{
    int c = n;
    while(c > 0) {
        n += c%10;
        c = c/10;
    }
    return n;
}

int main()
{
    memset(dp, 0, sizeof(dp));
    for(int i=1; i<=10000; i++) {
        dp[self(i)]++;
    }
    for(int i=1; i<=10000; i++) {
        if(!dp[i]) printf("%d\n", i);
    }
    return 0;
}
