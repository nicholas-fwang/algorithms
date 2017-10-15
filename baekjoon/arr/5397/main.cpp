#include <iostream>
#include <cstdio>
#include <string>
// #include <vector>
#include <list>

using namespace std;

string str;

int main()
{
  int testCase;
  scanf("%d", &testCase);
  for(int tc=1; tc<=testCase; tc++) {
    cin >> str;
    list<char> result;
    // vector<char>::iterator cursor = result.end();
    auto cursor = result.begin();
    for(int i=0; i<str.size(); i++) {
      switch(str[i]) {
        case '<':
        if(cursor != result.begin()) cursor--;
        break;
        case '>':
        if(cursor != result.end()) cursor++;
        break;
        case '-':
        if(cursor != result.begin()) {
          cursor--;
          cursor = result.erase(cursor);
        }
        break;
        default:
        cursor = result.insert(cursor, str[i]);
        cursor++;
        break;
      }
    }
    for(char c : result) {
      cout << c;
    }
    cout << "\n";
  }
  return 0;
}
