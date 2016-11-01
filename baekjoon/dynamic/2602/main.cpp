#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int dp[101][21][2];
int map[101][2];
int s[21];
int main()
{
    string s1,s2,s3;
    cin >> s1;
    cin >> s2;
    cin >> s3;
    for(int i=1; i<=s1.size(); i++) {
        s[i] = s1[i-1]-'A';
    }
    for(int i=1; i<=s2.size(); i++) {
        map[i][0] = s2[i-1] - 'A';
        map[i][1] = s3[i-1] - 'A';
    }
    dp[0][0][0] = 1;
    dp[0][0][1] = 1;
    int m = s1.size();
    int n = s2.size();
    for(int i=1; i<=n; i++) {
        for(int l=1; l<=m; l++) {
            for(int d=0; d<=1; d++) {
                if(map[i][d] == s[l]) {
                    for(int j=0; j<i; j++) {
                        dp[i][l][d] += dp[j][l-1][1-d];
                    }
                }
            }
        }
    }
    int ret = 0;
    for(int i=1; i<=n; i++) {
        for(int d=0; d<=1; d++) {
            ret += dp[i][m][d];
        }
    }
    printf("%d\n", ret);
    return 0;
}