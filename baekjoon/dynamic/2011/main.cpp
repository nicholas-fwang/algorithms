#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int DIVIDE = 1000000;

int cache[5001];
string s;
int solve(int n);
int main()
{
    memset(cache, -1, sizeof(cache));
    cin >> s;
    int ret = solve(0)%DIVIDE;
    printf("%d\n", ret);
    return 0;
}

int solve(int n)
{
    if(n == s.size()) {
        return 1;
    }
    
    int& ret = cache[n];
    if(ret != -1) return ret;
    ret = 0;
    if(s[n] > '0') ret += solve(n+1)%DIVIDE;
    if(n+1 < s.size()) {
        int tmp = (s[n]-'0')*10 + s[n+1]-'0';
        if(tmp >= 10 && tmp <= 26) ret += solve(n+2)%DIVIDE;
    }
    return ret;
}