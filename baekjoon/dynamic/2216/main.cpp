#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>

using namespace std;

const int oo = 0x3f3f3f3f;

int a,b,c;
int cache[3001][3001];
int ar1[3001];
int ar2[3001];
int n,m;
int solve(int n1, int space);
int main()
{
    scanf("%d %d %d", &a, &b, &c);
    string s1,s2;
    cin >> s1;
    cin >> s2;
    n = s1.size();
    m = s2.size();
    memset(cache, -1, sizeof(cache));
    for(int i=0; i<n; i++) {
        ar1[i] = s1[i]-'a';
    }
    for(int i=0; i<m; i++) {
        ar2[i] = s2[i]-'a';
    }
    int ret = solve(0,0);
    printf("%d\n", ret);
    return 0;
}

int solve(int n1, int n2)
{
    if(n1 >= n && n2 < m) {
        return (m-n2)*b;
    } else if(n2 >= m && n1 < n) {
        return (n-n1)*b;
    } else if(n1 >= n && n2 >= m) {
        return 0;
    }
    
    int& ret = cache[n1][n2];
    if(ret != -1) return ret;
    ret = -oo;
    
    ret = max(ret, solve(n1+1,n2)+b);
    ret = max(ret, solve(n1,n2+1)+b);
    int v = (ar1[n1]==ar2[n2] ? a : c);
    ret = max(ret, solve(n1+1,n2+1)+v);
    return ret;
}