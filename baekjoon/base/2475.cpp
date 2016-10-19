#include <iostream>
#include <cstdio>

using namespace std;


int main()
{
    int ret = 0;
    for(int i=0; i<5; i++) {
        int tmp;
        scanf("%d", &tmp);
        ret += (tmp*tmp);
    }
    printf("%d\n", ret%10);
    return 0;
}