#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int map[100];
int N;
int cache[100][10001];

int solve(int n, int k);

int main()
{
    int k;
    memset(cache, -1, sizeof(cache));
    scanf("%d %d", &N, &k);
    for(int i=0; i<N; i++) {
        int tmp;
        scanf("%d", &tmp);
        map[i] = tmp;
    }
    
    int ret = solve(0, k);
    
    printf("%d\n", ret);
    
    return 0;
}

int solve(int n, int k)
{   
    if(k == 0) {
        return 1;
    } else if(k < 0) {
        return 0;
    }
    if(n >= N) {
        return 0;
    }
    
    int& ret = cache[n][k];
    if(ret != -1) {
        return ret;
    }
    ret = 0;
    for(int i=0; i<=k/map[n]; i++) {
        ret += solve(n+1, k-(map[n]*i));
    }
    return ret;
}

