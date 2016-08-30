#include <iostream>
#include <cstdio>
#include <cstring>

const int oo = 0x3f3f3f3f;

using namespace std;

int map[301];
int cache[301][3];

int solve(int line, int pre);

int main()
{
    int n;
    scanf("%d", &n);
    memset(cache, -1, sizeof(cache));
    for(int i=1; i<=n; i++) {
        int tmp;
        scanf("%d", &tmp);
        map[i] = tmp;
    }
    printf("%d\n", solve(n, 0));
    return 0;
}

int solve(int line, int pre)
{
    if(line == 0) {
        return 0;
    }
    if(line < 0) {
        return -oo;
    }
    
    int& ret = cache[line][pre];
    if(ret != -1) {
        return ret;
    }
    ret = 0;
    
    ret = max(ret, solve(line-2, 2) + map[line]);
    // 바로 직전에 한칸을 건넌게 아닐 경우 한칸 이동 가능
    // 다음 계단이 출발점일 경우 그 전 이동 칸 상관 없이 한칸 이동 가능
    if(pre != 1 || line == 1) {
        ret = max(ret, solve(line-1, 1) + map[line]);
    }
    return ret;
}