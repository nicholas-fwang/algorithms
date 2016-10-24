#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;
const string LOW = "abcdefghijklmnopqrstuvwxyz";

bool isPal(const string& s);
char upperToLow(char c);
int main()
{
    string test;
    getline(cin, test);
    int testCase = atoi(test.c_str());
    while(testCase--) {
        string s;
        getline(cin, s);
        if(isPal(s)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

bool isPal(const string& s)
{
    int n = s.size();
    int start = 0;
    int end = n-1;
    while(end-start >= 0) {
        if(upperToLow(s[start]) != upperToLow(s[end])) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

char upperToLow(char c)
{
    if(c >= 'A' && c <= 'Z') {
        return LOW[c-'A'];
    } else {
        return c;
    }
}