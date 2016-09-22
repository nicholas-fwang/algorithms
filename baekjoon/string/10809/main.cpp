#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int map[26];

int main()
{
    string s;
    cin >> s;
    memset(map, -1, sizeof(map));
    for(int i=0; i<s.size(); i++) {
        if(map[s[i]-'a'] == -1) {
            map[s[i]-'a'] = i;
        }
    }
    for(int i=0; i<26; i++) {
        printf("%d ", map[i]);
    }
    printf("\n");
    return 0;
}