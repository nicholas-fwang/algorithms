#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int oo = 0x3f3f3f3f;

int main()
{
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        int n;
        scanf("%d", &n);
        vector<pair<int,int> > coords(n);
        for(int i=0; i<n; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            coords[i] = make_pair(x,y);
        }
        sort(coords.begin(), coords.end());
        int min = oo;
        int ret = 0;
        for(int i=0; i<n; i++) {
            if(coords[i].second < min) {
                min = coords[i].second;
                ret++;
            }
        }
        printf("%d\n", ret);
    }
    return 0;
}