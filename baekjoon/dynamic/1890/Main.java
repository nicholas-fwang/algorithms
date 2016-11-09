import java.util.*;

class Main {
    
    static int[][] board;
    static int n;
    static long[][] cache;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        board = new int[n][n];
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                board[i][j] = sc.nextInt();
            }
        }
        cache = new long[n][n];
        for(int i=0; i<n; i++) {
            Arrays.fill(cache[i], -1);
        }
        
        System.out.println(solve(0,0));
    }
    
    public static long solve(int row, int col) {
        if(row == n-1 && col == n-1) {
            return 1;
        } else if(row >= n || col >= n) {
            return 0;
        }
        
        if(cache[row][col] != -1) return cache[row][col];
        cache[row][col] = 0;
        
        cache[row][col] += solve(row+board[row][col],col);
        cache[row][col] += solve(row,col+board[row][col]);
        return cache[row][col];
    }
}