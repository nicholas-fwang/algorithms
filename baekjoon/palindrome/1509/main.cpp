#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int oo = 0x3f3f3f3f;

bool dp[2501][2501];
int cache[2501];
int N;
string s;
int solve(int n);

int main()
{
    cin >> s;
    N = s.size();
    for(int i=0; i<s.size(); i++) {
        dp[i][i] = true;
    }
    for(int i=0; i<s.size()-1; i++) {
        if(s[i] == s[i+1]) dp[i][i+1] = true;
    }
    for(int i=2; i<s.size(); i++) {
        for(int j=0; j<i; j++) {
            if(dp[j+1][i-1] && s[j] == s[i]) {
                dp[j][i] = true;
            }
        }
    }
    memset(cache, -1, sizeof(cache));
    printf("%d\n", solve(0));
    return 0;
}

int solve(int n) {
    if(n == N) return 0;
    
    int& ret = cache[n];
    if(ret != -1) return ret;
    ret = oo;
    for(int i=n; i<N; i++) {
        if(dp[n][i]) {
            ret = min(ret, solve(i+1)+1);
        }
    }
    return ret;
}