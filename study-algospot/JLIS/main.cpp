#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const long long oo = 0x3f3f3f3f3f3f3f3f;

int N1,N2;
int cache[101][101];
int map1[101], map2[101];
int solve(int n1, int n2);
int main()
{
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        memset(cache, -1, sizeof(cache));
        scanf("%d %d", &N1, &N2);
        for(int i=0; i<N1; i++) {
            scanf("%d", &map1[i]);
        }
        for(int i=0; i<N2; i++) {
            scanf("%d", &map2[i]);
        }
        printf("%d\n", solve(-1,-1));
    }
    return 0;
}

int solve(int n1, int n2)
{
    int& ret = cache[n1+1][n2+1];
    if(ret != -1) return ret;
    ret = 0;
    long long a = (n1 == -1 ? -oo:map1[n1]);
    long long b = (n2 == -1 ? -oo:map2[n2]);
    long long maxElement = max(a,b);
    for(int i=n1+1; i<N1; i++) {
        if(maxElement < map1[i]) ret = max(ret, solve(i, n2)+1);
    }
    for(int i=n2+1; i<N2; i++) {
        if(maxElement < map2[i]) ret = max(ret, solve(n1, i)+1);
    }
    return ret;
}