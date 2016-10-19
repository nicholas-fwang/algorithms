#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int a[100], b[100];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i=0; i<n; i++) {
        scanf("%d", &b[i]);
    }
    sort(a, a+n);
    sort(b, b+n);
    reverse(b, b+n);
    int ret = 0;
    for(int i=0; i<n; i++) {
        ret += (a[i]*b[i]);
    }
    printf("%d\n", ret);
    return 0;
}
