#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int M = 1000000000+100;
int skip;
int bino[201][201];

void solve1(int a, int b, string ret);
void calcBino();
void solve2(int a, int b, string ret);
string solve3(int a, int b, int s);
int main()
{
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        int a,b;
        int k;
        scanf("%d %d %d", &a, &b, &k);
        skip = k-1;
        calcBino();
//        solve1(a,b,"");
//        solve2(a,b,"");
        string ret = solve3(a,b,k);
        cout << ret << endl;
    }
    return 0;
}

void solve1(int a, int b, string ret)
{
    if(a == 0 && b == 0) {
        if(skip == 0) cout << ret << endl;
        --skip;
    }
    
    if(a > 0) solve1(a-1,b,ret+"-");
    if(b > 0) solve1(a,b-1,ret+"o");
}

void calcBino()
{
    memset(bino, 0, sizeof(bino));
    for(int i=0; i<=200; i++) {
        bino[i][0] = bino[i][i] = 1;
        for(int j=1; j<i; j++) {
            bino[i][j] = min(M, bino[i-1][j-1] + bino[i-1][j]);
        }
    }
}

void solve2(int a, int b, string ret)
{
    if(skip < 0) return ;
    if(a == 0 && b == 0) {
        if(skip == 0) cout << ret << endl;
        --skip;
        return ;
    }
    if(bino[a+b][a] <= skip) {
        skip -= bino[a+b][a];
        return ;
    }
    
    if(a > 0) solve2(a-1,b,ret+"-");
    if(b > 0) solve2(a,b-1,ret+"o");
}

string solve3(int a, int b, int s) {
    if(a == 0) return string(b, 'o');
    if(s < bino[a+b-1][a-1]) {
        return "-" + solve3(a-1, b, s);
    }
    return "o" + solve3(a, b-1, s-bino[a+b-1][a-1]);
}