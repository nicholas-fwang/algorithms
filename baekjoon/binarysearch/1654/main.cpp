#include <iostream>
#include <cstdio>

using namespace std;

int k,n;
int map[10000];
int binarySearch(unsigned int low, unsigned int high, int src);
int main()
{
    scanf("%d %d", &k, &n);
    for(int i=0; i<k; i++) {
        scanf("%d", &map[i]);
    }
    int ret = binarySearch(1,(1<<31)-1, n);
    printf("%d\n", ret);
    return 0;
}

int binarySearch(unsigned int low, unsigned int high, int src)
{
    if(low > high) return high;
    
    int ret = 0;
    unsigned int mid = (low+high)/2;
    for(int i=0; i<k; i++) {
        ret += (map[i]/mid);
    }
    if(ret >= src) {
        return binarySearch(mid+1, high, src);
    } else {
        return binarySearch(low, mid-1, src);
    }
}