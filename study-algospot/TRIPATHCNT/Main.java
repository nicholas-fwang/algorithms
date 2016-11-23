import java.util.*;

class Main {
    public static int N;
    public static int [][] map;
    public static int [][] cache;
    public static int [][] c;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testCase = sc.nextInt();
        for(int tc=0; tc<testCase; tc++) {
            N = sc.nextInt();
            map = new int[N+1][N+1];
            cache = new int[N+1][N+1];
            c = new int[N+1][N+1];
            for(int i=0; i<=N; i++) {
                Arrays.fill(cache[i], -1);
                Arrays.fill(c[i], -1);
            }
            for(int i=0; i<N; i++) {
                for(int j=0; j<=i; j++) {
                    map[i][j] = sc.nextInt();
                }
            }
            System.out.println(cnt(0,0));
        }
    }
    
    public static int solve(int row, int col) {
        if(row == N) {
            return 0;
        }
        
        if(cache[row][col] != -1) return cache[row][col];
        cache[row][col] = 0;
        
        cache[row][col] = max(cache[row][col], solve(row+1,col)+map[row][col]);
        cache[row][col] = max(cache[row][col], solve(row+1,col+1)+map[row][col]);
        return cache[row][col];
    }
    
    public static int max(int a, int b) {
        return a>b? a:b;
    }
    
    public static int cnt(int row, int col) {
        if(row == N-1) return 1;
        
        if(c[row][col] != -1) return c[row][col];
        c[row][col] = 0;
        
        if(solve(row+1,col) >= solve(row+1,col+1)) c[row][col] += cnt(row+1,col);
        if(solve(row+1,col) <= solve(row+1,col+1)) c[row][col] += cnt(row+1,col+1);
        return c[row][col];
    }
}