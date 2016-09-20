#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    queue<int> q;
    while(n--) {
        string command;
        cin >> command;
        int ret;
        if(command == "push") {
            int value;
            scanf("%d", &value);
            q.push(value);
            continue;
        } else if(command == "pop") {
            if(q.empty()) ret = -1;
            else {
                ret = q.front();
                q.pop();
            }
        } else if(command == "size") {
            ret = q.size();
        } else if(command == "empty") {
            ret = (q.empty() ? 1 : 0);
        } else if(command == "front") {
            if(q.empty()) ret = -1;
            else ret = q.front();
        } else if(command == "back") {
            if(q.empty()) ret = -1;
            else ret = q.back();
        }
        printf("%d\n", ret);
    }
}