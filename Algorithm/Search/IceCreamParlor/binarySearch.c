/*
* It timed out
*/
#include <stdio.h>
#include <stdlib.h>

int compare(const void *arg1, const void *arg2)
{
    if(*(int *)arg1 > *(int *)arg2) return 1;
    else if(*(int *)arg1 == *(int *)arg2) return 0;
    else return -1;
}

// binary search for arr
int binarySearch(int* arr, int minIndex, int maxIndex, int value) {
    int mid = (minIndex + maxIndex) / 2;
    int solution = -1;

    // if not found
    if(minIndex == maxIndex) {
        return solution;
    }

    if(value > arr[mid]) {
        solution = binarySearch(arr, mid, maxIndex, value);
    } else if(value < arr[mid]) {
        solution = binarySearch(arr, minIndex, mid, value);
    } else {
        return arr[mid];
    }
    return solution;
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

        int v1, v2;

        // find v1 + v2 = m, using binary search,
        // if not solve, increase i then, repeat binary search
        for(i=0; i<=n/2; i++) {
            v1 = c[i];
            v2 = binarySearch(c, i+1, n-1, m-v1);
            if(v2 > -1) {
                break;
            }
        }

        // find index for selected values using original array d
        int in1=-1, in2=-1;
        for(i=0; i<n; i++) {
            if(v1 == d[i] || v2 == d[i]) {
                if(in1 == -1) {
                    in1 = i;
                } else {
                    in2 = i;
                }
            }
        }
        printf("%d %d\n", in1+1, in2+1);
    }
    return 0;
}
