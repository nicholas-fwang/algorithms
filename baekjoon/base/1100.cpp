#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int ret = 0;
    for(int i=0; i<8; i++) {
        string s;
        cin >> s;
        for(int j=0; j<8; j++) {
            if((s[j] == 'F') && ((i%2==0&&j%2==0)||(i%2==1&&j%2==1))) ret++;
        }
    }
    printf("%d\n", ret);
}