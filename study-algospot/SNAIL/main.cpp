#include <iostream>
#include <cstdio>

using namespace std;

int N,M;
double cache[1002][1002];
double solve(int n, int m);
int main()
{
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        for(int i=0; i<=1001; i++) {
            for(int j=0; j<=1001; j++) {
                cache[i][j] = -1;
            }
        }
        scanf("%d %d", &N, &M);
        printf("%.10f\n", solve(0,0));
    }
    return 0;
}

double solve(int n, int m) {
    if(n >= N) return 1;
    if(m == M) {
        return n >= N ? 1 : 0;
    }
    
    double& ret = cache[n][m];
    if(ret != -1) return ret;
    return ret = 0.75*solve(n+2, m+1) + 0.25*solve(n+1, m+1);
}