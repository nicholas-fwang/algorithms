#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int oo = 0x3f3f3f3f;

int N;
int cache[10001][10];
int choices[10001][10];
int values[10001][10];
int S[10001], O[10001];

int solve(int n, int k);
void trace(int n, int k);
int main()
{
    memset(cache, -1, sizeof(cache));
    scanf("%d", &N);
    string s,o;
    cin >> s >> o;
    for(int i=0; i<s.size(); i++) {
        S[i] = s[i]-'0';
        O[i] = o[i]-'0';
    }
    int ret = solve(0,0);
    printf("%d\n", ret);
    trace(0,0);
    return 0;
}

void trace(int n, int k)
{
    if(n == N) return ;
    if(values[n][k] == 0) {
        trace(n+1, k);
    } else {
        printf("%d %d\n", n+1, values[n][k]);
        trace(n+1, choices[n][k]);
    }
}

int solve(int n, int k)
{
    if(n == N) return 0;
    
    int& ret = cache[n][k];
    if(ret != -1) return ret;
    
    int cur = (S[n]+k)%10;
    int o = O[n];
    int left = (o-cur+10)%10;
    int right = (cur-o+10)%10;
    int leftRet = solve(n+1, (k+left)%10)+left;
    int rightRet = solve(n+1, k)+right;
    if(leftRet < rightRet) {
        // n 번째를 왼쪽으로 움직임
        choices[n][k] = (k+left)%10;
        values[n][k] = left;
        ret = leftRet;
    } else {
        // n 번째를 오른쪽으로 움직임
        choices[n][k] = k;
        values[n][k] = -right;
        ret = rightRet;
    }
    return ret;
}