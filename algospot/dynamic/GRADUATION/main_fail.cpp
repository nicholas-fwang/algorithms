#include <iostream>
#include <string.h>
#include <limits.h>

#define MIN(a,b) a>b ? b:a

using namespace std;

// row index 과목을 들으려면 이수해야 되는 과목 col, pre[row][col] = 1
int pre[12][12];
// row 학기에 개설되는 과목 col, classes[row][col] = 1
int classes[10][10];

// 현재까지 들은 과목
// 0 = 선수과목 때문에 못 듣는 과목, 1 = 이수한 과목, -1 = 수강 가능 과목
int taken[12];
int n, k, m, l;

// 현재학기(current)
int graduate(int current);
// taken refresh
void refreshTaken();
int main()
{
    int testCase;
    cin >> testCase;
    while(testCase--) {
        cin >> n >> k >> m >> l;
        memset(taken, -1, sizeof(taken));
        memset(pre, 0, sizeof(pre));
        memset(classes, 0, sizeof(classes));
        for(int i=0; i<n; i++) {
            int tmp;
            cin >> tmp;
            for(int j=0; j<tmp; j++) {
                int tmp1;
                cin >> tmp1;
                pre[i][tmp1] = 1;
            }
        }
        
        for(int i=0; i<m; i++) {
            int tmp;
            cin >> tmp;
            for(int j=0; j<tmp; j++) {
                int tmp1;
                cin >> tmp1;
                classes[i][tmp1] = 1;
            }
        }
        
        refreshTaken();
        
        int result = graduate(0);
        if(result == INT_MAX) cout << "IMPOSSIBLE" << endl;
        else cout << result << endl;
    }
    return 0;
}
int graduate(int current)
{
    // base step
    int cnt=0;
    for(int i=0; i<n; i++) {
        if(taken[i] == 1) cnt++;
    }
    // 다 들음
    if(cnt >= k) {
        return 0;
    }
    // 전체 학기 종료
    if(current == m) return INT_MAX;
    int ret = INT_MAX;
    // recursive step
    // 아무것도 듣지 않아서 휴학 처리
    ret = MIN(ret, graduate(current+1));
    
    // 과목을 1개부터 l개까지 듣는다
    for(int i=1; i<=l; i++) {
        // TODO : n개 중 i개로 만들면서 current 학기에 수강 가능한 canTaken 배열
        // canTaken 배열로 taken 배열에 이수 값(1) 입력
        // refreshTaken()
        // ret = MIN(ret, graduate(current+1)+1);
        // canTaken 배열로 입력한 taken 원상 복귀
        // refreshTaken()
    }
    return ret;
}

void refreshTaken()
{
    for(int i=0; i<n; i++) {
        int canTake = 1;
        // 수강한 과목빼고 전부 refresh
        if(taken[i] != 1) {
            for(int j=0; j<n; j++) {
                if(pre[i][j] == 1) {
                    if(taken[j] != 1) {
                        canTake = 0;
                        break;
                    }
                }
            }
            // 수강 가능 과목
            if(canTake) taken[i] = -1;    
            // 수강 불가능 과목
            else taken[i] = 0;
        }
    }
}