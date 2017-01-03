#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int N;
int map[501];
int cache[501];
int solve(int n);
int main()
{
    memset(cache, -1, sizeof(cache));
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        int a,b;
        scanf("%d%d", &a, &b);
        map[a] = b;
    }
    printf("%d\n", N-solve(0));
    return 0;
}

int solve(int n)
{   
    int& ret = cache[n];
    if(ret != -1) return ret;
    ret = 0;
    
    for(int i=n+1; i<=500; i++) {
        if(map[n] < map[i]) ret = max(ret, solve(i)+1);
    }
    return ret;
}