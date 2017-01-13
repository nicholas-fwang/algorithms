import java.util.*;

class Main {
    static int N;
    static boolean dp[];
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        dp = new boolean[1001];
        Arrays.fill(dp, false);
        N = sc.nextInt();
        dp[0] = true;
        dp[1] = true;
        dp[3] = true;
        dp[4] = true;
        for(int i=5; i<=N; i++) {
            dp[i] = !dp[i-4] | !dp[i-3] | !dp[i-1];
        }
        String ret = (dp[N]==true?"SK":"CY");
        System.out.println(ret);
    }
}