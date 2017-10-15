#include <iostream>
#include <cstdio>
#include <stack>
#include <string>

using namespace std;

string S;

bool isOpen(char c)
{
  if(c == '(' || c == '{' || c == '[') return true;
  return false;
}

bool isMatched(char open, char close)
{
  if(open == '(' && close == ')') return true;
  if(open == '{' && close == '}') return true;
  if(open == '[' && close == ']') return true;
  return false;
}

int main()
{
  int testCase;
  scanf("%d", &testCase);
  for(int tc=1; tc<=testCase; tc++) {
      cin >> S;
      stack<char> st;
      bool result = true;
      for(int i=0; i<S.size(); i++) {
        if(isOpen(S[i])) {
          st.push(S[i]);
        }
        else {
          if(st.empty()) {
            result = false;
            break;
          }
          char open = st.top();
          st.pop();
          if(!isMatched(open, S[i])) {
            result = false;
            break;
          }
        }
      }
      if(!st.empty()) result = false;
      if(result) cout << "YES\n";
      else cout << "NO\n";
  }
  return 0;
}
