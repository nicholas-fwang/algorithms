from collections import deque

if __name__ == '__main__' :
    testCase = int(input())
    for tc in range(testCase) :
        K, N = map(int, input().split(' '))
        a = 1983
        q = deque()
        result = 0
        sum = 0
        for i in range(N) :
            if i > 0 :
                a = (a*214013 + 2531011) % (1<<32)
            signal = a%10000 + 1
            sum += signal
            q.append(signal)
            while sum > K :
                sum -= q[0]
                q.popleft()
            if sum == K :
                result += 1
        print("%d" %(result))
