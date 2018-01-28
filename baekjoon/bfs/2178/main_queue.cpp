#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;
const int d[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

int n,m;
int map[100][100];
int visited[100][100];

struct Item {
  int row;
  int col;
  int dir;
};

void bfs(int r, int c);
bool inRange(int r, int c);
int main()
{
    scanf("%d %d", &n, &m);
    memset(map, -1, sizeof(map));
    memset(visited, -1, sizeof(visited));
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        for(int j=0; j<s.size(); j++) {
            map[i][j] = s[j]-'0';
        }
    }

    bfs(0,0);
    printf("%d\n", visited[n-1][m-1]);
    return 0;
}

void bfs(int r, int c)
{
    int ret = 1;
    visited[r][c] = 1;

    Item q[10001];
    int front = 0;
    int rear = 0;
    Item item = {0,0,1};
    q[rear++] = item;

    while(front < rear) {
        int row = q[front].row;
        int col = q[front].col;
        int cost = q[front].dir;

        front++;

        for(int i=0; i<4; i++) {
            int nextRow = row+d[i][0];
            int nextCol = col+d[i][1];
            int nextCost = cost+1;
            if(inRange(nextRow,nextCol) && map[nextRow][nextCol] == 1 && visited[nextRow][nextCol] == -1) {
                visited[nextRow][nextCol] = nextCost;
                Item nextItem = {nextRow, nextCol, nextCost};
                q[rear++] = nextItem;
            }
        }
    }
}

bool inRange(int r, int c)
{
    if(r >=0 && c >= 0 && r < n && c < m) return true;
    return false;
}
