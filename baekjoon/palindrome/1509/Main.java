import java.util.*;

class Main {
    static final int oo = 0x3f3f3f3f;
    static String s;
    static int N;
    static boolean dp[][];
    static int cache[];
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        s = sc.nextLine();
        N = s.length();
        dp = new boolean[2501][2501];
        for(int i=0; i<=2500; i++) Arrays.fill(dp[i], false);
        for(int i=0; i<N; i++) {
            dp[i][i] = true;
        }
        for(int i=0; i<N-1; i++) {
            if(s.charAt(i) == s.charAt(i+1)) {
                dp[i][i+1] = true;
            }
        }
        for(int i=2; i<N; i++) {
            for(int j=0; j<i; j++) {
                if(dp[j+1][i-1] && s.charAt(j) == s.charAt(i)) {
                    dp[j][i] = true;
                } 
            }
        }
        
        cache = new int[2501];
        Arrays.fill(cache, -1);
        System.out.println(solve(0));
    }
    
    public static int solve(int n) {
        if(n == N) return 0;
        
        if(cache[n] != -1) return cache[n];
        int ret = oo;
        for(int i=n; i<N; i++) {
            if(dp[n][i]) ret = min(ret, solve(i+1)+1);
        }
        return cache[n] = ret;
    }
    
    public static int min(int a, int b) {
        return a>b?b:a;
    }
}