#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int N;
int cache[1001];
int play(int n);
int main()
{
    memset(cache, -1, sizeof(cache));
    scanf("%d", &N);
    if(play(N) == 0) {
        printf("CY\n");
    } else {
        printf("SK\n");
    }
    return 0;
}

int play(int n)
{
    int& ret = cache[n];
    if(ret != -1) return ret;
    ret = 0;
    
    if(n-3>0 && !play(n-3)) ret = 1;
    else if(n-1>0 && !play(n-1)) ret = 1;
    return ret;
}