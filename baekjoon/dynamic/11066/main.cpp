#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int oo = 0x3f3f3f3f;

int N;
int map[501];
int psum[501];
int cache[501][501];
int solve(int left, int right);
int main()
{
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        scanf("%d", &N);
        for(int i=0; i<N; i++) scanf("%d", &map[i]);
        psum[0] = 0;
        for(int i=1; i<=N; i++) {
            psum[i] = psum[i-1] + map[i-1];
        }
        memset(cache, -1, sizeof(cache));
        printf("%d\n", solve(0,N-1));
    }
    return 0;
}

int solve(int left, int right)
{
    if(left == right) return 0;
    
    int& ret = cache[left][right];
    if(ret != -1) return ret;
    ret = oo;
    
    for(int i=left; i<right; i++) {
        ret = min(ret, solve(left, i)+solve(i+1,right)+psum[right+1]-psum[left]);
    }
    return ret;
}