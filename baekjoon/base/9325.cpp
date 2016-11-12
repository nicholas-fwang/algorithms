#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        long long ret = 0;
        scanf("%lld", &ret);
        int n;
        scanf("%d", &n);
        while(n--) {
            int p,q;
            scanf("%d %d", &p, &q);
            ret += p*q;
        }
        printf("%lld\n", ret);
    }
    return 0;
}