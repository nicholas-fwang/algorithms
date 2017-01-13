#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int cache[1001];
int N;
int play(int n);
int main()
{
    memset(cache, -1, sizeof(cache));
    scanf("%d", &N);
    if(play(N) == 0) {
        printf("SK\n");
    } else {
        printf("CY\n");
    }
    return 0;
}

int play(int n)
{
    int& ret = cache[n];
    if(ret != -1) return ret;
    ret = 0;
    if(n-3 > 0) {
        if(!play(n-3)) {
            ret = 1;
        }
    } else if(n-1 > 0) {
        if(!play(n-1)) {
            ret = 1;
        }
    }
    return ret;
}