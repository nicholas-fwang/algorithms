#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

// 난수값 출력 구조체
struct RNG {
    int seed, a, b;
    RNG(int _a, int _b) : a(_a), b(_b), seed(1983) {
        
    }
    
    int next() {
        int ret = seed;
        seed = (((long long)seed*a)+b) % 20090711;
        return ret;
    }
};

// 1~n개의 중간값을 더한 결과를 반환
int printMedian(int n, RNG rng);

int main()
{
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        int n,a,b;
        scanf("%d %d %d", &n, &a, &b);
        
        printf("%d\n", printMedian(n, RNG(a,b)));
    }
    return 0;
}

int printMedian(int n, RNG rng)
{
    // 우선순위큐로 minHeap과 maxHeap을 구현한다
    priority_queue<int, vector<int>, less<int> > maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
    int ret = 0;
    
    for(int i=1; i<=n; i++) {
        // maxHeap은 minHeap의 크기보다 1 크거나 같다
        if(maxHeap.size() == minHeap.size()) {
            maxHeap.push(rng.next());
        } else {
            minHeap.push(rng.next());
        }
        
        // 추가된 값이 바꼈을 경우
        if(!minHeap.empty() && !maxHeap.empty() &&
           maxHeap.top() > minHeap.top()) {
            int a=maxHeap.top(), b=minHeap.top();
            maxHeap.pop();
            minHeap.pop();
            maxHeap.push(b);
            minHeap.push(a);
        }
        ret = (ret + maxHeap.top()) % 20090711;
    }
    return ret;
}