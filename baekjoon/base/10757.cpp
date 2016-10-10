#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int a[10002],b[10002];
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    for(int i=0; i<s1.size(); i++) {
        a[i] = s1[s1.size()-1-i]-'0';
    }
    for(int i=0; i<s2.size(); i++) {
        b[i] = s2[s2.size()-1-i]-'0';
    }
    int len = (s1.size() > s2.size() ? s1.size() : s2.size());
    vector<int> ret(len+1, 0);
    int m=0;
    for(int i=0; i<ret.size(); i++) {
        ret[i] = (a[i]+b[i])%10+m;
        m = (a[i]+b[i])/10;
    }
    int i=0;
    if(ret[ret.size()-1] == 0) {
        i = ret.size()-2;
    } else {
        i = ret.size()-1;
    }
    for(; i>=0; i--) {
        printf("%d", ret[i]);
    }
    printf("\n");
    
    return 0;
}