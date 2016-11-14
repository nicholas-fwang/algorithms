import java.util.*;

class Main {
    static final int oo = 0x3f3f3f3f;
    static int[][] map;
    static int[][][] cache;
    static int N;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        
        map = new int[N][N];
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                map[i][j] = sc.nextInt();
            }
        }
        cache = new int[N][N][1<<N];
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                Arrays.fill(cache[i][j], -1);
            }
        }
        int ret = oo;
        for(int i=0; i<N; i++) {
            ret = min(ret, solve(i,i,0));
        }
        System.out.println(ret);
    }

    public static int solve(int start, int end, int l) {
        if(l == (1<<N)-1 && start == end) {
            return 0;
        } else if(l == (1<<N)-1 && start != end) {
            return oo;
        }
        
        if(cache[start][end][l] != -1) return cache[start][end][l];
        cache[start][end][l] = oo;
        
        for(int i=0; i<N; i++) {
            if(map[start][i] > 0 && ((l>>i)&1) == 0) {
                int tmp = l;
                cache[start][end][l] = min(cache[start][end][l], solve(i,end,tmp + (1<<i))+map[start][i]);
            }
        }
        return cache[start][end][l];
    }
    
    public static int min(int a, int b) {
        return a>b ? b:a;
    }
}