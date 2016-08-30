#include <iostream>
#include <cstdio>

using namespace std;

int map[301][301];

int main()
{
    int row, col;
    scanf("%d %d", &row, &col);
    for(int i=1; i<=row; i++) {
        for(int j=1; j<=col; j++) {
            int tmp;
            scanf("%d", &tmp);
            map[i][j] = tmp;
        }
    }
    
    int k;
    scanf("%d", &k);
    while(k--) {
        int a,b,c,d;
        int ret = 0;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        for(int i=a; i<=c; i++) {
            for(int j=b; j<=d; j++) {
                ret += map[i][j];
            }
        }
        printf("%d\n", ret);
    }
    return 0;
}