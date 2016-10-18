#include <iostream>
#include <cstdio>

using namespace std;

int arr[1000000];
int n,m;
int binarySearch(int low, int high, int src);
int main()
{
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    int ret = binarySearch(1,1000000000,m);
    printf("%d\n", ret);
    return 0;
}

int binarySearch(int low, int high, int src)
{
    if(low > high) {
        return high;
    }
    
    int mid = (low+high)/2;
    long long h=0;
    for(int i=0; i<n; i++) {
        h += (arr[i]-mid > 0 ? arr[i]-mid : 0);
    }
    if(h > src) {
        return binarySearch(mid+1, high, src);
    } else if(h < src) {
        return binarySearch(low, mid-1, src);
    } else {
        return mid;
    }
}