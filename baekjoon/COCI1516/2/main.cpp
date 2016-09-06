#include <iostream>
#include <cstdio>
#include <stdlib.h>

using namespace std;

int map[100000];

int compare(const void* a, const void* b);
int main()
{
    int n;
    long long ret = 0;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int tmp;
        scanf("%d", &tmp);
        map[i] = tmp;
        ret += tmp;
    }
    
    qsort(map, n, sizeof(map[0]), compare);
    
    for(int i=n%3; i<=n-3; i+=3) {
        ret -= map[i];
    }
    
    printf("%lld\n", ret);
    return 0;
}

int compare(const void* a, const void* b)
{
    if(*(int*)a > *(int*)b) {
        return 1;
    } else {
        return -1;
    }
}