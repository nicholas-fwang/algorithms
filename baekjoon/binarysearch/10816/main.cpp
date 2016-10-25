#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int> > N;
vector<int> tmp;
int n,m;
int binarySearch(int low, int high, int value);
int main()
{
    scanf("%d", &n);
    int t;
    for(int i=0; i<n; i++) {
        scanf("%d", &t);
        tmp.push_back(t);
    }
    sort(tmp.begin(), tmp.end());
    int j=0;
    N.push_back(make_pair(tmp[j],1));
    for(int i=1; i<tmp.size(); i++) {
        if(tmp[i-1] == tmp[i]) {
            N[j].second++;
        } else {
            j++;
            N.push_back(make_pair(tmp[i],1));
        }
    }
    scanf("%d", &m);
    int a;
    for(int i=0; i<m; i++) {
        scanf("%d", &a);
        printf("%d ", binarySearch(0,N.size()-1,a));
    }
    return 0;
}

int binarySearch(int low, int high, int value)
{
    if(low > high) {
        return 0;
    }
    
    int mid = (low+high)/2;
    if(value > N[mid].first) {
        return binarySearch(mid+1, high, value);
    } else if(value < N[mid].first) {
        return binarySearch(low, mid-1, value);
    } else {
        // 갯수 계산
        return N[mid].second;
    }
}