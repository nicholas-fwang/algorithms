#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    while(n--) {
        string s;
        cin >> s;
        char a=s[0], b=s[2];
        printf("%d\n", (a-'0') + (b-'0'));
    }
    return 0;
}