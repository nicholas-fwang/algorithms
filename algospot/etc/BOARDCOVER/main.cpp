/**
*   author : fisache
*   link : https://www.algospot.com/judge/problem/read/BOARDCOVER
*/

#include <iostream>

#define BLACK 0
#define WHITE 1

using namespace std;

int board[20][20];
int h, w;

const int coveredItem[4][3][2] = 
        {{{0,0},{1,0},{1,-1}},
        {{0,0},{0,1},{1,1}},
        {{0,0},{1,0},{1,1}},
        {{0,0},{1,0},{0,1}}};

/** recuresive function for counting */
int countCover();
/** finds it is available fill BLACK for coveredItem */
bool isAvailable(int unFilledH, int unFilledW, int item);
/** fills the COLOR including coveredItem */
void set(int unFilledH, int unFilledW, int item, int COLOR);
int main()
{
    int testCase;
    cin >> testCase;
    while(testCase--) {
        cin >> h;
        cin >> w;
        for(int height=0; height < h; height++) {
            for(int width=0; width < w; width++) {
                char val;
                cin >> val;
                if(val == '#') board[height][width] = BLACK;
                else board[height][width] = WHITE;
            }
        }
        cout << countCover() << endl;
    }
    return 0;
}

int countCover()
{
    int unFilledH = -1, unFilledW = -1;
    /** finds the most left and up WHITE location in board*/
    for(int height=0; height < h; height++) {
        for(int width=0; width < w; width++) {
            if(board[height][width] == WHITE) {
                unFilledH = height;
                unFilledW = width;
                break;
            }
        }
        if(unFilledH > -1) break;
    }
    if(unFilledH == -1) return 1;
    
    int ret = 0;
    
    /** recuresive step*/
    for(int item=0; item < 4; item++) {
        if(isAvailable(unFilledH, unFilledW, item)) {
            set(unFilledH, unFilledW, item, BLACK);
            ret += countCover();
            set(unFilledH, unFilledW, item, WHITE);
        }
    }
    /** if not count, return 0 */
    return ret;
}

bool isAvailable(int unFilledH, int unFilledW, int item)
{
    for(int i=0; i<3; i++) {
        /** out of index */
        if(unFilledH+coveredItem[item][i][0] >= h || unFilledW+coveredItem[item][i][1] >= w) {
            return false;
        }
        
        /** coveredItem in board is BLACK*/
        if(board[unFilledH+coveredItem[item][i][0]][ unFilledW+coveredItem[item][i][1]] == BLACK) {
            return false;
        } 
    }
    return true;
}

void set(int unFilledH, int unFilledW, int item, int COLOR)
{
    for(int i=0; i<3; i++) {
        board[unFilledH+coveredItem[item][i][0]][unFilledW+coveredItem[item][i][1]] = COLOR;
    }
}