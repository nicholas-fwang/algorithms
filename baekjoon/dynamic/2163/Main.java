import java.util.*;

class Main {
    public static final int oo = 0x3f3f3f3f;
    public static int N,M;
    public static int cache[][];
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        cache = new int[N+1][M+1];
        for(int i=0; i<=N; i++) Arrays.fill(cache[i], -1);
        System.out.println(solve(N,M));
    }
    
    public static int solve(int n, int m) {
        if(n==1 && m==1) return 0;
        
        if(cache[n][m] != -1) return cache[n][m];
        cache[n][m] = oo;
        
        for(int i=1; i<n; i++) {
            cache[n][m] = min(cache[n][m], solve(i,m)+solve(n-i,m)+1);
        }
        
        for(int i=1; i<m; i++) {
            cache[n][m] = min(cache[n][m], solve(n,i)+solve(n,m-i)+1);
        }
        return cache[n][m];
    }
    
    public static int min(int a, int b) {
        return a>b?b:a;
    }
}