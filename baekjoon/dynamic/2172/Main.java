import java.util.*;

class Main {
    public static final int dx[] = {1,1,0,-1,-1,-1,0,1};
    public static final int dy[] = {0,1,1,1,0,-1,-1,-1};
    
    public static int N,L;
    public static int [][][][][] cache;
    public static boolean [][][][][] memo;
    public static int [][] map;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        L = sc.nextInt();
        cache = new int[N+1][N+1][N+1][N+1][L+1];
        memo = new boolean[N+1][N+1][N+1][N+1][L+1];
        map = new int[N+1][N+1];
        
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                map[i][j] = sc.nextInt();
            }
        }
        
        int ret = 0;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(L%2 == 1) {
                    ret += solve(i,j,i,j,1);
                } else {
                    for(int k=0; k<8; k++) {
                        int nexti = i+dy[k];
                        int nextj = j+dx[k];
                        if(inRange(nexti, nextj) && map[i][j]== map[nexti][nextj]) {
                            ret += solve(i,j,nexti,nextj,2);
                        }
                    }
                }         
            }
        }
        System.out.println(ret);
    }
    
    public static int solve(int r1, int c1, int r2, int c2, int l) {
        if(l == L) return 1;
        
        if(memo[r1][c1][r2][c2][l]) return cache[r1][c1][r2][c2][l];
        
        int ret = 0;
        memo[r1][c1][r2][c2][l] = true;
        for(int i=0; i<8; i++) {
            for(int j=0; j<8; j++) {
                int nextR1 = r1+dy[i];
                int nextC1 = c1+dx[i];
                int nextR2 = r2+dy[j];
                int nextC2 = c2+dx[j];   
                if(inRange(nextR1,nextC1) && inRange(nextR2,nextC2) && map[nextR1][nextC1] == map[nextR2][nextC2]) {
                    ret += solve(nextR1,nextC1,nextR2,nextC2,l+2);
                }
            }
        }
        return cache[r1][c1][r2][c2][l] = ret;
    }
    
    public static boolean inRange(int row, int col) {
        return row >= 0 && row < N && col >= 0 && col < N;
    }
}