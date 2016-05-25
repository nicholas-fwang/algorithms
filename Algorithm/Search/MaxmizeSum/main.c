#include <stdio.h>
#include <stdlib.h>

int c[100000];
int main()
{
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        int n, i;
        long m;
        scanf("%d %ld", &n, &m);
        for(i=0; i<n; i++) {
            int tmp;
            scanf("%d", &tmp);
            c[i] = tmp % m;
        }
        
        
        
    }
}