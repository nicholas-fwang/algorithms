#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
    
int N[500000];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &N[i]);
    }
    sort(N, N+n);
    int m;
    scanf("%d", &m);
    for(int i=0; i<m; i++) {
        int tmp;
        scanf("%d", &tmp);
        printf("%d ", binary_search(N, N+n, tmp));
    }
    printf("\n");
    return 0;
}