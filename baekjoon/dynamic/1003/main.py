if __name__ == '__main__':
    fibo = [[0 for col in range(2)] for row in range(41)]
    testCase = int(input())
    fibo[0][0] = 1
    fibo[1][0] = 0

    fibo[0][1] = 0
    fibo[1][1] = 1

    for tc in range(testCase):
        n = int(input())
        for i in range(2,n+1):
            fibo[i][0] = fibo[i-1][0] + fibo[i-2][0]
            fibo[i][1] = fibo[i-1][1] + fibo[i-2][1]
        print("%d %d" %(fibo[n][0], fibo[n][1]))
