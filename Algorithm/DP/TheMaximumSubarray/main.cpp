#include <iostream>

#define MAX(a,b) a > b ? a : b

using namespace std;

int array[100000];

int getMaximumSubarrary(int n)
{
    int max_ending_here = array[0];
    int max_so_far = array[0];
    for(int i=1; i<n; i++) {
        // if array[i] > max_ending_here+array[i], discard max_ending_here, that is previous value
        max_ending_here = MAX(array[i], max_ending_here + array[i]);
        // store max subarray   
        max_so_far = MAX(max_so_far, max_ending_here);
    }
    return max_so_far;
}

int getMaximum(int n)
{
    int sum = 0;
    int negative = 1, max = -9999;
    for(int i=0; i<n; i++) {
        if(array[i] >= 0) {
            sum += array[i];
            negative = 0;
        }
        max = MAX(max, array[i]);
    }
    // if not contain any positive value in array, use max value
    if(negative == 1) return max;
    else return sum;
}

int main()
{
    int testCase;
    cin >> testCase;
    while(testCase--) {
        int n;
        cin >> n;
        for(int i=0; i<n; i++) {
            cin >> array[i];
        }
        cout << getMaximumSubarrary(n) << " " << getMaximum(n) << endl;
    }
    return 0;
}