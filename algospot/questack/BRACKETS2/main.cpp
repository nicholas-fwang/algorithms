#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

bool isOpener(char c);
bool isProperCloser(char open, char close);

int main()
{
    int testCase;
    cin >> testCase;
    while(testCase--) {
        stack<char> bracket;
        bool result = true;
        string b;
        cin >> b;
        int len = b.length();
        
         for(int i=0; i<len; i++) {
             // open 괄호면 push한다
            if(isOpener(b[i])) {
                bracket.push(b[i]);
            } else {
                // !bracket.empty() : push된 open 괄호가 없으면 안된다
                // isProperCloser : top에 있는 open 괄호와 맞는 close 괄호인지 확인한다
                if(!bracket.empty() && isProperCloser(bracket.top(), b[i])) {
                    bracket.pop();
                } else {
                    result = false;
                    break;
                }
            }
        }
        
        // push된 open 괄호를 전부 써야 맞다
        if(!bracket.empty()) {
            result = false;
        }
        if(result) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

bool isOpener(char c)
{
    if(c == '(' || c == '{' || c == '[') {
        return true;
    }
    return false;
}

bool isProperCloser(char open, char close)
{
    switch(open) {
        case '(' :
            if(close == ')') return true;
            else return false;
        case '{' :
            if(close == '}') return true;
            else return false;
        case '[' :
            if(close == ']') return true;
            else return false;
        default :
            return false;
    }
}