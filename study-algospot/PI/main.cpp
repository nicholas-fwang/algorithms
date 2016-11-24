#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;
const int oo = 0x3f3f3f3f;

int cache[10001];
string s;
int solve(int n);
int calc(int start, int l);
int main()
{
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        memset(cache, -1, sizeof(cache));
        cin >> s;
        printf("%d\n", solve(0));
    }
    return 0;
}

int solve(int n)
{
    if(n == s.size()) {
        return 0;
    }
    
    int& ret = cache[n];
    if(ret != -1) return ret;
    ret = oo;
    
    for(int i=3; i<=5; i++) {
        if(n+i <= s.size()) {
            ret = min(ret, solve(n+i) + calc(n, i));
        }
    }
    return ret;
}

int calc(int start, int l)
{
    bool find = true;
    string m = s.substr(start, l);
    for(int i=0; i<m.size()-1; i++) {
        if(m[i] != m[i+1]) {
            find = false;
            break;
        }
    }
    if(find) return 1;
    find = true;
    
    int d = m[0] - m[1];
    for(int i=0; i<m.size()-1; i++) {
        if(m[i]-m[i+1] != d) {
            find = false;
            break;
        }
    }
    if(find && abs(d) == 1) return 2;
    find = true;
    
    for(int i=0; i<m.size(); i++) {
        if(m[i%2] != m[i]) {
            find = false;
            break;
        }
    }
    if(find) return 4;
    find = true;
    
    for(int i=0; i<m.size()-1; i++) {
        if(m[i]-m[i+1] != d) {
            find = false;
            break;
        }
    }
    if(find) return 5;
    return 10;
}