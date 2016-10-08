#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int ret = 0;
    int n=0;
    for(int i=1; i<=5; i++) {
        int a,b,c,d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        if(a+b+c+d > ret) {
            ret = a+b+c+d;
            n = i;
        }
    }
    printf("%d %d\n", n, ret);
    return 0;
}