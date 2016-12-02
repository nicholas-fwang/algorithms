#include <iostream>
#include <cstdio>

using namespace std;

int N;
long long map[100001];
long long solve(int left, int right);
int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%lld", &map[i]);
    printf("%lld\n", solve(0,N-1));
    return 0;
}

long long solve(int left, int right)
{
    if(left == right) return map[right]*map[right];
    
    int mid = (left+right)/2;
    long long ret = max(solve(left, mid), solve(mid+1, right));
    
    int lo = mid;
    int hi = mid+1;
    long long height = min(map[lo],map[hi]);
    long long width = map[lo]+map[hi];
    ret = max(ret, height*width);
    while(left < lo || hi < right) {
        if(hi < right && (left == lo || map[lo-1]<map[hi+1])) {
            ++hi;
            height = min(height, map[hi]);
            width += map[hi];
        } else {
            --lo;
            height = min(height, map[lo]);
            width += map[lo];
        }
        ret = max(ret, height*width);
    }
    return ret;
}