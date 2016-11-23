#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

string W,S;
int cache[101][101];
int N;
vector<string> r;
int solve(int w, int s);
int main()
{
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        cin >> W;
        scanf("%d", &N);
        for(int i=0; i<N; i++) {
            cin >> S;
            memset(cache, -1, sizeof(cache));
            if(solve(0,0) == 1) r.push_back(S);
        }
        sort(r.begin(), r.end());
        for(int i=0; i<r.size(); i++) {
            cout << r[i] << endl;
        }
    }
    return 0;
}

int solve(int w, int s) {
    int& ret = cache[w][s];
    if(ret != -1) return ret;
    while(s < S.size() && w < W.size() && 
         (W[w] == '?' || W[w] == S[s])) {
        ++w;
        ++s;
    }
    if(w == W.size()) return ret = (s==S.size());
    if(W[w] == '*') {
        for(int i=0; i+s <= S.size(); i++) {
            if(solve(w+1, s+i)) return ret = 1;
        }
    }
    return ret = 0;
}