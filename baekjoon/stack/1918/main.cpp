#include <iostream>
#include <cstdio>
#include <string>
#include <stack>

using namespace std;
const string op = "*/+-";

int prior(char c) {
    if(c=='(' || c==')') return 0;
    if(c=='+' || c=='-') return 1;
    if(c=='*' || c=='/') return 2;
    return -1;
}

int main()
{
    string str;
    cin >> str;
    stack<char> s;
    for(int i=0; i<str.size(); i++) {
        if(op.find(str[i]) != string::npos) {
            while(!s.empty() && prior(str[i]) <= prior(s.top())) {
                printf("%c", s.top());
                s.pop();
            }
            s.push(str[i]);
        } else if(str[i] == '(') {
            s.push(str[i]);
        } else if(str[i] == ')') {
            while(s.top() != '(') {
                printf("%c", s.top());
                s.pop();
            }
            s.pop();
        } else {
            printf("%c", str[i]);
        }
    }
    while(!s.empty()) {
        printf("%c", s.top());
        s.pop();
    }
    return 0;
}