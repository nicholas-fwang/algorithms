#include <cstdio>
#include <iostream>

using namespace std;

const int day[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
const string str[7] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};

int main()
{
    int m,d;
    int ret = 0;
    scanf("%d %d", &m, &d);
    for(int i=1; i<m; i++) {
        ret += day[i];
    }
    ret += d;
    cout << str[ret%7] << endl;
    return 0;
}