#include <cstring>
#include <cstdio>
#include <iostream>

using namespace std;

// P,K,H,T
int card[4][14];

int getIndex(char c);
int main()
{
    string s;
    bool greska = false;
    cin >> s;
    for(int i=0; i<s.size(); i+=3) {
        int n = (s[i+1]-'0')*10 + (s[i+2]-'0');
        int index = getIndex(s[i]);
        card[index][n]++;
        if(card[index][n] > 1) {
            greska = true;
            break;
        }
    }

    if(greska) {
        printf("GRESKA\n");
        return 0;
    }
    
    for(int i=0; i<4; i++) {
        int cnt = 0;
        for(int j=1; j<=13; j++) {
            cnt += card[i][j];
        }
        printf("%d ", 13-cnt);
    }
    printf("\n");
    
    return 0;
}

int getIndex(char c) {
    switch(c) {
        case 'P':
            return 0;
        case 'K':
            return 1;
        case 'H':
            return 2;
        case 'T':
            return 3;
    }
    return -1;
}