import java.util.*;

class Main {
    static int[][] cache;
    static int[] map;
    static int N;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testCase = sc.nextInt();
        for(int tc = 0; tc < testCase; tc++) {
            N = sc.nextInt();
            cache = new int[N+1][N+1];
            map = new int[N+1];
            for(int i=0; i<=N; i++) {
                Arrays.fill(cache[i], -1);
            }
            for(int i=1; i<=N; i++) {
                map[i] = sc.nextInt();
            }
            System.out.println(solve(1,0));
        }
    }
    
    public static int solve(int n, int l) {
        if(n == N+1) return 0;
        
        if(cache[n][l] != -1) return cache[n][l];
        cache[n][l] = 0;
        
        if(map[n] > map[l]) 
            cache[n][l] = max(cache[n][l], solve(n+1,n)+1);
        
        return cache[n][l] = max(cache[n][l], solve(n+1,l));
    }
    
    public static int max(int a, int b) {
        return a>b?a:b;
    }
}