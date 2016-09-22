#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int map[26];
int main()
{
    string s;
    cin >> s;
    for(int i=0; i<s.size(); i++) {
        map[s[i]-'a']++;
    }
    for(int i=0; i<26; i++) {
        printf("%d ", map[i]);
    }
    printf("\n");
    return 0;
}