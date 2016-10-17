#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
const int parent[7] = {1,2,4,8,16,32,64};

int binarySearch(int low, int high, int src);

int main()
{
    int n;
    int ret = 0;
    scanf("%d", &n);
    while(n > 0) {
        n -= binarySearch(0, 6, n);
        ret++;
    }
    printf("%d\n", ret);
    return 0;
}

int binarySearch(int low, int high, int src)
{
    if(low > high) {
        return parent[high];
    }
    
    int mid = (low+high)/2;
    if(src > parent[mid]) {
        return binarySearch(mid+1, high, src);
    } else if(src < parent[mid]) {
        return binarySearch(low, mid-1, src);
    } else {
        return parent[mid];
    }
}