#include <iostream>
#include <cstdio>

using namespace std;

const int oo = 0x3f3f3f3f;

int n[100000];

int main()
{
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        int N, Q;
        scanf("%d %d", &N, &Q);
        for(int i=0; i<N; ++i) {
            int h;
            scanf("%d", &h);
            n[i] = h;
        }
        while(Q--) {
            int a,b;
            scanf("%d %d", &a, &b);
            int max = 0, min = oo;
            for(int i=a; i<=b; ++i) {
                if(n[i] < min) {
                    min = n[i];
                }
                if(n[i] > max) {
                    max = n[i];
                }
            }
            printf("%d\n", max-min);
        }
    }
    return 0;
}