#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

const int D[4][2] = {{1,0}, {-1,0}, {0,-1}, {0,1}};

bool STOP = false;

struct Item {
    int y;
    int x;
    int cnt;
};

vector<string> gravity(vector<string> map)
{
    vector<string> ret;
    for(int i=0; i<12; i++) {
        string s;
        for(int j=0; j<6; j++) {
            s.push_back('.');
        }
        ret.push_back(s);
    }
    for(int j=0; j<7; j++) {
        int y = 11;
        for(int i=11; i>=0; i--) {
            if(map[i][j] != '.') {
                ret[y][j] = map[i][j];
                y--;
            }
        }
    }
    return ret;
}

bool inRange(int y, int x)
{
    return y>=0 && y<12 && x>=0 && x<6;
}

vector<string> boom(vector<string> map)
{
    bool visited[12][6];
    memset(visited, false, sizeof(visited));
    bool boomed = false;
    for(int i=0; i<12; i++) {
        for(int j=0; j<6; j++) {
            if(map[i][j] != '.' && !visited[i][j]) {
                Item q[100];
                visited[i][j] = true;
                char color = map[i][j];
                int front = 0;
                int rear = 0;
                int find = 1;
                int deleted[100][2];
                deleted[0][0] = i;
                deleted[0][1] = j;
                Item item = {i, j, 1};
                q[rear++] = item;
                while(front < rear) {
                    int y = q[front].y;
                    int x = q[front].x;
                    int cnt = q[front].cnt;
                    front++;

                    for(int z=0; z<4; z++) {
                        int nextY = y+D[z][0];
                        int nextX = x+D[z][1];
                        int nextCnt = cnt + 1;
                        if(inRange(nextY, nextX) && !visited[nextY][nextX] &&
                            map[nextY][nextX] == color) {
                            visited[nextY][nextX] = true;
                            Item nextItem = {nextY, nextX, nextCnt};
                            q[rear++] = nextItem;
                            deleted[find][0] = nextY;
                            deleted[find][1] = nextX;
                            find++;
                        }
                    }
                }

                if(find >= 4) {
                    boomed = true;
                    for(int i=0; i<find; i++) {
                        int deleteY = deleted[i][0];
                        int deleteX = deleted[i][1];
                        map[deleteY][deleteX] = '.';
                    }
                }
            }
        }
    }
    if(!boomed) {
        STOP=true;
    }
    return gravity(map);
}

int dfs(int relay, vector<string> map)
{
    if(STOP) {
        return relay-1;
    }
    return dfs(relay+1, boom(map));
}

int main()
{
    vector<string> map;
    for(int i=0; i<12; i++) {
        string s;
        cin >> s;
        map.push_back(s);
    }
    printf("%d\n", dfs(0, map));
    return 0;
}
