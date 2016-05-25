#include <stdio.h>
#include <stdlib.h>

int a[100], b[100];
int main()
{
    int n, m, min=10000;
    int *arr1, *arr2;
    int i;
    scanf("%d", &n);
    arr1 = (int *) malloc(sizeof(int)*n);
    for(i=0; i<n; i++) {
        scanf("%d", &arr1[i]);
    }
    scanf("%d", &m);
    arr2 = (int *) malloc(sizeof(int)*m);
    for(i=0; i<m; i++) {
        int tmp;
        scanf("%d", &tmp);
        arr2[i] = tmp;
        if(tmp < min) {
            min = tmp;
        }
    }
    for(i=0; i<100; i++) {
        a[i] = 0;
        b[i] = 0;
    }
    
    for(i=0; i<n; i++) {
        a[arr1[i]-min]++;
    }
    
    for(i=0; i<m; i++) {
        b[arr2[i]-min]++;
    }
    
    for(i=0; i<100; i++) {
        if(a[i] != b[i]) {
            printf("%d ", i+min);
        }
    }
    
    printf("\n");
    
    free(arr1);
    free(arr2);
}