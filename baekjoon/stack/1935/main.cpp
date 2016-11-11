#include <iostream>
#include <cstdio>
#include <string>
#include <stack>

using namespace std;

double map[26];
int main()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    stack<double> s;
    for(int i=0; i<n; i++) {
        cin >> map[i];
    }
    
    double ret = 0.0;
    double a,b;
    for(int i=0; i<str.size(); i++) {
        switch(str[i]) {
            case '*':
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                s.push(b*a);
                ret = b*a;
                break;
            case '/':
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                s.push(b/a);
                ret = b/a;
                break;
            case '+':
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                s.push(b+a);
                ret = b+a;
                break;
            case '-':
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                s.push(b-a);
                ret = b-a;
                break;
            default:
                s.push(map[str[i]-'A']);
                break;
        }
    }
    printf("%.2f", ret);
    
    return 0;
}