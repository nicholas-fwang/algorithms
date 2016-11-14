#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int oo = 0x3f3f3f3f;

int map[1001];
int N;
int cache[1001];
int solve(int n);
int main()
{
    scanf("%d", &N);
    memset(cache, -1, sizeof(cache));
    for(int i=0; i<N; i++) {
        scanf("%d", &map[i]);
    }
    int ret = solve(0);
    if(ret >= oo) printf("-1\n");
    else printf("%d\n", ret);
    return 0;
}

int solve(int n)
{
    if(n == N-1) return 0;
    else if(n > N-1) return oo; 
    
    int& ret = cache[n];
    if(ret != -1) return ret;
    ret = oo;
    
    for(int i=1; i<=map[n]; i++) {
        ret = min(ret, solve(n+i)+1);
    }
    return ret;
}