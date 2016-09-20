#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    char grade;
    if(90 <= n && n <= 100) {
        grade = 'A';
    } else if(80 <= n && n <= 89) {
        grade = 'B';
    } else if(70 <= n && n <= 79) {
        grade = 'C';
    } else if(60 <= n && n <= 69) {
        grade = 'D';
    } else {
        grade = 'F';
    }
    printf("%c\n", grade);
    return 0;
}