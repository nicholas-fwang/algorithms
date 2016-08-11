#include <iostream>
#include <limits.h>
#include <string.h>

#define MAX(a,b) a>b ? a:b

using namespace std;

const int DIR[2][2] = {{0,1},{1,0}};

int board[1000][3];
int mask[1000][3];

int n, k;

// dir : 0 : 오른쪽 1 : 아래
int cover(int row, int col, int num, int dir);
int main()
{
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        for(int j=0; j<3; j++) {
            int tmp;
            cin >> tmp;
            board[i][j] = tmp;
        }
    }
    memset(mask, 0, sizeof(mask));
    
    int ret = INT_MIN;
    for(int i=0; i<n; i++) {
        for(int j=0; j<3;j ++) {
            if(j < 2) {
                ret = MAX(ret, cover(i, j, 0, 0));     
            }
            if(i < n-1) {
                ret = MAX(ret, cover(i, j, 0, 1));     
            }
        }
    }
    cout << ret << endl;
    return 0;
}

int cover(int row, int col, int num, int dir)
{
    if(num >= k) {
        return 0;
    }
    
    int ret = INT_MIN;
    
    // 도미노를 놓았다
    mask[row][col] = 1;
    mask[row+DIR[dir][0]][col+DIR[dir][1]] = 1;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<3; j++) {
            if(mask[i][j] == 1) continue;
            if(j < 2) {
                ret = MAX(ret, cover(i, j, num+1, 0) +
                                board[row][col]+board[row+DIR[dir][0]][col+DIR[dir][1]]);
            }
            
            if(n < n-1) {
                ret = MAX(ret, cover(i, j, num+1, 1) +
                                board[row][col]+board[row+DIR[dir][0]][col+DIR[dir][1]]);
            } 
        }
    }
    
    mask[row][col] = 0;
    mask[row+DIR[dir][0]][col+DIR[dir][1]] = 0;
    return ret;
}