#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;
const int c[4][3][2] = {
    { {0,0},{0,1},{1,0} },
    { {0,0},{0,1},{1,1} },
    { {0,0},{1,0},{1,1} },
    { {0,0},{1,0},{1,-1} }
};

int h,w;
string board[20];

int solve();
bool isAvailable(int row, int col, int cnt);
int main()
{
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        scanf("%d %d", &h, &w);
        for(int i=0; i<h; i++) {
            cin >> board[i];
        }
        printf("%d\n", solve());
    }
    return 0;
}

int solve()
{
    int row = -1;
    int col = -1;
    
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            if(board[i][j] == '.') {
                row = i;
                col = j;
                break;
            }
        }
        if(row != -1) break;
    }
    if(row == -1 && col == -1) return 1;
    
    int ret = 0;
    for(int i=0; i<4; i++) {
        if(isAvailable(row,col,i)) {
            for(int j=0; j<3; j++) {
                int nextRow = row+c[i][j][0];
                int nextCol = col+c[i][j][1];
                board[nextRow][nextCol] = '#';
            }
            ret += solve();
            for(int j=0; j<3; j++) {
                int nextRow = row+c[i][j][0];
                int nextCol = col+c[i][j][1];
                board[nextRow][nextCol] = '.';
            }
        }
    }
    return ret;
}

bool isAvailable(int row, int col, int cnt)
{
    for(int i=0; i<3; i++) {
        int nextRow = row + c[cnt][i][0];
        int nextCol = col + c[cnt][i][1];
        if(nextRow >= 0 && nextRow < h && nextCol >= 0 && nextCol < w &&
          board[nextRow][nextCol] == '.') {
            continue;    
        } else {
            return false;
        }
    }
    return true;
}