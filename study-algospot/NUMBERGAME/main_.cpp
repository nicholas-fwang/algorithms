#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int oo = 0x3f3f3f3f;

int N;
int map[51];
int cache[51][51];
int solve(int left, int right);
int main()
{
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        memset(cache, oo, sizeof(cache));
        scanf("%d", &N);
        for(int i=0; i<N; i++) {
            scanf("%d", &map[i]);
        }
        printf("%d\n", solve(0,N-1));
    }
    return 0;
}

int solve(int left, int right)
{
    if(left > right) return 0;
    
    int& ret = cache[left][right];
    if(ret != oo) return ret;
    
    ret = max(map[left]-solve(left+1, right),
             map[right]-solve(left, right-1));
    
    if(right-left >= 1) {
        ret = max(ret, -solve(left+2, right));
        ret = max(ret, -solve(left, right-2));
    }
    return ret;
}