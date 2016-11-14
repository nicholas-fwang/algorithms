#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int oo = 0x3f3f3f3f;

int map[16][16];
int cache[16][16][1<<16];
int solve(int start, int end, int l);
int N;
int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    memset(cache, -1, sizeof(cache));
    int ret = oo;
    for(int i=0; i<N; i++) {
        ret = min(ret, solve(i, i, 0));
    }
    printf("%d\n", ret);
    return 0;
}

int solve(int start, int end, int l) {
    if(l == (1<<N)-1 && start == end) {
        return 0;
    } else if(l == (1<<N)-1 && start != end) {
        return oo;
    }
    
    int& ret = cache[start][end][l];
    if(ret != -1) return ret;
    ret = oo;
    
    for(int i=0; i<N; i++) {
        int tmp = l;
        if(map[start][i] > 0 && ((tmp >> i)&1) == 0) {
            ret = min(ret, solve(i, end, tmp + (1<<i))+map[start][i]);
        }
    }
    return ret;
}