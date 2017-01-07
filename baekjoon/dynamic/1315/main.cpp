#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int N;
int cache[1001][1001];
int psum[1001][1001], qsum[1001][1001];
int solve(int st, int in);
int main()
{
    memset(cache, -1, sizeof(cache));
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        int a,b,c;
        scanf("%d%d%d", &a, &b, &c);
        
        for(int j=a; j<=1000; j++) {
            for(int k=1; k<=1000; k++) {
                psum[j][k]+=c;
                qsum[j][k]++;
            }
        }
        
        for(int j=1; j<=1000; j++) {
            for(int k=b; k<=1000; k++) {
                psum[j][k]+=c;
                qsum[j][k]++;
            }
        }
        
        for(int j=a; j<=1000; j++) {
            for(int k=b; k<=1000; k++) {
                psum[j][k]-=c;
                qsum[j][k]--;
            }
        }
    }
    
    printf("%d\n", solve(1,1));
    return 0;
}

int solve(int st, int in)
{
    int& ret = cache[st][in];
    if(ret != -1) return ret;
    ret = qsum[st][in];
    
    int cptr = psum[st][in]-st-in+2;
    for(int i=0; i<=cptr; i++) {
        int cstr = min(1000, st+i);
        int cint = min(1000, in+cptr-i);
        if(qsum[cstr][cint] == qsum[st][in]) continue;
//        ret = max(ret, solve(cstr, cint)+qsum[cstr][cint]-qsum[st][in]);
        ret = max(ret, solve(cstr, cint));
    }
    return ret;
}