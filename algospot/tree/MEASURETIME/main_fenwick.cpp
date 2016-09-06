#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct Fenwick {
    
    vector<int> tree;
    
    Fenwick(int n) : tree(n+1) {
    }
    
    // 0부터 pos까지의 합을 구한다
    int sum(int pos) {
        // 팬윅트리를 비트로 사용해 합을 구하기 위해 1을 더한다
        ++pos;
        int ret = 0;
        while(pos > 0) {
            ret += tree[pos];
            // 켜져있는 최하위비트를 끈 pos를 더해줘야 한다
            pos &= (pos-1);
        }
        return ret;
    }
    
    // pos에 val를 더한다
    void add(int pos, int val) {
        // 팬윅트리를 비트로 사용해 합을 구하기 위해 1을 더한다
       ++pos;
        while(pos < tree.size()) {
            tree[pos] += val;
            // 켜져있는 최하위 비트를 더한 pos에 업데이트한다
            pos += (pos & -pos);
        }
    }
};

int n[1000000];
int main()
{
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        int N;
        long long ret = 0;
        scanf("%d", &N);
        for(int i=0; i<N; i++) {
            int tmp;
            scanf("%d", &tmp);
            n[i] = tmp;
        }
        
        Fenwick fenwick(1000000);
        for(int i=0; i<N; i++) {
            // 999999까지 더한 결과 - n[i]까지 더한 결과
            // 초기에 sum(999999)는 0이다
            ret += fenwick.sum(999999) - fenwick.sum(n[i]);
            // n[i] pos를 추가한다
            fenwick.add(n[i], 1);
        }
        // 다 더한 결과는 최대 1000000의 제곱이기 때문에 64비트를 사용한다
        printf("%llu\n", ret);
    }
    return 0;
}