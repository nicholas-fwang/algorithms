#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int N,K;
int cache[31][31];
int solve(int n, int k);
int main()
{
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        scanf("%d %d", &K, &N);
        memset(cache, -1, sizeof(cache));
        printf("%d\n", solve(N,K));
    }
    return 0;
}

int solve(int n, int k)
{
    if(n == 0 || n == k) {
        return 1;
    }
    
    int& ret = cache[n][k];
    if(ret != -1) return ret;
    ret = 0;
    
    if(n-1>=0) ret += solve(n-1, k);
    if(n-1>=0 && k-1>=0) ret += solve(n-1, k-1);
    return ret;
}