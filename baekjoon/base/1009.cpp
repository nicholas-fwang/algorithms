#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        int a,b;
        scanf("%d %d", &a, &b);
        int v = a;
        for(int i=0; i<b-1; i++) {
            v = (v*a)%10;
        }
        if(v == 0) printf("10\n");
        else printf("%d\n", v);
    }
}