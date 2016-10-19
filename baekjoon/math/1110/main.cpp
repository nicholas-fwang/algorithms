#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int tmp = 10*(n%10)+(n%10+n/10)%10;
    int ret = 1;
    while(n != tmp) {
        tmp = 10*(tmp%10)+((tmp%10+tmp/10)%10);
        ret++;
    }
    printf("%d\n", ret);
    return 0;
}