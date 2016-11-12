#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        int n;
        int ret = 1;
        scanf("%d", &n);
        for(int i=2; i<=n; i++) {
            if(i*i <= n) ret++;
        }
        printf("%d\n", ret);
    }
    return 0;
}
