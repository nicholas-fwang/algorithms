#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    string a,b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    if(atoi(a.c_str()) > atoi(b.c_str())) cout << a << endl;
    else cout << b << endl;
    return 0;
}