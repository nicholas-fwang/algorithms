import java.util.*;

class Main {
    public static int N;
    public static int cache[];
    public static int map[];
    
    public static void main(String[] args) {
        cache = new int[501];
        Arrays.fill(cache, -1);
        map = new int[501];
        Arrays.fill(map, 0);
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        for(int i=0; i<N; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            map[a] = b;
        }
        System.out.println(N-solve(0));
    }
    
    public static int solve(int n) {
        if(cache[n] != -1) return cache[n];
        cache[n] = 0;
        
        for(int i=n+1; i<=500; i++) {
            if(map[i] > map[n]) cache[n] = max(cache[n], solve(i)+1);
        }
        return cache[n];
    }
    
    public static int max(int a, int b) {
        return a>b?a:b;
    }
}