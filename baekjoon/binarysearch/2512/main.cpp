#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int N;
long long M;
int map[10001];
long long psum[10001];
int binarySearch(int low, int high);
int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d", &map[i]);
    }
    scanf("%lld", &M);
    sort(map, map+N);
    psum[0] = map[0];
    for(int i=1; i<N; i++) {
        psum[i] = psum[i-1]+map[i];
    }
    printf("%d\n", binarySearch(0, map[N-1]));
    return 0;
}

int binarySearch(int low, int high)
{
    if(low > high) return high;
    
    int mid = (low+high)/2;
    int cnt = 0;
    while(map[cnt] < mid) cnt++;
    long long h = psum[cnt-1] + ((N-cnt)*mid);
    if(h > M) {
        return binarySearch(low, mid-1);
    } else if(h < M) {
        return binarySearch(mid+1, high);
    } else {
        return mid;
    }
}