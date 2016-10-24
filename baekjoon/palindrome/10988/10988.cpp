#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int start = 0;
    int end = s.size()-1;
    while(end-start>=0) {
        if(s[start] != s[end]) {
            printf("0\n");
            return 0;
        }
        start++;
        end--;
    }
    printf("1\n");
    return 0;
}