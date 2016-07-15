#include <stdio.h>
#include <stdlib.h>

#define RIGHT 1
#define UP 2
#define LEFT 3
#define DOWN 4

int n, m;
char c[100][100];

// find whether one path or multi path, then if one path, return path direction
int isOnePath(int row, int col, int pre_dir)
{
    int path = 0;
    int multi = 0;
    // right 1
    if(col+1 < m) {
        if(c[row][col+1] != 'X' && pre_dir != LEFT) {
            path = RIGHT;
            multi++;
        }
    }
    // up 2
    if(row-1 > -1) {
        if(c[row-1][col] != 'X' && pre_dir != DOWN) {
            path = UP; 
            multi++;
        }
    }
    // left 3
    if(col-1 > -1) {
        if(c[row][col-1] != 'X' && pre_dir != RIGHT) {
            path = LEFT;
            multi++;
        }
    }
    // down 4
    if(row+1 < n) {
        if(c[row+1][col] != 'X' && pre_dir != UP) {
            path = DOWN;
            multi++;
        }
    }
    if(multi == 1) {    // one path
        return path;
    } else {    // multi path
        return 0;
    }
}

int findDirection(int row, int col, int pre_dir)
{
    int tmp=0;
    //base case
    if(c[row][col] == '*') {
        return pre_dir;
    } else {    // recursive step
        // right
        if(col+1 < m) {
            if(c[row][col+1] != 'X' && pre_dir != LEFT) {
                tmp = findDirection(row, col+1, RIGHT);
                if(tmp > 0) return RIGHT;
            }
        }
        // up
        if(row-1 > -1) {
            if(c[row-1][col] != 'X' && pre_dir != DOWN) {
                tmp = findDirection(row-1, col, UP);
                if(tmp > 0) return UP;
            }
        }
        // left
        if(col-1 > -1) {
            if(c[row][col-1] != 'X' && pre_dir != RIGHT) {
                tmp = findDirection(row, col-1, LEFT);
                if(tmp > 0) return LEFT;
            }
        }
        // down
        if(row+1 < n) {
            if(c[row+1][col] != 'X' && pre_dir != UP) {
                tmp = findDirection(row+1, col, DOWN);
                if(tmp > 0) return DOWN;
            }
        }
        // not find path
        return 0;
    }
}

int main()
{
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        int i, j, k;
        int waves=0, preDir=0;
        int startRow, startCol, endRow, endCol;
        scanf("%d %d", &n, &m);
        
        for(i=0; i<n ;i++) {
            scanf("%s", c[i]);
        }
        scanf("%d", &k);
        for(i=0; i<n; i++) {
            for(j=0; j<m; j++) {
                if(c[i][j] == 'M') {
                    startRow = i;
                    startCol = j;
                } else if(c[i][j] == '*') {
                    endRow = i;
                    endCol = j;
                }
            }
        }
        while(startRow != endRow || startCol != endCol) {
            int onePath = isOnePath(startRow, startCol, preDir);
            int findPath;

            if(onePath > 0 && onePath <= 4) {
                // store predirection because we don't want to go to pre-path again
                preDir = onePath;
            } else {
                waves++;
                findPath = findDirection(startRow, startCol, preDir);
                preDir = findPath;
            }
            
            // move to path found
            switch(preDir) {
            case RIGHT:
            startCol++;
            break;
            case UP:
            startRow--;
            break;
            case LEFT:
            startCol--;
            break;
            case DOWN:
            startRow++;
            break;
            default:
            break;
            }
        }
        if(k == waves) printf("Impressed\n");
        else printf("Oops!\n");
    }
    return 0;
}
