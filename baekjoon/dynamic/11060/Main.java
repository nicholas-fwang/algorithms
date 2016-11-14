import java.util.*;

class Main {
    static final int oo = 0x3f3f3f3f;
    static int cache[];
    static int N;
    static int map[];
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        map = new int[N];
        for(int i=0; i<N; i++) {
            map[i] = sc.nextInt();
        }
        cache = new int[N];
        Arrays.fill(cache, -1);
        
        int ret = solve(0);
        if(ret >= oo) ret = -1;
        System.out.println(ret);
    }
    
    public static int solve(int n) {
        if(n == N-1) return 0;
        else if(n > N-1) return oo;
        
        if(cache[n] != -1) return cache[n];
        cache[n] = oo;
        
        for(int i=1; i<=map[n]; i++) {
            cache[n] = min(cache[n], solve(n+i)+1);
        }
        return cache[n];
    }
    
    public static int min(int a, int b) {
        return a>b ? b : a;
    }
}