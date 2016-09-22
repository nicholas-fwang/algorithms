#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

const int oo = 0x3f3f3f3f;

int h[500001];
int ret[500001];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &h[i]);
    }
    stack<int> remaining;
    h[n] = oo;
    for(int i=0; i<=n; i++) {
        while(!remaining.empty() && h[remaining.top()] < h[i]) {
            int j = remaining.top();
            remaining.pop();
            if(remaining.empty()) {
                ret[j] = -1;
            } else {
                ret[j] = remaining.top();
            }
        }
        remaining.push(i);
    }
    for(int i=0; i<n; i++) {
        printf("%d ", ret[i]+1);
    }
    printf("\n");
    return 0;
}