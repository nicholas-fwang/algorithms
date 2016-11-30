import java.util.*;

class Main {
    public static final int MOD = 1000000007;
    public static long cache[][][];
    public static int N,L,R;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        L = sc.nextInt();
        R = sc.nextInt();
        
        cache = new long[101][101][101];
        for(int i=0; i<=100; i++) {
            for(int j=0; j<=100; j++) Arrays.fill(cache[i][j], -1);
        }
        System.out.println(solve(N-1,1,1));
    }
    
    public static long solve(int n, int l , int r) {
        if(n == 0) {
            if(l == L && r == R) return 1;
            return 0;
        }
        
        if(cache[n][l][r] != -1) return cache[n][l][r];
        
        cache[n][l][r] = solve(n-1,l+1,r)%MOD;
        cache[n][l][r] += solve(n-1,l,r+1)%MOD;
        cache[n][l][r] += (N-1-n)*solve(n-1,l,r)%MOD;
        return cache[n][l][r] %= MOD;
    }
}