import java.util.*;

class Main {
    static final int oo = 0x3f3f3f3f;
    static int [][] map;
    static int [][][] cache;
    static int n,m;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        map = new int[n][m];
        cache = new int[n][m][2];
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                Arrays.fill(cache[i][j], -1);
                map[i][j] = sc.nextInt();
            }
        }
        
        System.out.println(max(solve(0,0,0), solve(0,0,1)));
    }
    
    public static int solve(int row, int col, int d) {
        if(row == n-1 && col == m-1) return map[row][col];
        
        if(cache[row][col][d] != -1) return cache[row][col][d];
        cache[row][col][d] = -oo;
        
        if(d == 0 && col-1 >= 0) {
            cache[row][col][d] = max(cache[row][col][d], solve(row,col-1,d)+map[row][col]);
        } else if(d == 1 && col+1 < m) {
            cache[row][col][d] = max(cache[row][col][d], solve(row,col+1,d)+map[row][col]);
        }
        
        if(row+1 < n) {
            cache[row][col][d] = max(cache[row][col][d], solve(row+1,col,0)+map[row][col]);
            cache[row][col][d] = max(cache[row][col][d], solve(row+1,col,1)+map[row][col]);
        }
        return cache[row][col][d];
    }
    
    public static int max(int a, int b) {
        return a>b? a : b;
    }
}