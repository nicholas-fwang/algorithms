#include <stdio.h>
#include <stdlib.h>

int compare(const void *arg1, const void *arg2)
{
    if(*(int *)arg1 > *(int *)arg2) return 1;
    else if(*(int *)arg1 == *(int *)arg2) return 0;
    else return -1;
}

int c[10000];
int d[10000];
int main()
{
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        int m,n;
        int i;
        scanf("%d", &m);
        scanf("%d", &n);
        for(i=0; i<n; i++) {
            scanf("%d", &c[i]);
            d[i] = c[i];
        }

        qsort(c, n, sizeof(int), compare);
        
        // sum c[minIndex] + c[maxIndex], then check the value is larger than m or smaller
        // if larger, decrease maxIndex, else increase minIndex
        int minIndex = 0, maxIndex = n-1;
        while(c[minIndex] + c[maxIndex] != m) {
            if(c[minIndex] + c[maxIndex] > m) {
                maxIndex--;
            } else {
                minIndex++;
            }
        }
        
        // find the index for selected values using original array d
        int in1=-1, in2=-1;
        for(i=0; i<n; i++) {
            if(c[minIndex] == d[i] || c[maxIndex] == d[i]) {
                if(in1 == -1) {
                    in1 = i;
                } else {
                    in2 = i;
                    break;
                }
            }
        }
        printf("%d %d\n", in1+1, in2+1);
        
    }
    return 0;
}
