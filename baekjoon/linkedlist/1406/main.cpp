#include <iostream>
#include <cstdio>
#include <string>
#include <list>
#include <cstring>
#include <algorithm>

using namespace std;

string S;
int N;
list<char> l;

int main()
{
  cin >> S;
  scanf("%d", &N);
  for(int i=0; i<S.size(); i++) {
    l.push_back(S[i]);
  }
  auto it = l.end();
  for(int i=0; i<N; i++) {
    char command;
    cin >> command;
    if(command == 'P') {
      char c;
      cin >> c;
      l.insert(it, c);
    }
    if(command == 'L' && it != l.begin()) {
      it--;
    }
    if(command == 'D' && it != l.end()) {
      it++;
    }
    if(command == 'B' && it != l.begin()) {
      it--;
      it = l.erase(it);
    }
  }
  for(auto it : l) cout << it;
  // cout << endl;
}
