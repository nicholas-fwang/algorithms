#include <iostream>
#include <cstdio>

using namespace std;
const int oo = 0x3f3f3f3f;

int map[20][20];
int N;
int solve(int n);
void rev(int n);
int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        string s;
        cin >> s;
        for(int j=0; j<N; j++) {
            if(s[j] == 'T') map[i][j] = 1;
        }
    }
    printf("%d\n", solve(0));
    return 0;
}

int solve(int n)
{
    if(n == N) {
        int ret = 0;
        for(int i=0; i<N; i++) {
            int t=0;
            for(int j=0; j<N; j++) {
                if(map[j][i] == 1) t++;
            }
            if(N-t < t) t = N-t;
            ret += t;
        }
        return ret;
    }
    
    int ret = oo;
    rev(n);
    ret = min(ret, solve(n+1));
    rev(n);
    ret = min(ret, solve(n+1));
    return ret;
}

void rev(int n)
{
    for(int i=0; i<N; i++) {
        map[n][i] = 1-map[n][i];
    }
}