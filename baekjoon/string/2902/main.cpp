#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    string s;
    cin >> s;
    string ret;
    for(int i=0; i<s.size(); i++) {
        if(s[i] >= 'A' && s[i] <= 'Z') {
            ret.push_back(s[i]);
        }
    }
    cout << ret << endl;
    return 0;
}