#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int w[1001];
int c[1001];
// cache[line][tab] : line-1 줄과 같이 탭될 수 있는 값이 tab일 때 최소 탭수
int cache[1001][161];

int solve(int line, int tab);
int main()
{
    int t;
    memset(cache, -1, sizeof(cache));
    scanf("%d", &t);
    w[0] = 0;
    for(int i=1; i<=t; i++) {
        int tmp;
        scanf("%d", &tmp);
        w[i] = tmp;
    }
    
    c[0] = 0;
    for(int i=1; i<=t; i++) {
        int tmp;
        scanf("%d", &tmp);
        c[i] = w[i]-tmp;
    }
    // 탭이 안된다는 것은 80이다 (-80 ~ 80 --> 0 ~ 160)
    int ret = solve(t, 80);
    printf("%d\n", ret);
    return 0;
}

int solve(int line, int tab)
{
    if(line == 0) {
        return 0;
    }
    
    int& ret = cache[line][tab];
    if(ret != -1) {
        return ret;
    }
    
    int d;
    if(c[line] * c[line-1] > 0) {
        d = min(abs(c[line]), abs(c[line-1])) + 80;
    } else {
        d = 80;
    }
    
    return ret = (solve(line-1, d) + abs(c[line])-(tab-80));
}