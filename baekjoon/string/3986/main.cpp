#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int main()
{
    int testCase;
    scanf("%d", &testCase);
    int ret = 0;
    while(testCase--) {
        string a;
        cin >> a;
        stack<char> s;
        for(int i=0; i<a.size(); i++) {
            if(!s.empty() && s.top() == a[i]) {
                s.pop();
            } else {
                s.push(a[i]);
            }
        }
        if(s.empty()) ret++;
    }
    printf("%d\n", ret);
    return 0;
}