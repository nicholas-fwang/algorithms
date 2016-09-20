#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <cstdlib>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    stack<int> s;
    while(n--) {
        string command;
        cin >> command;
        if(command == "pop") {
            int ret;
            if(s.empty()) ret = -1;
            else {
                ret = s.top();
                s.pop();
            }
            printf("%d\n", ret);
         } else if(command == "size") {
            printf("%lu\n", s.size());
        } else if(command == "empty") {
            int ret = (s.empty() ? 1 : 0);
            printf("%d\n", ret);
        } else if(command == "top") {
            int ret = (s.empty() ? -1 : s.top());
            printf("%d\n", ret);
        } else {
            int value;
            scanf("%d", &value);
            s.push(value);
        }
    }
    return 0;
}