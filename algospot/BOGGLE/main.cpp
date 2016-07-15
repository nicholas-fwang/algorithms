/**
*   author : fisache
*   TODO : Apply Dynamic Programming with new cpp file
*   link : https://www.algospot.com/judge/problem/read/BOGGLE
*/


#include <iostream>
#include <string>

using namespace std;

/** For moving up, down, right, left and diagonals*/
const int dr[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int dc[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

char board[5][5];

/** recursive function */
bool hasWord(int row, int col, const string& word);
/** before compraison, filter bounding out of index */
bool inRange(int row, int col);

int main()
{
    int testCase;
    cin >> testCase;
    while(testCase--) {
        for(int i=0; i<5; i++) {
            for(int j=0; j<5; j++) {
                cin >> board[i][j];
            }
        }
        
        int n;
        cin >> n;
        for(int i=0; i<n; i++) {
            string word;
            cin >> word;
            bool isMatched = false;
            for(int row=0; row < 5; row++) {
                for(int col=0; col < 5; col++) {
                    if(hasWord(row, col, word)) {
                        isMatched = 1;
                        break;
                    }
                }
                if(isMatched) break;
            }
            cout << word << " ";
            if(isMatched) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}

bool hasWord(int row, int col, const string& word)
{
    if(!inRange(row, col)) return false;
    if(board[row][col] != word[0]) return false;
    if(word.size() == 1) return true;
    
    for(int direction=0; direction < 8; direction++) {
        if(hasWord(row+dr[direction], col+dc[direction], word.substr(1))) {
            return true;
        }
    }
    return false;
}

bool inRange(int row, int col)
{
    if(row > 4 || col > 4) {
        return false;
    }
    return true;
}