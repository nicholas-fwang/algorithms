#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
const int oo = 0x3f3f3f3f;
const string ch = "DSLR";
int operate(int n, int op);
int main()
{
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        int a,b;
        scanf("%d %d", &a, &b);
        queue<int> q;
        q.push(a);
        vector<pair<int,int> > parent = vector<pair<int, int> >(10001, make_pair(-1,-1));
        parent[a].first = a;
        while(!q.empty()) {
            int here = q.front();
            q.pop();
            if(here == b) break;
            for(int i=0; i<4; i++) {
                int there = operate(here, i);
                if(parent[there].first == -1) {
                    parent[there].first = here;
                    parent[there].second = i;
                    q.push(there);
                }
            }
        }
        int n;
        string ret;
        while(b != a) {
            n = parent[b].second;
            ret.push_back(ch[n]);
            b = parent[b].first;
        }
        reverse(ret.begin(), ret.end());
        cout << ret << endl;
    }
    return 0;
}


int operate(int n, int op)
{
    switch(op) {
        case 0:
            n = (n*2)%10000;
            break;
        case 1:
            if(n == 0) n = 9999; 
            else n--;
            break;
        case 2:
            n = (n*10)%10000 + (n/1000);
            break;
        case 3:
            n = n/10 + (n%10)*1000;
            break;
        default :
            break;
    }
    return n;
}