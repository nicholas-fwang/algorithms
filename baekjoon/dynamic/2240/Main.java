import java.util.*;

class Main {
    
    static final int oo = 0x3f3f3f3f;
    static int [][][] cache;
    static int [] map;
    static int T,W;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();
        W = sc.nextInt();
        map = new int[T+1];
        cache = new int[2][W+1][T+1];
        for(int i=0; i<2; i++) {
            for(int j=0; j<W+1; j++) {
                Arrays.fill(cache[i][j], -1);
            }
        }
        for(int i=0; i<T; i++) {
            map[i] = sc.nextInt()-1;
        }
        System.out.println(max(solve(0,0,0),solve(1,0,0)));
    }
    
    public static int solve(int n, int w, int t) {
        if(w > W) return -oo;
        if(t == T) return 0;
        
        if(cache[n][w][t] != -1) return cache[n][w][t];
        cache[n][w][t] = 0;
        int tmp = 0;
        if(map[t] == n) tmp++;
        cache[n][w][t] = max(cache[n][w][t], solve(1-n, w+1, t+1)+tmp);
        cache[n][w][t] = max(cache[n][w][t], solve(n, w, t+1)+tmp);
        return cache[n][w][t];
    }
    
    public static int max(int a, int b) {
        return a>b?a:b;
    }
}