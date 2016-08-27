#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int w[1001];
int c[1001];

int solve(int line, int tab);
int main()
{
    int t;
    scanf("%d", &t);
    w[0] = 0;
    for(int i=1; i<=t; i++) {
        int tmp;
        scanf("%d", &tmp);
        w[i] = tmp;
    }
    
    c[0] = 0;
    for(int i=1; i<=t; i++) {
        int tmp;
        scanf("%d", &tmp);
        c[i] = w[i]-tmp;
    }
    
    int d;
    int pre = 0;    
    int ret = 0;
    for(int i=t; i>0; i--) {
        if(c[i] * c[i-1] > 0) {
            d = min(abs(c[i]), abs(c[i-1]));
        } else {
            d = 0;
        }
        ret += abs(c[i])-pre;
        pre = d;
    }
    printf("%d\n", ret);
    return 0;
}
