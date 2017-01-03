import java.util.*;

class Main {
    public static final double oo = 0x3f3f3f3f;
    public static int N,C;
    public static int[] map;
    public static double[][] cache;
    public static double[][] psum;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testCase = sc.nextInt();
        for(int tc=0; tc<testCase; tc++) {
            map = new int[201];
            cache = new double[201][201];
            psum = new double[201][201];
            for(int i=0; i<=200; i++) {
                Arrays.fill(cache[i], -1);
                Arrays.fill(psum[i], 0);
            }
            N = sc.nextInt();
            C = sc.nextInt();
            for(int i=0; i<N; i++) {
                map[i] = sc.nextInt();   
            }
            for(int i=0; i<N; i++) {
                for(int j=i+1; j<N; j++) {
                    for(int k=i+1; k<j; k++) {
                        psum[i][j] += cal(i,j,k);
                    }
                }
            }
            System.out.printf("%.4f\n", solve(0,1)/N);
        }
    }
    
    public static double cal(int i, int j, int k) {
        return fabs(map[i] + 1.0*(map[j]-map[i])*(k-i)/(j-i) - map[k]);
    }
    
    public static double solve(int n, int c) {
        if(n == N-1) return 0;
        if(c == C-1) return psum[n][N-1];
        
        if(cache[n][c] >= -0.5) return cache[n][c];
        cache[n][c] = oo;
        
        for(int i=n+1; i<N; i++) {
            cache[n][c] = min(cache[n][c], solve(i,c+1)+psum[n][i]);
        }
        return cache[n][c];
    }
    
    public static double min(double a, double b) {
        return a>b? b:a;
    }
    
    public static double fabs(double a) {
        return a>=0 ? a:-a;
    }
}