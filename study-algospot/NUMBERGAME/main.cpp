#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int oo = 0x3f3f3f3f;

int cache[2][51][51];
int map[51];
int N;
int solve(int n, int left, int right);
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
        printf("%d\n", solve(0,0,N-1));
    }
    return 0;
}

int solve(int n, int left, int right)
{
    if(left > right) return 0;
    
    int& ret = cache[n][left][right];
    if(ret != oo) return ret;
    
    if(right - left >= 1) {
        ret = max(solve(1-n, left+2, right), solve(1-n, left, right-2));
    }
    // 현우
    if(n == 0) {
        ret = max(solve(1-n, left+1, right)+map[left], solve(1-n, left, right-1)+map[right]);
    } else {
        ret = max(solve(1-n, left+1, right)-map[left], solve(1-n, left, right-1)-map[right]);
    }
    return ret;
}