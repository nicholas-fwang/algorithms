#include <iostream>
#include <string.h>

#define MAX(a,b) a>b ? a:b

using namespace std;

int triangle[100][100];
int cache[100][100];
int n;

/* recursive function **/
int getMaxTriangle(int row, int col);

int main()
{
    int testCase;
    cin >> testCase;
    while(testCase--) {
        memset(cache, -1, sizeof(cache));
        cin >> n;
        for(int i=0; i<n; i++) {
            for(int j=0; j<i+1; j++) {
                int tmp;
                cin >> tmp;
                triangle[i][j] = tmp;
            }
        }
        
        int maxTriangle = getMaxTriangle(0, 0);
        cout << maxTriangle << endl;
    }
    return 0;
}

int getMaxTriangle(int row, int col)
{
    if(row == n-1) {
        return triangle[row][col];
    }
    
    /* memoization **/
    int& ret = cache[row][col];
    if(ret != -1) {
        return ret;
    }
    
    int tri = triangle[row][col];
    /* select max value between row+1 and row+1, col+1**/
    ret = MAX(getMaxTriangle(row+1, col)+tri, getMaxTriangle(row+1, col+1)+tri);
    return ret;
}