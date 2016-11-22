#include <iostream>
#include <cstdio>

using namespace std;

bool map[11];
int N;
int possible(int n);
int main()
{
    int o;
    scanf("%d", &o);
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        int tmp;
        scanf("%d", &tmp);
        map[tmp] = true;
    }
    
    int ret = abs(o-100);
    for(int i=0; i<=1000000; i++) {
        int p = possible(i);
        if(p >= 1) {
            ret = min(ret, abs(o-i)+p);
        }
    }
    printf("%d\n", ret);
    return 0;
}

int possible(int n)
{
    int ret = 0;
    if(n == 0) return map[0] ? 0:1;
    while(n > 0) {
        ret++;
        if(map[n%10]) return 0;
        n /= 10;
    }
    return ret;
}