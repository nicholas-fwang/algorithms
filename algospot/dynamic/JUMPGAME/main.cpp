#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

int board[100][100];
int cache[100][100];
int n;

int isAvailable(int row, int col);
bool inRange(int row, int col);

int main()
{
    int testCase;
    cin >> testCase;
    while(testCase--) {
        memset(cache, -1, sizeof(cache));
        cin >> n;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                int tmp;
                cin >> tmp;
                board[i][j] = tmp;
            }
        }
        
        bool result = isAvailable(0, 0);
        if(result == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

/* recursive function **/
int jump(int row, int col)
{
    /* base step **/
    if(!inRange(row, col)) {
        return 0;
    } else if(row == n-1 && col == n-1) {
        return 1;
    }
    
    /* memoization **/
    int &ret = cache[row][col];
    if(ret != -1) return ret;
    
    int size = board[row][col];
    /* if out of board, return 0 else return 1**/
    ret = (jump(row+size, col) || jump(row, col+size));
    return ret;
}

bool inRange(int row, int col)
{
    if(row >= n || col >= n) {
        return false;
    }
    return true;
}
