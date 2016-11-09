#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
const int dx[8] = {0,0,1,-1,1,-1,1,-1};
const int dy[8] = {1,-1,0,0,1,-1,-1,1};

string board[5];
bool solve(int row, int col, string& word, int cnt);
bool inRange(int row, int col);
int main()
{
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        string s;
        for(int i=0; i<5; i++) {
            cin >> s;    
            board[i] = s;
        }
        
        int word;
        scanf("%d", &word);
        string w;
        for(int i=0; i<word; i++) {
            cin >> w;
            bool find = false;
            for(int j=0; j<5; j++) {
                for(int k=0; k<5; k++) {
                    if(w[0] == board[j][k] && solve(j,k,w,0)) {
                        cout << w << " YES\n";
                        find = true;
                        break;
                    }
                }
            }
            if(!find) cout << w << " NO\n";
        }
    }
    return 0;
}

bool solve(int row, int col, string& word, int cnt)
{
    if(cnt == word.size()-1) {
        return true;
    }
    
    bool ret = false;
    
    for(int i=0; i<8; i++) {
        int nextRow = row + dy[i];
        int nextCol = col + dx[i];
        if(inRange(nextRow, nextCol) && board[nextRow][nextCol] == word[cnt+1]) {
            ret = solve(nextRow, nextCol, word, cnt+1);
            if(ret) break;
        }
    }
    
    return ret;
}

bool inRange(int row, int col)
{
    return row < 5 && row >= 0 && col < 5 && col >= 0;
}