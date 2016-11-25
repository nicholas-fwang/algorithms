import java.util.*;

class Main {
    public static final int oo = 0x3f3f3f3f;
    public static int N,M;
    public static int [][] cache;
    public static int [] map;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        int s = sc.nextInt();
        M = sc.nextInt();
        cache = new int[N+1][M+1];
        for(int i=0; i<=N; i++) Arrays.fill(cache[i], -1);
        map = new int[N+1];
        for(int i=0; i<N; i++) {
            map[i] = sc.nextInt();
        }
        
        int ret = solve(0, s);
        if(ret < 0) ret = -1;
        System.out.println(ret);
    }
    
    public static int solve(int n, int c) {
        if(!inRange(c)) return -oo;
        if(n == N) return c;
        
        if(cache[n][c] != -1) return cache[n][c];
        cache[n][c] = -oo;
        
        cache[n][c] = max(cache[n][c], solve(n+1,c+map[n]));
        cache[n][c] = max(cache[n][c], solve(n+1,c-map[n]));
        return cache[n][c];
    }
    
    public static int max(int a, int b) {
        return a>b?a:b;
    }
    
    public static boolean inRange(int n) {
        return n>=0 && n<=M;
    }
}