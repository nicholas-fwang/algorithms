#include <iostream>

#define MAX(a,b) a>b? a:b

using namespace std;

int n;
int trees[500][500];
/** for memoization*/
int cache[500][500];
/** move for panda*/
int panda[4][2] = {
    {1,0},{0,1},{-1,0},{0,-1}
};

/** recursive function */
int explorForBamboo(int row, int col);
/** return false if row or col is out of index */
bool inRange(int row, int col);

int main()
{
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> trees[i][j];
            cache[i][j] = 1;
        }
    }
    int result = 1;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            /** store the result if larger than previous value*/
            result = MAX(result, explorForBamboo(i, j));
        }
    }
    cout << result << endl;
    return 0;
}

int explorForBamboo(int row, int col)
{
    /** if coordinate was calculated , return the value */
    int& ret = cache[row][col];
    if(ret != 1) {
        return ret;
    }
    /** init value is 1*/
    ret = 1;
    
    /** recursive step moving up, down, right and left*/
    for(int i=0; i<4; i++) {
        int moveRow = panda[i][0];
        int moveCol = panda[i][1];
        if(inRange(row+moveRow, col+moveCol)) {
            if(trees[row+moveRow][col+moveCol] > trees[row][col]) {
                ret = MAX(ret, explorForBamboo(row+moveRow, col+moveCol)+1);
            }
        }
    }
    return ret;
}

bool inRange(int row, int col)
{
    if(row >= n || col >= n || row < 0 || col < 0) {
        return false;
    }
    return true;
}