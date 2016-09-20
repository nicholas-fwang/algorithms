#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>

using namespace std;

int h[100001];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &h[i]);
    }
    
    stack<int> remaining;
    h[n] = 0;
    int ret = 0;
    for(int i=0; i<=n; i++) {
        while(!remaining.empty() && h[remaining.top()] >= h[i]) {
            int j = remaining.top();
            remaining.pop();
            
            int width = -1;
            if(remaining.empty()) {
                width = i;
            } else {
                width = i - remaining.top() -1;
            }
            ret = max(ret, width*h[j]);
        }
        remaining.push(i);
    }
    printf("%d\n", ret);
    
    return 0;
}