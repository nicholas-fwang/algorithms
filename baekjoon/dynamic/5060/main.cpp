#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;
const double oo = 0x3f3f3f3f;

int map[201];
double cache[201][201], psum[201][201];
int N, C;
double cal(int i, int j, int k);
double solve(int n, int c);
int main()
{
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        memset(cache, -1, sizeof(cache));
        memset(psum, 0, sizeof(psum));
        scanf("%d%d", &N, &C);
        for(int i=0; i<N; i++) {
            scanf("%d", &map[i]);
        }
        for(int i=0; i<N; i++) {
            for(int j=i+1; j<N; j++) {
                for(int k=i+1; k<j; k++) {
                    psum[i][j] += cal(i,j,k);
                }
            }
        }
        printf("%.4lf\n", solve(0,1)/N);
    }
    return 0;
}

double cal(int i, int j, int k)
{
    return fabs(map[i] + 1.0*(map[j]-map[i])*(k-i)/(j-i) - map[k]);
}

double solve(int n, int c)
{
    if(n == N-1) return 0;
    if(c == C-1) return psum[n][N-1];
    
    double& ret = cache[n][c];
    if(ret >= -0.5) return ret;
    ret = oo;
    
    for(int i=n+1; i<N; i++) {
        ret = min(ret, solve(i, c+1) + psum[n][i]);
    }
    return ret;
}