#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int DIVIDE=15746;

int cache[1000001];

int solve(int n);
int main()
{
    int n;
    scanf("%d", &n);
    memset(cache, -1, sizeof(cache));
    int ret = solve(n);
    printf("%d\n", ret);
    return 0;
}

int solve(int n)
{
//    if(n==1) return 1;
//    else if(n==2) return 2;
//    else if(n<0) return 0;
//    
    if(n==0) return 1;
    else if(n<0) return 0;
    
    int& ret = cache[n];
    if(ret != -1) return ret;
    ret = (solve(n-1)%DIVIDE) + (solve(n-2)%DIVIDE);
    return ret%DIVIDE;
}