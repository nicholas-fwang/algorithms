#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int map[1000];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &map[i]);
    }
    int ret = 0;
    int start = 0;
    int end = 0;
    for(int i=1; i<n; i++) {
        // 오르막길
        if(map[i-1] < map[i]) {
            end = i;
        } else {
            if(end > start) ret = max(ret, map[end]-map[start]);
            start = i;
        }
    }
    if(end == n-1) ret = max(ret, map[end]-map[start]);
    printf("%d\n", ret);
    return 0;
}