#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

const int oo = 0x3f3f3f3f;

int map[1001];

int compare(const void* a, const void* b);
int main()
{
    int n;
    scanf("%d", &n);
    map[0] = oo;
    for(int i=1; i<=n; i++) {
        scanf("%d", &map[i]);
    }
    qsort(map+1, n, sizeof(map[0]), compare);
    int ret = 0;
    for(int i=1; i<=n; i++) {
        ret += map[i] * (n-i+1);
    }
    printf("%d\n", ret);
    return 0;
}

int compare(const void* a, const void* b)
{
    if(*(int*)a > *(int*)b) {
        return 1;
    }  else {
        return -1;
    }
}