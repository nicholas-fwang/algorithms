#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int cache[3][1001];
bool sosu[1001];
int choices[1001];
int N;
int solve(int n, int k);
void trace(int n, vector<int>& ret);
int main()
{
    for(int i=2; i<=1000; i++) sosu[i] = true;
    for(int i=2; i<=sqrt(1000); i++) {
        if(!sosu[i]) continue;
        for(int j=i+i; j<=1000; j+=i) {
            sosu[j] = false;
        }
    }
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        bool find = false;
        memset(cache, -1, sizeof(cache));
        scanf("%d", &N);
        int ret = solve(0,0);
        if(ret == 0) printf("0\n");
        else {
            vector<int> v;
            trace(N, v);
            sort(v.begin(), v.end());
            for(int i=0; i<v.size(); i++) printf("%d ", v[i]);
            printf("\n");
        }
    }
    return 0;
}

int solve(int n, int k)
{
    if(n == 3) {
        return k==N?1:0;
    }
    int& ret = cache[n][k];
    if(ret != -1) return ret;
    ret = 0;
    int bestNext = -1;
    for(int i=2; i<=N; i++) {
        if(sosu[i] && k+i <= N && solve(n+1, k+i)) {
            ret = 1;
            choices[k+i] = k;
        }
    }
    return ret;
}

void trace(int n, vector<int>& ret)
{
    if(choices[n] == 0) {
        ret.push_back(n);
        return ;
    }
    ret.push_back(n-choices[n]);
    trace(choices[n], ret);
}