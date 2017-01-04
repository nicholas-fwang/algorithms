#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int cache[1001][1001];
string s1,s2;
int solve(int c1, int c2);
int main()
{
    cin >> s1;
    cin >> s2;
    memset(cache, -1, sizeof(cache));
    printf("%d\n", solve(0,0));
}

int solve(int c1, int c2)
{
    if(c1 == s1.size() || c2 == s2.size()) {
        return 0;
    }
    
    int& ret = cache[c1][c2];
    if(ret != -1) return ret;
    ret = 0;
    
    if(s1[c1] == s2[c2]) {
        ret = max(ret, solve(c1+1, c2+1)+1);
    } else {
        ret = max(solve(c1, c2+1), solve(c1+1, c2));
    }
    
    return ret;
}
