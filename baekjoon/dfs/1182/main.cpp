#include <iostream>
#include <cstdio>

using namespace std;

int s;
int map[21];

int solve(int n, bool inc, int value, int flag);

int main()
{
    int n;
    scanf("%d %d", &n, &s);
    for(int i=1; i<=n; i++) {
        scanf("%d", &map[i]);
    }
    int ret = solve(n, true, 0, 1);
    ret += solve(n, false, 0, 0);
    printf("%d\n", ret);
    return 0;
}

int solve(int n, bool inc, int value, int flag)
{
    if(n == 1) {
        if(flag == 0) return 0;
        if(inc) {
            return value+map[n] == s;
        } else {
            return value == s;
        }
    }
    
    int ret=0;
    if(inc) value += map[n];
    ret += solve(n-1, true, value, flag+1);
    ret += solve(n-1, false, value, flag);
    
    return ret;
}