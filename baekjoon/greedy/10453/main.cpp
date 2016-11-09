#include <iostream>
#include <cstdio>

using namespace std;

void swap(char& q, char& w);
int main()
{
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        string a,b;
        cin >> a >> b;
        int ret = 0;
        for(int i=0; i<a.size(); i++) {
            if(a[i] != b[i]) {
                for(int j=i+1; j<a.size(); j++) {
                    if(a[j] == b[i]) {
                        swap(a[i],a[j]);
                        ret += j-i;
                        break;
                    }
                }
            }
        }
        if(a != b) printf("-1\n");
        else printf("%d\n", ret);
    }
    return 0;
}

void swap(char& q, char& w)
{
    char tmp = q;
    q = w;
    w = tmp;
}