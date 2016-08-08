#include <iostream>

using namespace std;

int n;
unsigned int k;
int coin[10];

/** recursive function for counting coin */
int countLeastCoin(int leftMoney, int coinIndex);

int main()
{
    cin >> n;
    cin >> k;
    for(int i=0; i<n; i++) {
        cin >> coin[i];
    }
    
    /** the number of least coin*/
    int numberOfCoin = 0;
    numberOfCoin += countLeastCoin(k, n-1);
    cout << numberOfCoin << endl;
    return 0;
}

int countLeastCoin(int leftMoney, int coinIndex)
{
    /** base step */
    if(coinIndex == 0) {
        return leftMoney/coin[coinIndex];
    }
    
    /** count the number of coin
    *   , adding divded value to coin count
    *   , calling recursive function, including parameter the remainder
    */
    return leftMoney/coin[coinIndex] + countLeastCoin(leftMoney%coin[coinIndex], coinIndex-1);
}