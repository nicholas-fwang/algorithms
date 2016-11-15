import java.util.*;

class Main {
    
    static int[][] cache;
    static int[][] map;
    static int N;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testCase = sc.nextInt();
        for(int tc=0; tc<testCase; tc++) {
            N = sc.nextInt();
            cache = new int[N+1][N+1];
            map = new int[N+1][N+1];
            for(int i=0; i<=N; i++) {
                Arrays.fill(cache[i], -1);
            }
            for(int i=1; i<=N; i++) {
                for(int j=1; j<=i; j++) {
                    map[i][j] = sc.nextInt();
                }
            }
            System.out.println(solve(1,1));
        }
    }
    
    public static int solve(int row, int col) {
        if(row == N+1) return 0;
        
        if(cache[row][col] != -1) return cache[row][col];
        cache[row][col] = 0;
        
        cache[row][col] = max(cache[row][col], solve(row+1,col)+map[row][col]);
        cache[row][col] = max(cache[row][col], solve(row+1,col+1)+map[row][col]);
        
        return cache[row][col];
    }
    
    public static int max(int a, int b) {
        return a>b?a:b;
    }
}