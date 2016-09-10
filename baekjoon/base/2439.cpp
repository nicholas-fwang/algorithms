#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        int j;
        for(j=1; j<=n-i; j++) {
            printf(" ");
        }
        for(;j<=n; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}