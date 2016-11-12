#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;


int main()
{
    int n;
    scanf("%d", &n);
    int ret = 0;
    if(n < 100) ret = n;
    else {
        ret = 99;
        for(int i=100; i<=n; i++) {
            if(i == 1000) continue;
            int a = i/100;
            int b = (i/10)%10;
            int c = i%10;
            if(a-b == b-c) ret++;
        }
    }
    
    printf("%d\n", ret);
    return 0;
}