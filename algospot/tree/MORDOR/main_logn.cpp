#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int oo = 0x3f3f3f3f;

struct RMQ {
    int n;
    vector<int> rangeMin;
    vector<int> rangeMax;
    RMQ(const vector<int>& array) {
        n = array.size();
        rangeMin.resize(4*n);
        rangeMax.resize(4*n);
        initMin(array, 0, n-1, 1);
        initMax(array, 0, n-1, 1);
    }
    
    // 최소값을 저장하는 구간트리를 만든다
    int initMin(const vector<int>& array, int left, int right, int node) {
        if(left == right) {
            return rangeMin[node] = array[left];
        }
        int mid = (left + right) / 2;
        int leftMin = initMin(array, left, mid, node*2);
        int rightMin = initMin(array, mid+1, right, node*2+1);
        return rangeMin[node] = min(leftMin, rightMin);
    }
    
    // 최대값을 저장하는 구간트리를 만든다
    int initMax(const vector<int>& array, int left, int right, int node) {
        if(left == right) {
            return rangeMax[node] = array[left];
        }
        int mid = (left + right) / 2;
        int leftMax = initMax(array, left, mid, node*2);
        int rightMax = initMax(array, mid+1, right, node*2+1);
        return rangeMax[node] = max(leftMax, rightMax);
    }
    
    // nodeLeft ~ nodeRight 에서 최소값을 반환한다
    int queryMin(int left, int right, int node, 
             int nodeLeft, int nodeRight) {
        // nodeLeft,nodeRight가 left,right 범위를 벗어났다
        if(right < nodeLeft || left > nodeRight) {
            return oo;
        }
        
        // nodeLeft,nodeRight가 left,right 안에 포함됐다
        if(left <= nodeLeft && nodeRight <= right) {
            return rangeMin[node];
        }
        
        // 둘이 겹쳐있을 경우
        int mid = (nodeLeft + nodeRight) / 2;
        // 두 자식노드를 재귀호출해 범위를 다시 살펴본다
        return min(queryMin(left, right, node*2, nodeLeft, mid),
                  queryMin(left, right, node*2+1, mid+1, nodeRight));
    }
    
    // nodeLeft ~ nodeRight 에서 최대값을 반환한다
    int queryMax(int left, int right, int node,
                int nodeLeft, int nodeRight) {
        if(right < nodeLeft || left > nodeRight) {
            return 0;
        }
        if(right >= nodeRight && left <= nodeLeft) {
            return rangeMax[node];
        }
        
        int mid = (nodeLeft + nodeRight) / 2;
        return max(queryMax(left, right, node*2, nodeLeft, mid),
                  queryMax(left, right, node*2+1, mid+1, nodeRight));
    }
    
    int queryMin(int left, int right) {
        return queryMin(left, right, 1, 0, n-1);
    }
    
    int queryMax(int left, int right) {
        return queryMax(left, right, 1, 0, n-1);
    }
};

int main()
{
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        int N, Q;
        scanf("%d %d", &N, &Q);
        vector<int> arr;
        for(int i=0; i<N; i++) {
            int h;
            scanf("%d", &h);
            arr.push_back(h);
        }
        RMQ rmq = RMQ(arr);
        
        while(Q--) {
            int a,b;
            scanf("%d %d", &a, &b);
            int level = rmq.queryMax(a,b) - rmq.queryMin(a,b);
            printf("%d\n", level);
        }
    }
    return 0;
}