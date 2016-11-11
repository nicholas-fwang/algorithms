#include <iostream>
#include <cstdio>

using namespace std;

string a;
string b;

int main()
{
    getline(cin, a);
    getline(cin, b);
    int m = b.size();
    for(int i=0; i<a.size(); i++) {
        if(a[i] == ' ') continue;
        if(a[i] - (b[i%m] - 'a') -1 < 'a') {
            a[i] = a[i] + 26 - (b[i%m]-'a') -1;
        } else {
            a[i] = a[i] - (b[i%m]-'a') -1;
        }
    }
    cout << a << endl;
    return 0;
}