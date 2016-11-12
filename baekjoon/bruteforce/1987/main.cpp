#include <iostream>
#include <cstdio>

using namespace std;
const int dx[4] = {0,0,1,-1};
const int dy[4] = {1,-1,0,0};

int r,c;
string board[20];
bool alphbet[26];
bool inRange(int row, int col);
int solve(int row, int col);
int main()
{
    scanf("%d %d", &r, &c);
    for(int i=0; i<r; i++) {
        cin >> board[i];
    }
    printf("%d\n", solve(0,0));
    return 0;
}

int solve(int row, int col)
{
    if(!inRange(row,col)) {
        return 0;
    } else if(alphbet[board[row][col]-'A']) {
        return 0;
    }
    
    int ret = 1;
    alphbet[board[row][col]-'A'] = true;
    for(int i=0; i<4; i++) {
        int nextRow = row+dy[i];
        int nextCol = col+dx[i];
        ret = max(ret, solve(nextRow, nextCol)+1);
    }
    alphbet[board[row][col]-'A'] = false;
    
    return ret;
}

bool inRange(int row, int col)
{
    return row>=0 && row<r && col>=0 && col<c;
}