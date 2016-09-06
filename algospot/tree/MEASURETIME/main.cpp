#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct RMQ {
    int n;
    vector<int> rangeMin;
    
    RMQ(const vector<int>& array) {
        n = array.size();
        rangeMin.resize(4*n);
        init(array, 0, n-1, 1);
    }
    
    int init(const vector<int>& array, 
             int left, int right, int node) {
        if(left == right) {
            rangeMin[node] = array[left];
            return rangeMin[node];
        }    
        
        int mid = (left + right) / 2;
        int leftMin = init(array, left, mid, node*2);
        int rightMin = init(array, mid+1, right, node*2+1);
        return rangeMin[node] = max(leftMin, rightMin);
    }
    
    int query(int left, int right, 
              int nodeLeft, int nodeRight, int node) {
        
        if(right < nodeLeft || left > nodeRight) {
            return 0;
        }
        
        if(nodeLeft >= left && nodeRight <= right) {
            return rangeMin[node];
        }
        
        int mid = (nodeLeft + nodeRight) / 2;
        return min(query(left, right, nodeLeft, mid, node*2),
            query(left, right, mid+1, nodeRight, node*2+1);
    }
    
    int query(int right) {
        return query(0, right, 0, n-1, 1);
    }
};

int main()
{
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        int N;
        scanf("%d", &N);
        vector<int> n;
        for(int i=0; i<N; i++) {
            int tmp;
            scanf("%d", &tmp);
            n.push_back(tmp);
        }
        
        RMQ rmq = RMQ(n);
        int ret = 0;
        for(int i=1; i<N; i++) {
            int tmp = rmq.query(i-1);
            
//            ret += (i-rmq.queryLessthan(i-1, n[i]));
        }
//        printf("%d\n", ret);
    }
    return 0;
}