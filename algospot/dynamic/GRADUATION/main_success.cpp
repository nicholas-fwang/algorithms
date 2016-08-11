#include <iostream>
#include <string.h>
#include <limits.h>

#define MIN(a,b) a>b ? b:a

using namespace std;

const int INF = 987654321;

// i번째 과목의 선수과목 집합
int pre[12];
// i학기에 개설되는 과목 집합
int classes[10];
// i학기(row)일 때 들은 과목 집합이 col이라면 앞으로 k개 이상을 들으려면 남은 최소 학기 
// 과목이 최대 12개이기 때문에 최대 bit 자리를 12개 확보하기 위해 shift했다
int cache[10][1<<12];

int n, k, m, l;

// n의 이진수 표현에서 켜진 비트의 수를 반환한다
int bitCount(int n);
// 현재 학기 semester 전까지 들은과목 taken
// k개 이상 과목을 들으려면 최소 몇학기를 더 있어야 하는가
// 불가능하면 INT_MAX 반환
int graduate(int semester, int taken);
int main()
{
    int testCase;
    cin >> testCase;
    while(testCase--) {
        cin >> n >> k >> m >> l;
        memset(pre, 0, sizeof(pre));
        memset(classes, 0, sizeof(classes));
        memset(cache, -1, sizeof(cache));
        for(int i=0; i<n; i++) {
            int tmp;
            cin >> tmp;
            for(int j=0; j<tmp; j++) {
                int tmp1;
                cin >> tmp1;
                // i과목의 선수 과목을 입력한다
                pre[i] |= (1 << tmp1);
            }
        }
        for(int i=0; i<m; i++) {
            int tmp;
            cin >> tmp;
            for(int j=0; j<tmp; j++) {
                int tmp1;
                cin >> tmp1;
                // i학기에 개설되는 과목을 입력한다
                classes[i] |= (1<< tmp1);
            }
        }
        // 0학기에 들은과목의 집합 0
        int taken = 0;
        int result = graduate(0, taken);
        if(result == INT_MAX-1) cout << "IMPOSSIBLE" << endl;
        else cout << result << endl;
    }
    return 0;
}
int bitCount(int n)
{
    // 전부다 오른쪽으로 shift가 됐으면 0 반환
    if(n == 0) return 0;
    // 오른쪽으로 한칸씩 쉬프트하면서 가장 마지막 bit가 1인지 확인한다
    // 0번 bit를 빼고 나머지는 전부 2의 배수이기 때문에 마지막 bit가 1이라면 x%2는 1이 된다
    return n%2 + bitCount(n/2);
}

int graduate(int semester, int taken)
{
    // base step
    // 지금까지 들은 과목 수가 k개 이상이라면 0을 반환한다(다 들음)
    if(bitCount(taken) >= k) return 0;
    // 전체 학기가 다 끝났는데 k개를 못들었다
    if(semester == m) return INT_MAX-1;
    
    // semester 학기 전까지 taken 과목을 들었다면 k개 이상을 듣기위해 남은 최소 학기 수 
    int& ret = cache[semester][taken];
    if(ret != -1) return ret;
    ret = INT_MAX-1;
    
    // 이번 학기에 개설되는 과목 & 아직 안들은 과목 = 선수 조건 뺀 이번학기에 들을 수 있는 과목
    int canTake = (classes[semester] & ~taken);
    
    // 선수 과목을 듣지 않은 과목을 걸러낸다
    for(int i=0; i<n; i++) {
        // (i 과목이 canTake에 있는지)
        // && (지금까지 들은 과목 & i과목의 선수 과목) != i과목의 선수 과목
        // = i 과목은 이번학기에 들을 수 없다
        // i 과목이 canTake에 있는지 확인하고 i 과목의 선수 과목들이 이수됐는지 확인한다. 만약 이수되지 않았다면 i 과목은 이번학기에 들을 수 없다
        if((canTake & ( 1<< i )) &&
          (taken & pre[i]) != pre[i]) {
            canTake &= ~(1 << i);
        }
    }
    
    // 부분 집합을 모두 순회한다 take-1을 하게 되면 canTake보다 작은 모든 수를 순회하지만 (take-1) & canTake를 하게 되면 그 수 중에서 부분 집합만 순회한다
    for(int take = canTake; take > 0; take = ((take - 1) & canTake)) {
        // 한 학기에는 최대 l개 까지 들을 수 있다 따라서 l개 보다 큰 부분 집합은 무시한다
        if(bitCount(take) > l) continue;
        // 학기를 증가시키고 take를 들은 과목에 추가한다
        ret = MIN(ret, graduate(semester+1, taken | take) +1 );
    }
    
    // 아무것도 듣지 않은 경우(take = 0)에는 현재 학기만 증가시킨다
    ret = MIN(ret, graduate(semester+1, taken));
    return ret;
}