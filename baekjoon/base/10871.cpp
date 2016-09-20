#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    int n,x;
    scanf("%d %d", &n, &x);
    for(int i=0; i<n; i++) {
        int v;
        scanf("%d", &v);
        if(v < x) {
            printf("%d ", v);
        }
    }
    printf("\n");
    return 0;
}