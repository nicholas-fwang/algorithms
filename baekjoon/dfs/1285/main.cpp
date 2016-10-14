#include <iostream>
#include <cstdio>

using namespace std;

const int oo = 0x3f3f3f3f;

int map[21][21];
int n;

int solve(int row, bool reverse);
void rev(int row);
int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        string tmp;
        cin >> tmp;
        for(int j=0; j<tmp.size(); j++) {
            if(tmp[j] == 'H') map[i][j+1] = 0;
            else map[i][j+1] = 1;
        }
    }
    int ret = min(solve(n, true), solve(n, false));
    printf("%d\n", ret);
    return 0;
}

int solve(int row, bool reverse)
{
    if(row == 0) {
        int ret = 0;
        for(int i=1; i<=n; i++) {
            int h=0;
            for(int j=1; j<=n; j++) {
                if(map[j][i] == 1) h++;
            }
            if(h > n-h) h = n-h;
            ret += h;
        }
        return ret;
    }
    int ret = oo;
    if(reverse) {
        rev(row);
        ret = min(ret, solve(row-1, true));
        ret = min(ret, solve(row-1, false));
        rev(row);
    } else {
        ret = min(ret, solve(row-1, true));
        ret = min(ret, solve(row-1, false));
    }  
    return ret;
}
void rev(int row)
{
    for(int i=1; i<=n; i++) {
        if(map[row][i] == 1) map[row][i] = 0;
        else map[row][i] = 1;
    }
}