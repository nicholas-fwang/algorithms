#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    scanf("%d" , &n);
    int a,b=0,c=1;
    for(int i=2; i<=n; i++) {
        a = b+c;
        b = c;
        c = a;
    }
    if(n == 0) a = 0;
    if(n == 1) a = 1;
    printf("%d\n", a);
    return 0;
}