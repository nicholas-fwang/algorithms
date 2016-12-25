import java.util.*;

class Main {
    static int N, len;
    static int cache[][][];
    static int map[];
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        int d1 = sc.nextInt();
        int d2 = sc.nextInt();
        len = sc.nextInt();
        cache = new int[21][21][21];
        for(int i=0; i<=20; i++) {
            for(int j=0; j<=20; j++) Arrays.fill(cache[i][j], -1);
        }
        map = new int[21];
        for(int i=1; i<=len; i++) map[i] = sc.nextInt();
        
        System.out.println(solve(1, d1, d2));
    }
    
    public static int solve(int n, int d1, int d2) {
        if(n == len+1) return 0;
        
        if(cache[n][d1][d2] != -1) return cache[n][d1][d2];
        
        return cache[n][d1][d2] = 
            min(solve(n+1, map[n], d2) + abs(d1-map[n]),
                  solve(n+1, d1, map[n]) + abs(d2-map[n]));
    }
    
    public static int abs(int a) {
        return a>=0 ? a:-a;
    }
    
    public static int min(int a, int b) {
        return a>b ? b:a;
    }
}