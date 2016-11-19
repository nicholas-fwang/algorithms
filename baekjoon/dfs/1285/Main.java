import java.util.*;

class Main {
    public static final int oo = 0x3f3f3f3f;
    public static int N;
    public static int [][] map;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        sc.nextLine();
        
        map = new int[N][N];
        for(int i=0; i<N; i++) Arrays.fill(map[i], 0);
        
        for(int i=0; i<N; i++) {
            String s = sc.nextLine();
            for(int j=0; j<s.length(); j++) {
                if(s.charAt(j) == 'T') map[i][j] = 1;
            }
        }
        
        System.out.println(solve(0));
    }
    
    public static int solve(int n) {
        if(n == N) {
            int ret = 0;
            for(int i=0; i<N; i++) {
                int t=0;;
                for(int j=0; j<N; j++) {
                    if(map[j][i] == 1) t++;
                }
                if(t > N-t) t = N-t;
                ret += t;
            }
            return ret;
        }
        
        int ret = oo;
        ret = min(ret, solve(n+1));
        rev(n);
        ret = min(ret, solve(n+1));
        rev(n);
        return ret;
        
    }
    
    public static void rev(int n) {
        for(int i=0; i<N; i++) {
            map[n][i] = 1-map[n][i];
        }
    }
    
    public static int min(int a, int b) {
        return a>b? b:a;
    }
}