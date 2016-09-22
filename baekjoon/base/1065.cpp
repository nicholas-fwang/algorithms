#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

bool isHansu(int n)
{
    if(n < 100) return true;
    int c = n;
    int d = n%10 - (n%100)%10;
    int e = c%10;
    while(1) {
        c = c/10;
        if(e-c%10 != d) {
            return false;
        }
        if(c == 0) {
            return true;
        }
        e = c%10;
    }
    
    return true;
}

int main()
{
    int n;
    scanf("%d", &n);
    int ret = 0;
    for(int i=1; i<=n; i++) {
        if(isHansu(i)) ret++;
    }
    printf("%d\n", ret);
    return 0;
}