import java.util.*;

class Main {
    final static int oo = 0x3f3f3f3f;
    static int N, k;
    static int map[], psum[];
    static int cache[][];
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        map = new int[50000];
        psum = new int[50001];
        cache = new int[3][50000];
        for(int i=0; i<3; i++) Arrays.fill(cache[i], -1);
        
        N = sc.nextInt();
        for(int i=0; i<N; i++) map[i] = sc.nextInt();
        psum[0] = 0;
        for(int i=1; i<=N; i++) psum[i] = psum[i-1] + map[i-1];
        k = sc.nextInt();
        
        System.out.println(solve(0,0));
    }
    
    public static int solve(int n, int s) {
        if(n == 3) return 0;
        if(s >= N) return -oo;
        
        if(cache[n][s] != -1) return cache[n][s];
        cache[n][s] = 0;
        
        if(s+1 < N) cache[n][s] = max(cache[n][s], solve(n, s+1));
        if(s+k-1 < N) cache[n][s] = max(cache[n][s], solve(n+1, s+k)+psum[s+k]-psum[s]);
        
        return cache[n][s];
    }
    
    public static int max(int a, int b) {
        return a>b?a:b;
    }
}