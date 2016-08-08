#include <iostream>
#include <limits.h>
#include <string.h>

#define MIN(a,b) a>b ? b:a

using namespace std;

int op[1000000];
    
int main()
{
    int n;
    cin >> n;
    int ret = INT_MAX;
    op[1] = 0;
    op[2] = 1;
    op[3] = 1;
    
    // a[n] : n을 만드는 최소 연산 횟수
    // a[n] = MIN(a[n/3]+1, a[n/2]+1, a[n-1]+1)
    for(int i=4; i<=n; i++) {
        ret = INT_MAX;
        if(i % 3 == 0) {
            ret = MIN(ret, op[i/3]+1);
        }
        if(i % 2 == 0) {
            ret = MIN(ret, op[i/2]+1);
        }
        ret = MIN(ret, op[i-1]+1);
        op[i] = ret;
    }
    
    cout << op[n] << endl;
    return 0;
}