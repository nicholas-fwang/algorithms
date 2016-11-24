import java.util.*;

class Main {
    public static final int MOD = 10000000;
    public static int N;
    public static int [][] cache;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testCase = sc.nextInt();
        for(int tc=0; tc<testCase; tc++) {
            N = sc.nextInt();
            cache = new int[N+1][N+1];
            for(int i=0; i<=N; i++) Arrays.fill(cache[i], -1);
            int ret = 0;
            for(int i=1; i<=N; i++) {
                ret += solve(i,i);
                ret = ret%MOD;
            }
            System.out.println(ret);
        }
    }
    
    public static int solve(int n, int first) {
        if(n == N) return 1;
        
        if(cache[n][first] != -1) return cache[n][first];
        cache[n][first] = 0;
        
        for(int i=1; i<=N-n; i++) {
            cache[n][first] += ((first+i-1)*solve(n+i, i))%MOD;
            cache[n][first] = cache[n][first]%MOD;
        }
        return cache[n][first];
    }
}