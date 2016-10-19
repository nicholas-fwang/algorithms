#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;
const int oo = 0x3f3f3f3f;

int cache[100001];

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
    if(n == 0) {
        return 0;
    }
    if(n < 0) return oo;
    int& ret = cache[n];
    if(ret != -1) return ret;
    ret = oo;
    for(int i=sqrt(n); i>=1; i--) {
        ret = min(ret, solve(n-(i*i))+1);
    }
    return ret;
}