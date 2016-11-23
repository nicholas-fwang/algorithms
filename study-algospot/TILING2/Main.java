import java.util.*;

class Main {
    public static final int DI = 1000000007;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testCase = sc.nextInt();
        int[] dp;
        dp = new int[101];
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<=100; i++) {
            dp[i] = dp[i-1]%DI + dp[i-2]%DI;
            dp[i] = dp[i]%DI;
        }
        for(int tc=0; tc<testCase; tc++) {
            int n = sc.nextInt();
            System.out.println(dp[n]);
        }
    }
}