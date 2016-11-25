#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int dx[8] = {1,1,0,-1,-1,-1,0,1};
const int dy[8] = {0,1,1,1,0,-1,-1,-1};

int N,L;
int map[21][21];
int cache[21][21][21][21][21];
bool inRange(int row, int col);
int solve(int r1,int c1, int r2, int c2, int l);
int main()
{
    scanf("%d %d", &N, &L);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    memset(cache, -1, sizeof(cache));
    
    int ret = 0;
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(L%2 == 1) {
                ret += solve(i,j,i,j,1);
            } else {
                for(int k=0; k<8; k++) {
                    int nexti = i+dy[k];
                    int nextj = j+dx[k];
                    if(inRange(nexti, nextj) && map[i][j]== map[nexti][nextj]) {
                        ret += solve(i,j,nexti,nextj,2);
                    }
                }
            } 
        }
    }
    
    printf("%d\n", ret);
    return 0;
}

int solve(int r1,int c1, int r2, int c2, int l)
{
    if(l == L) return 1;
    
    int& ret = cache[r1][c1][r2][c2][l];
    if(ret != -1) {
        return ret;
    }
    ret = 0;
    
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            int nextR1 = r1+dy[i];
            int nextC1 = c1+dx[i];
            int nextR2 = r2+dy[j];
            int nextC2 = c2+dx[j];
            
            if(inRange(nextR1,nextC1) && inRange(nextR2,nextC2) && map[nextR1][nextC1] == map[nextR2][nextC2]) {
                ret += solve(nextR1,nextC1,nextR2,nextC2,l+2);
            }
        }
    }
    return ret;
}

bool inRange(int row, int col) {
    return row >= 0 && row < N && col >= 0 && col < N;
}