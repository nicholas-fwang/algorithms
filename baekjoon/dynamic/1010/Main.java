import java.util.*;

class Main {
    public static int N,K;
    public static int cache[][];
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testCase = sc.nextInt();
        for(int tc=0; tc<testCase; tc++) {
            K = sc.nextInt();
            N = sc.nextInt();
            cache = new int[N+1][K+1];
            for(int i=0; i<=N; i++) Arrays.fill(cache[i], -1);
            System.out.println(solve(N,K));
        }
    }
    
    public static int solve(int n, int k) {
        if(n==0 || n==k) {
            return 1;
        }
        
        if(cache[n][k] != -1) return cache[n][k];
        cache[n][k] = 0;
        
        if(n-1>=0) cache[n][k] += solve(n-1, k);
        if(n-1>=0 && k-1>=0) cache[n][k] += solve(n-1, k-1);
        return cache[n][k];
    }
}