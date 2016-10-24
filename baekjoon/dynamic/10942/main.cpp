#include <iostream>
#include <cstdio>

using namespace std;

int arr[2000];
int pal[2000][2000];

int isPal(int start, int end);
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            if(i==j) {
                pal[i][i] = 1;
                continue;
            }
            pal[i][j] = isPal(i,j);
        }
    }
    
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        int a,b;
        scanf("%d %d", &a, &b);
        printf("%d\n", pal[a-1][b-1]);
    }
    return 0;
}

int isPal(int start, int end)
{
    while(end-start >= 2) {
        if(arr[start] != arr[end]) {
            return 0;
        }
        end--;
        start++;
    }
    if(arr[start] != arr[end]) return 0;
    return 1;
}