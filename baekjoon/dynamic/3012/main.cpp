#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const string open = "({[";
const string close = ")}]";
const int MOD = 100000;

typedef long long ll;

int N;
ll cache[201][201];
string s;
ll solve(int low, int high);
ll mod(ll a);
int main()
{
    memset(cache, -1, sizeof(cache));
    scanf("%d", &N);
    cin >> s;
    ll ret = solve(0,N-1);
    if(ret >= MOD) {
        printf("%05lld\n", ret-MOD);
    } else {
        printf("%lld\n", ret);
    }
    return 0;
}

ll solve(int low, int high)
{
    if(low > high) return 1;
    
    ll& ret = cache[low][high];
    if(ret != -1) return ret;
    ret = 0;
    
    for(int i=low+1; i<=high; i+=2) {
        for(int j=0; j<3; j++) {
            if(s[low] == open[j] || s[low] == '?') {
                if(s[i] == close[j] || s[i] == '?') {
                    ret = mod(ret + solve(low+1,i-1)*solve(i+1,high));
                }
            } 
        }
    }
    return ret;
}

ll mod(ll a)
{
    if(a>=MOD) return MOD+a%MOD;
    return a;
}