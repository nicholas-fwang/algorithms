#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int arr[26];
int main()
{
    string s;
    cin >> s;
    int n = s.size();
    for(int i=0; i<n; i++) {
        arr[s[i]-'A']++;
    }
    vector<char> ret(n);
    int start=0;
    int end=n-1;
    while(end-start > 0) {
        char c;
        bool get = false;
        for(int i=0; i<26; i++) {
            if(arr[i]>=2) {
                arr[i] -= 2;
                c = i+'A';
                get = true;
                break;
            }
        }
        if(!get) {
            printf("I'm Sorry Hansoo\n");
            return 0;
        }
        ret[start] = c;
        ret[end] = c;
        start++; end--;
    }
    // 홀수개
    if(end-start == 0) {
        char a;
        for(int i=0; i<26; i++) {
            if(arr[i] == 1) {
                a = i+'A';
                break;
            }    
        }
        ret[start] = a;
    }
    for(int i=0; i<ret.size(); i++) {
        printf("%c",ret[i]);
    }
    return 0;
}