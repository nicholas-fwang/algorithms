#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
    int testCase;
    cin >> testCase;
    while(testCase--) {
        int n, k;
        cin >> n >> k;
        vector<int> josephus;
        // 병사의 번호를 입력한다
        for(int i=1; i<=n; i++) {
            josephus.push_back(i);
        }
        vector<int>::iterator iter = josephus.begin();
        while(josephus.size() > 2) {
            iter = josephus.erase(iter);
            // 병사는 원형으로 둘러 앉았기 때문에 끝에 도달하면 다시 처음으로 간다
            if(iter == josephus.end()) {
                iter = josephus.begin();
            }
            // erase는 죽은 병사의 다음 iter를 반환하기 때문에 k-1번만 옆으로 간다
            for(int i=0; i<k-1; i++) {
                iter++;
                if(iter == josephus.end()) {
                    iter = josephus.begin();
                }
            }
        }
        // 살아남은 병사 2명의 번호를 출력한다
        cout << josephus.at(0) << " " << josephus.at(1) << endl;
    }
    return 0;
}