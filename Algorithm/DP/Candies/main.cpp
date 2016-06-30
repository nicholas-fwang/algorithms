#include <iostream>

#define MIN(a, b) a > b ? b : a

using namespace std;

int rating[100000];
int candies[100000];

int main()
{
    int n;
    cin >> n;
    int amount=0;
    for(int i=0; i<n; i++) {
        cin >> rating[i];
    }
    
    for(int i=0; i<n; i++) {
        candies[i] = 1;
    }

    for(int i=1; i<n; i++) {
        if(rating[i-1] < rating[i]) {
            candies[i] = candies[i-1] + 1;
        }
    }
    
    for(int i=n-2; i>=0; i--) {
        if(rating[i+1] < rating[i] && candies[i] < candies[i+1]+1) {
            candies[i] = candies[i+1] + 1;
        }
    }
    
    for(int i=0; i<n; i++) {
        amount += candies[i];
    }
    cout << amount << endl;
    return 0;
}