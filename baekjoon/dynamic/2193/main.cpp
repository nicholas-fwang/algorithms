#include <iostream>

using namespace std;

long long primary[90];

int main()
{
    int n;
    cin >> n;
    primary[0] = 1;
    primary[1] = 1;
    for(int i=2; i<n; i++) {
        primary[i] = primary[i-1] + primary[i-2];
    }
    cout << primary[n-1] << endl;
    return 0;
}