#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int arr[10001];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int a;
        scanf("%d", &a);
        arr[a]++;
    }
    for(int i=1; i<10001; i++) {
        for(int j=0; j<arr[i]; j++) {
            printf("%d\n", i);
        }
    }
    return 0;
}