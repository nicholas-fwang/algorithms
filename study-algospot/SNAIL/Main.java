import java.util.*;

class Main {
    public static int N,M;
    public static double [][]cache;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testCase = sc.nextInt();
        for(int tc=0; tc<testCase; tc++) {
            N = sc.nextInt();
            M = sc.nextInt();
            cache = new double[N][M];
            for(int i=0; i<N; i++) {
                for(int j=0; j<M; j++) cache[i][j] = -1;
            }
            System.out.printf("%.10f\n", solve(0,0));
        }
    }
    
    public static double solve(int n, int m) {
        if(n >= N) return 1;
        if(m == M) return n >= N ? 1 : 0;
        
        if(cache[n][m] != -1) return cache[n][m];
        
        return cache[n][m] = 0.75*solve(n+2, m+1) + 0.25*solve(n+1, m+1);
    }
}