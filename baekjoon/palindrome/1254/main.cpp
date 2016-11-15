#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

string s;
string tmp;
bool isPal(int end);
int main()
{
    cin >> s;
    tmp = s;
    if(isPal(s.size()-1)) {
        printf("%d\n", (int)tmp.size());
        return 0;
    }
    for(int i=0; i<s.size(); i++) {
        tmp = s;
        for(int j=i; j>=0; j--) {
            tmp.push_back(s[j]);
        }
        if(isPal(s.size()+i)) {
            printf("%d\n", (int)tmp.size());
            return 0;
        }
    }
    
    return 0;
}

bool isPal(int end)
{
    int start = 0;
    while(start < end) {
        if(tmp[start] != tmp[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}