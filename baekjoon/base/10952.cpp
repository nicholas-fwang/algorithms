#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int a,b;
    scanf("%d %d", &a, &b);
    while(a+b != 0) {
        printf("%d\n", a+b);
        scanf("%d %d", &a, &b);
    }
    return 0;
}