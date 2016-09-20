#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int cache[3][100001];
int map[2][100001];

int solve(int row, int prev);

int main()
{
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        int n;
        scanf("%d", &n);
        memset(cache, -1, sizeof(cache));
        for(int i=0; i<2; i++) {
            for(int j=1; j<=n; j++) {
                scanf("%d", &map[i][j]);
            }
        }
    
        int ret = solve(n, 0);
        printf("%d\n", ret);
    }
    return 0;
}

int solve(int row, int prev)
{
    if(row == 0) {
        return 0;
    }
    int& ret = cache[prev][row];
    if(ret != -1) return ret;
    ret = 0;
    for(int i=0; i<3; i++) {
        if((i&prev) == 0x0) {
            int tmp = (i == 0 ? 0 : map[i%2][row]);
            ret = max(ret, solve(row-1, i)+tmp);
        }
    }
    return ret;
}