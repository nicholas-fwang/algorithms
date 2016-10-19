#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int divide = 9901;

int cache[100001][3];

int solve(int n, int prev);
int main()
{
    int n;
    scanf("%d", &n);
    memset(cache, -1, sizeof(cache));
    int ret = solve(n,0);
    printf("%d\n", ret%divide);
    return 0;
}

int solve(int n, int prev)
{
    if(n == 0) return 1;
    
    int& ret = cache[n][prev];
    if(ret != -1) return ret;
    ret = 0;
    if(prev == 0) {
        ret += solve(n-1, 1)%divide + solve(n-1, 2)%divide + solve(n-1, 0)%divide;
    } else if(prev == 1) {
        ret += solve(n-1, 0)%divide + solve(n-1, 2)%divide;
    } else {
        ret += solve(n-1, 0)%divide + solve(n-1, 1)%divide;
    }
    return ret%divide;
}