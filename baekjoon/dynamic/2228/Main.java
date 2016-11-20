import java.util.*;

class Main {
    public static final int oo = 0x3f3f3f3f;
    public static int N, M;
    public static int[] map;
    public static int[][][] cache;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        map = new int[N];
        cache = new int[N+1][M+1][2];
        for(int i=0; i<=N; i++) {
            for(int j=0; j<=M; j++) Arrays.fill(cache[i][j], -1);
        }
        for(int i=0; i<N; i++) {
            map[i] = sc.nextInt();
        }
        System.out.println(max(solve(1,0,0),solve(1,1,1)+map[0]));
    }
    
    public static int solve(int n, int m, int selected) {
        if(n == N) {
            if(m == M) return 0;
            else return -oo;
        }
        if(m > M) return -oo;
        
        if(cache[n][m][selected] != -1) return cache[n][m][selected];
        cache[n][m][selected] = -oo;
        
        if(selected == 0) {
            cache[n][m][selected] = max(cache[n][m][selected], solve(n+1,m,0));
            cache[n][m][selected] = max(cache[n][m][selected], solve(n+1,m+1,1)+map[n]);
        } else {
            cache[n][m][selected] = max(cache[n][m][selected], solve(n+1,m,1)+map[n]);
            cache[n][m][selected] = max(cache[n][m][selected], solve(n+1,m,0));
        }
        return cache[n][m][selected];
    }
    
    public static int max(int a, int b) {
        return a>b? a:b;
    }
}