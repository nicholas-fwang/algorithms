#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int x,y,w,h;
    scanf("%d %d %d %d", &x, &y, &w, &h);
    int ret = x;
    ret = min(ret, y);
    ret = min(ret, w-x);
    ret = min(ret, h-y);
    printf("%d\n", ret);
    return 0;
}