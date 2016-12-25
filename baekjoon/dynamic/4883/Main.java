import java.util.*;

class Main {
    static final int oo = 0x3f3f3f3f;
    static int N;
    static int dp[][];
    static int map[][];
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tc=0;
        while(true) {
            N = sc.nextInt();
            if(N == 0) break;
            map = new int[100001][4];
            dp = new int[100001][4];
            for(int i=0; i<N; i++) {
                for(int j=0; j<3; j++) {
                    map[i][j] = sc.nextInt();
                }
            }
            
            dp[0][0] = oo;
            dp[0][1] = map[0][1];
            dp[0][2] = map[0][1]+map[0][2];
            
            for(int i=1; i<N; i++) {
                dp[i][0] = min(dp[i-1][0], dp[i-1][1])+map[i][0];
                dp[i][1] = min(dp[i-1][0], dp[i-1][1]);
                dp[i][1] = min(dp[i][1], dp[i-1][2]);
                dp[i][1] = min(dp[i][1], dp[i][0])+map[i][1];
                dp[i][2] = min(dp[i-1][1], dp[i-1][2]);
                dp[i][2] = min(dp[i][2], dp[i][1])+map[i][2];
            }
            
            System.out.printf("%d. %d\n", ++tc, dp[N-1][1]);
        }
    }
    
    public static int min(int a, int b) {
        return a>b?b:a;
    }
}