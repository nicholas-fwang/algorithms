#include <iostream>
#include <string.h>

#define MAX(a,b) a>b ? a:b

using namespace std;

// 2행을 가질때 도미노가 만들어지는 경우는 총 12가지 방법이 있다
// 0x47 : 0100
//        0111
// 도미노가 2개 만들어진다
const int dominoes[12] = {
    0x00,
    0x11, 0x22, 0x44, 0x03, 0x06,
    0x17, 0x47, 0x33, 0x55, 0x66,
    0x77
};

// 2행에서 도미노를 만들 때 소비되는 도미노 개수
const int cost[12] = {
    0, 
    1, 1, 1, 1, 1,
    2, 2, 2, 2, 2,
    3
};

// 3f을 이진표기하면 00111111이 되는데 이것은 2배를 하더라도 overflow가 안나고
// 음수 표현도 가능하기 때문에 무한대로 적합하다
const int oo = 0x3f3f3f3f;

int n,k;

// cache의 원리를 생각해보면 block 단위로 가져오는 spatial locality의 원리로
// 메모리의 연속적인 값을 가지는 구간이 더 긴게 좋다.
// 따라서 원래는 row가 1000개까지 가지지만 반대로 해줘 cache 역할을 최대화 시켜준다
// recursion 함수는 row가 0부터 올라가지 않고 n부터 내려가기 때문에 
// base step에서 행이 0일 때 return을 진행하게 하기 위해 1000+1로 공간을 잡았다
int board[3][1001];
// cache[n][k][last]
// n행에 있을 때 전에 k개를 사용했고 전 이번에 해당하는 2개의 행렬 중 전 행렬에 포함되는
// 열을 사용했을 때 앞으로 도미노를 놓는 최대값
int cache[1001][1001][8];

// row 행에서 bitmask domino가 덮는 영역의 합
int get(int domino, int row);
// recursion
// row값 보다 -1, -2인 행을 의미한다
int cover(int row, int usedK, int preD);
int main()
{
    cin >> n >> k;
    memset(cache, -1, sizeof(cache));
    for(int i=0; i<n; i++) {
        for(int j=0; j<3; j++) {
            int tmp;
            cin >> tmp;
            board[j][i] = tmp;
        }
    }
    int result = cover(n, k, 0);
    cout << result << endl;
    return 0;
}

int get(int domino, int row)
{
    int sol = 0;
    // 영역이 벗어났거나 영역에 도미노가 없을 때
    // 영역이 벗어나는 경우는 cover에서 row가 1이라면 0과 -1번 행을 쓰기 때문에
    // -1번째 행을 무시한다
    if(row < 0 && domino) return -oo;
    // 최하위 비트가 1이라면 더해지고 0이라면 0이 더해진다
    sol += (domino&1) * board[0][row];
    // 오른쪽으로 쉬프트해서 다음 최하위 비트를 가져온다
    domino >>= 1;
    sol += (domino&1) * board[1][row];
    domino >>= 1;
    sol += (domino&1) * board[2][row];
    return sol;
}

int cover(int row, int usedK, int last)
{
    // n부터 시작하는 row가 0이 됐다.
    // 즉, 행렬에서 -1과 -2번째 행렬을 사용할거기 때문에 return 한다
    if(row == 0) {
        // 마지막에 도달했을 때 k를 다 사용했으면 0
        return usedK == 0 ? 0 : -oo;
    }
    
    if(!usedK) {
        // 행렬의 끝에 도달한 것과 상관없이 k를 다썼을 경우
        return 0;
    }

    if(usedK < 0) {
        // 도미노를 2개 이상 쓰는 경우에는 usedK가 음수가 될 수 있다
        return -oo;
    }

    // row 행에서 전에 사용됐던 도미노가 usedK개 이고 
    // 바로 이전에 사용했던 도미노의 위행 비트가 last일 때 남은 도미노들의 최대합
    int& ret = cache[row][usedK][last];
    if(ret != -1) {
        return ret;
    }

    ret = -oo;
    // 2행에 도미노가 놓일 수 있는 경우의 수 12개
    for(int i=0; i<12; i++) {
        // 2행 중 아래행
        int right = dominoes[i] & 0xf;
        // 2행 중 위행
        int left = (dominoes[i] >> 4) & 0xf;
        // 현재 행의 아래행과 이전의 행의 위행의 도미노가 겹치는지 확인한다
        if(last & right) continue;

        int sum = 0;
       
        // 아래행에 놓이는 도미노들의 합
        sum += get(dominoes[i], row-1);
        // 위행에 놓이는 도미노들의 합
        sum += get(dominoes[i] >> 4, row-2);

        // recursive
        ret = MAX(ret, cover(row-1, usedK-cost[i], left)+sum);
    }
    return ret;
}

