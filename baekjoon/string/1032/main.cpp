#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

string str[50];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        cin >> str[i];
    }
    
    int size = str[0].size();
    for(int i=0; i<size; i++) {
        for(int j=1; j<n; j++) {
            if(str[0][i] != str[j][i]) {
                str[0][i] = '?';
                break;
            }
        }
    }
    cout << str[0] << endl;
    
    return 0;
}